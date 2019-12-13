// Generated by gencpp from file pal_navigation_msgs/VisualLocRecognizeResponse.msg
// DO NOT EDIT!


#ifndef PAL_NAVIGATION_MSGS_MESSAGE_VISUALLOCRECOGNIZERESPONSE_H
#define PAL_NAVIGATION_MSGS_MESSAGE_VISUALLOCRECOGNIZERESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <geometry_msgs/PoseWithCovarianceStamped.h>

namespace pal_navigation_msgs
{
template <class ContainerAllocator>
struct VisualLocRecognizeResponse_
{
  typedef VisualLocRecognizeResponse_<ContainerAllocator> Type;

  VisualLocRecognizeResponse_()
    : success(false)
    , confidence(0.0)
    , estimatedPose()  {
    }
  VisualLocRecognizeResponse_(const ContainerAllocator& _alloc)
    : success(false)
    , confidence(0.0)
    , estimatedPose(_alloc)  {
  (void)_alloc;
    }



   typedef uint8_t _success_type;
  _success_type success;

   typedef double _confidence_type;
  _confidence_type confidence;

   typedef  ::geometry_msgs::PoseWithCovarianceStamped_<ContainerAllocator>  _estimatedPose_type;
  _estimatedPose_type estimatedPose;





  typedef boost::shared_ptr< ::pal_navigation_msgs::VisualLocRecognizeResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::pal_navigation_msgs::VisualLocRecognizeResponse_<ContainerAllocator> const> ConstPtr;

}; // struct VisualLocRecognizeResponse_

typedef ::pal_navigation_msgs::VisualLocRecognizeResponse_<std::allocator<void> > VisualLocRecognizeResponse;

typedef boost::shared_ptr< ::pal_navigation_msgs::VisualLocRecognizeResponse > VisualLocRecognizeResponsePtr;
typedef boost::shared_ptr< ::pal_navigation_msgs::VisualLocRecognizeResponse const> VisualLocRecognizeResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::pal_navigation_msgs::VisualLocRecognizeResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::pal_navigation_msgs::VisualLocRecognizeResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace pal_navigation_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'nav_msgs': ['/opt/ros/kinetic/share/nav_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'sensor_msgs': ['/opt/ros/kinetic/share/sensor_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'pal_navigation_msgs': ['/home/pge/tiago_pge/devel/.private/pal_navigation_msgs/share/pal_navigation_msgs/msg', '/home/pge/tiago_pge/src/pal_msgs/pal_navigation_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::pal_navigation_msgs::VisualLocRecognizeResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::pal_navigation_msgs::VisualLocRecognizeResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::pal_navigation_msgs::VisualLocRecognizeResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::pal_navigation_msgs::VisualLocRecognizeResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::pal_navigation_msgs::VisualLocRecognizeResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::pal_navigation_msgs::VisualLocRecognizeResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::pal_navigation_msgs::VisualLocRecognizeResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "af944bb003989194ffe33120c472f3ed";
  }

  static const char* value(const ::pal_navigation_msgs::VisualLocRecognizeResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xaf944bb003989194ULL;
  static const uint64_t static_value2 = 0xffe33120c472f3edULL;
};

template<class ContainerAllocator>
struct DataType< ::pal_navigation_msgs::VisualLocRecognizeResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "pal_navigation_msgs/VisualLocRecognizeResponse";
  }

  static const char* value(const ::pal_navigation_msgs::VisualLocRecognizeResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::pal_navigation_msgs::VisualLocRecognizeResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool success\n\
float64 confidence\n\
geometry_msgs/PoseWithCovarianceStamped estimatedPose\n\
\n\
\n\
\n\
\n\
\n\
================================================================================\n\
MSG: geometry_msgs/PoseWithCovarianceStamped\n\
# This expresses an estimated pose with a reference coordinate frame and timestamp\n\
\n\
Header header\n\
PoseWithCovariance pose\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
================================================================================\n\
MSG: geometry_msgs/PoseWithCovariance\n\
# This represents a pose in free space with uncertainty.\n\
\n\
Pose pose\n\
\n\
# Row-major representation of the 6x6 covariance matrix\n\
# The orientation parameters use a fixed-axis representation.\n\
# In order, the parameters are:\n\
# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)\n\
float64[36] covariance\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Pose\n\
# A representation of pose in free space, composed of position and orientation. \n\
Point position\n\
Quaternion orientation\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Point\n\
# This contains the position of a point in free space\n\
float64 x\n\
float64 y\n\
float64 z\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Quaternion\n\
# This represents an orientation in free space in quaternion form.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
float64 w\n\
";
  }

  static const char* value(const ::pal_navigation_msgs::VisualLocRecognizeResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::pal_navigation_msgs::VisualLocRecognizeResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.success);
      stream.next(m.confidence);
      stream.next(m.estimatedPose);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct VisualLocRecognizeResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::pal_navigation_msgs::VisualLocRecognizeResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::pal_navigation_msgs::VisualLocRecognizeResponse_<ContainerAllocator>& v)
  {
    s << indent << "success: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.success);
    s << indent << "confidence: ";
    Printer<double>::stream(s, indent + "  ", v.confidence);
    s << indent << "estimatedPose: ";
    s << std::endl;
    Printer< ::geometry_msgs::PoseWithCovarianceStamped_<ContainerAllocator> >::stream(s, indent + "  ", v.estimatedPose);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PAL_NAVIGATION_MSGS_MESSAGE_VISUALLOCRECOGNIZERESPONSE_H
