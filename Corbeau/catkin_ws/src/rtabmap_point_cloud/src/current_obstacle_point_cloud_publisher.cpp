#include <ros/ros.h>

#include <pcl_conversions/pcl_conversions.h>
#include <pcl_ros/point_cloud.h>
#include <pcl/point_types.h>

#include "rtabmap_ros/Info.h"
#include "rtabmap_ros/MapData.h"
#include <rtabmap_ros/MsgConversion.h>
#include <rtabmap_ros/GetMap.h>

#include <rtabmap/core/Transform.h>
#include <rtabmap/core/util3d_transforms.h>
#include <rtabmap/core/util3d_filtering.h>
#include <rtabmap/core/util3d.h>

int cloud_decimation_ = 4;
float cloud_max_depth_ = 15;
float cloud_min_depth_ = 2;
float cloud_voxel_size_ = 0.15;

sensor_msgs::PointCloud2::Ptr cloud_map(new sensor_msgs::PointCloud2);

void point_cloud_construction(const rtabmap_ros::MapData& map)
{
	for(unsigned int i=0; i<map.nodes.size() && i<map.nodes.size(); ++i)
	{
		int id = map.nodes[i].id;

		rtabmap::Signature s = rtabmap_ros::nodeDataFromROS(map.nodes[i]);
		if(!s.sensorData().imageCompressed().empty() && //There is an image
		   !s.sensorData().depthOrRightCompressed().empty() && //Depth is available
		   (s.sensorData().cameraModels().size() || s.sensorData().stereoCameraModel().isValidForProjection())) //Construction is possible
		{
			cv::Mat image, depth;
			rtabmap::LaserScan scan;

			s.sensorData().uncompressData(&image, &depth, &scan);

			if(!s.sensorData().imageRaw().empty() && !s.sensorData().depthOrRightRaw().empty()) //Raw data available
			{
				pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud;
				pcl::IndicesPtr validIndices(new std::vector<int>);

				//Construction of point cloud from camera
				cloud = rtabmap::util3d::cloudRGBFromSensorData(s.sensorData(),
																cloud_decimation_,
																cloud_max_depth_,
																cloud_min_depth_,
																validIndices.get());
				if (cloud_voxel_size_)
				{
					cloud = rtabmap::util3d::voxelize(cloud, validIndices, cloud_voxel_size_);
				}

				//Construction of point cloud from laser
				if (!scan.isEmpty())
				{
					scan = rtabmap::util3d::commonFiltering(scan, 1, cloud_min_depth_, cloud_max_depth_, cloud_voxel_size_);

					pcl::PointCloud<pcl::PointXYZRGB>::Ptr scan_cloud;
					scan_cloud = rtabmap::util3d::laserScanToPointCloudRGB(scan, scan.localTransform());

					*cloud += *scan_cloud;
				}

				if(cloud->size())
				{
					//*cloud += *cloud;
					pcl::toROSMsg(*cloud, *cloud_map);
					cloud_map->header = map.header;
					cloud_map->header.frame_id = "base_link";
				}

			}
		}
	}
}

int main(int argc, char** argv)
{
	ros::init (argc, argv, "current_obstacle_point_cloud_publisher");

	if(argc < 3) {ROS_ERROR("need arg1: mapData input, arg2: pointCloud output"); return -1;};
	std::string map_data_name = argv[1];
	std::string point_cloud_name = argv[2];

	ros::NodeHandle node;
	ros::Subscriber sub = node.subscribe(map_data_name, 10, &point_cloud_construction);

	ros::Publisher  pub = node.advertise<sensor_msgs::PointCloud2>(point_cloud_name, 1);

	while(ros::ok())
	{
		pub.publish(cloud_map);

		ros::spinOnce();
	}
	
	return 0;
}