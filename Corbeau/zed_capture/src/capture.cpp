#include <iostream>
#include <signal.h>
#include <string>

#include <sl/Camera.hpp>
#include <sl/types.hpp>
#include <sl/defines.hpp>
#include <opencv2/opencv.hpp>

using namespace sl;

/**
* Code to generate color images and depth images from the ZED
* 
* Authors : 
* Bonnefont Clément
* Morland Alexandre
* 
* For the UPSSITECH PGE 2019-2020
**/

// TODO_TODAY : Check closing ZED after Ctrl + C

// Create a ZED camera object
Camera zed;

/**
* Conversion function between sl::Mat and cv::Mat
**/
cv::Mat slMat2cvMat(Mat& input) {
    // Mapping between MAT_TYPE and CV_TYPE
    int cv_type = -1;
    switch (input.getDataType()) {
        case MAT_TYPE::MAT_TYPE_32F_C1: cv_type = CV_32FC1; break;
        case MAT_TYPE::MAT_TYPE_32F_C2: cv_type = CV_32FC2; break;
        case MAT_TYPE::MAT_TYPE_32F_C3: cv_type = CV_32FC3; break;
        case MAT_TYPE::MAT_TYPE_32F_C4: cv_type = CV_32FC4; break;
        case MAT_TYPE::MAT_TYPE_8U_C1: cv_type = CV_8UC1; break;
        case MAT_TYPE::MAT_TYPE_8U_C2: cv_type = CV_8UC2; break;
        case MAT_TYPE::MAT_TYPE_8U_C3: cv_type = CV_8UC3; break;
        case MAT_TYPE::MAT_TYPE_8U_C4: cv_type = CV_8UC4; break;
        default: break;
    }

    // Since cv::Mat data requires a uchar* pointer, we get the uchar1 pointer from sl::Mat (getPtr<T>())
    // cv::Mat and sl::Mat will share a single memory structure
    return cv::Mat(input.getHeight(), input.getWidth(), cv_type, input.getPtr<sl::uchar1>(MEM::MEM_CPU));
}

void handler_ctrl_c(int s) {
	printf("Closing application\n");
	zed.close();
	
	exit(1);
}

int main(int argc, char **argv) {
	// Intercept the Ctrl C command
	struct sigaction sigIntHandler;
 	
	sigIntHandler.sa_handler = handler_ctrl_c;
   	sigemptyset(&sigIntHandler.sa_mask);
   	sigIntHandler.sa_flags = 0;
	
	sigaction(SIGINT, &sigIntHandler, NULL);
	
    // Set configuration parameters
	InitParameters init_params;
	init_params.camera_resolution = RESOLUTION_HD1080;
	init_params.depth_mode = DEPTH_MODE::DEPTH_MODE_ULTRA;
    init_params.coordinate_units = UNIT::UNIT_METER;
	//init_params.sensing_mode = SENSING_MODE::SENSING_MODE_FILL;
	init_params.camera_fps = 30;
 	
    // Open the camera
    ERROR_CODE err = zed.open(init_params);
    if (err != SUCCESS) {
		printf("Error in the camera");
		zed.close();
        exit(-1);
	}
 	
    // Get camera information (ZED serial number)
    int zed_serial = zed.getCameraInformation().serial_number;
    printf("Hello! This is my serial number: %d\n", zed_serial);
	
	sl::Mat zed_image_left;
	sl::Mat zed_image_right;
	sl::Mat zed_depth_map;
	sl::Mat zed_depth_measure;
	
	printf("Camera launched, press 'q' to stop execution\n");
	printf("Press 'c' to take a capture\n");
	
	// Counter for the images
	int counter = 1;
	
	char key = ' ';
	cv::Mat emptyMat(400, 300, CV_64F);
	cv::imshow("Image", emptyMat);
	while(key != 'q') {
		// A new image and depth is available if grab() returns SUCCESS
		if (zed.grab() == SUCCESS) {
			if(key == 'c') {
				printf("Capture done\n");
				// Retrieve left image
				zed.retrieveImage(zed_image_left, VIEW::VIEW_LEFT);
				
				// Retrieve right image
				zed.retrieveImage(zed_image_right, VIEW::VIEW_RIGHT);
				
				// Retrieve depth image
				zed.retrieveImage(zed_depth_map, VIEW::VIEW_DEPTH);
				
				// Retrieve depth image
				zed.retrieveMeasure(zed_depth_measure, MEASURE::MEASURE_DEPTH);
			
				// Convert sl::Mat to cv::Mat
				cv::Mat ocv_image_left = slMat2cvMat(zed_image_left);
				cv::Mat ocv_image_right = slMat2cvMat(zed_image_right);
				cv::Mat ocv_depth_map = slMat2cvMat(zed_depth_map);
				cv::Mat ocv_depth_measure = slMat2cvMat(zed_depth_measure);
				
				// Display to screen
				/*
				cv::imshow("Image", ocv_image_left);
				cv::imshow("Depth", ocv_depth_map);
				cv::waitKey(0);
				cv::destroyAllWindows();
				*/
				
				// Write images on disk
				imwrite("Images/Left/Image_left_" + std::to_string(counter) + ".png", ocv_image_left);
				imwrite("Images/Right/Image_right_" + std::to_string(counter) + ".png", ocv_image_right);
				imwrite("Images/Depth/Depth_map_" + std::to_string(counter) + ".png", ocv_depth_map);
				
				// Write depth measure on disk
				cv::FileStorage storage("DepthMeasure/Depth_measure_" + std::to_string(counter) + ".yml", cv::FileStorage::WRITE);
				storage << "ocv_depth_measure" << ocv_depth_measure;
				storage.release();

				printf("Images number %d saved on disk\n", counter);
				counter++;
			}
		
			// Handle key event
        	key = cv::waitKey(100);
		}
	}
	
    // Close the camera
    zed.close();
    return 0;
}

