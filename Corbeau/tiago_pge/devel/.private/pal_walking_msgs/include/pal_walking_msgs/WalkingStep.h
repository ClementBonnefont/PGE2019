// Generated by gencpp from file pal_walking_msgs/WalkingStep.msg
// DO NOT EDIT!


#ifndef PAL_WALKING_MSGS_MESSAGE_WALKINGSTEP_H
#define PAL_WALKING_MSGS_MESSAGE_WALKINGSTEP_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <humanoid_nav_msgs/StepTarget.h>
#include <std_msgs/Duration.h>

namespace pal_walking_msgs
{
template <class ContainerAllocator>
struct WalkingStep_
{
  typedef WalkingStep_<ContainerAllocator> Type;

  WalkingStep_()
    : header()
    , step_target()
    , step_duration()
    , step_list_size(0)  {
    }
  WalkingStep_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , step_target(_alloc)
    , step_duration(_alloc)
    , step_list_size(0)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef  ::humanoid_nav_msgs::StepTarget_<ContainerAllocator>  _step_target_type;
  _step_target_type step_target;

   typedef  ::std_msgs::Duration_<ContainerAllocator>  _step_duration_type;
  _step_duration_type step_duration;

   typedef int32_t _step_list_size_type;
  _step_list_size_type step_list_size;





  typedef boost::shared_ptr< ::pal_walking_msgs::WalkingStep_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::pal_walking_msgs::WalkingStep_<ContainerAllocator> const> ConstPtr;

}; // struct WalkingStep_

typedef ::pal_walking_msgs::WalkingStep_<std::allocator<void> > WalkingStep;

typedef boost::shared_ptr< ::pal_walking_msgs::WalkingStep > WalkingStepPtr;
typedef boost::shared_ptr< ::pal_walking_msgs::WalkingStep const> WalkingStepConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::pal_walking_msgs::WalkingStep_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::pal_walking_msgs::WalkingStep_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace pal_walking_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'pal_walking_msgs': ['/home/pge/tiago_pge/src/pal_msgs/pal_walking_msgs/msg'], 'humanoid_nav_msgs': ['/opt/ros/kinetic/share/humanoid_nav_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::pal_walking_msgs::WalkingStep_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::pal_walking_msgs::WalkingStep_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::pal_walking_msgs::WalkingStep_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::pal_walking_msgs::WalkingStep_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::pal_walking_msgs::WalkingStep_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::pal_walking_msgs::WalkingStep_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::pal_walking_msgs::WalkingStep_<ContainerAllocator> >
{
  static const char* value()
  {
    return "71c9b6abe3794dbf1d1e8705aadecb82";
  }

  static const char* value(const ::pal_walking_msgs::WalkingStep_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x71c9b6abe3794dbfULL;
  static const uint64_t static_value2 = 0x1d1e8705aadecb82ULL;
};

template<class ContainerAllocator>
struct DataType< ::pal_walking_msgs::WalkingStep_<ContainerAllocator> >
{
  static const char* value()
  {
    return "pal_walking_msgs/WalkingStep";
  }

  static const char* value(const ::pal_walking_msgs::WalkingStep_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::pal_walking_msgs::WalkingStep_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Data about walking step being executed\n\
\n\
Header header\n\
\n\
humanoid_nav_msgs/StepTarget step_target\n\
\n\
std_msgs/Duration           step_duration\n\
\n\
int32  step_list_size\n\
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
MSG: humanoid_nav_msgs/StepTarget\n\
# Target for a single stepping motion of a humanoid's leg\n\
\n\
geometry_msgs/Pose2D pose   # step pose as relative offset to last leg\n\
uint8 leg                   # which leg to use (left/right, see below)\n\
\n\
uint8 right=0               # right leg constant\n\
uint8 left=1                # left leg constant\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Pose2D\n\
# Deprecated\n\
# Please use the full 3D pose.\n\
\n\
# In general our recommendation is to use a full 3D representation of everything and for 2D specific applications make the appropriate projections into the plane for their calculations but optimally will preserve the 3D information during processing.\n\
\n\
# If we have parallel copies of 2D datatypes every UI and other pipeline will end up needing to have dual interfaces to plot everything. And you will end up with not being able to use 3D tools for 2D use cases even if they're completely valid, as you'd have to reimplement it with different inputs and outputs. It's not particularly hard to plot the 2D pose or compute the yaw error for the Pose message and there are already tools and libraries that can do this for you.\n\
\n\
\n\
# This expresses a position and orientation on a 2D manifold.\n\
\n\
float64 x\n\
float64 y\n\
float64 theta\n\
\n\
================================================================================\n\
MSG: std_msgs/Duration\n\
duration data\n\
";
  }

  static const char* value(const ::pal_walking_msgs::WalkingStep_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::pal_walking_msgs::WalkingStep_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.step_target);
      stream.next(m.step_duration);
      stream.next(m.step_list_size);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct WalkingStep_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::pal_walking_msgs::WalkingStep_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::pal_walking_msgs::WalkingStep_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "step_target: ";
    s << std::endl;
    Printer< ::humanoid_nav_msgs::StepTarget_<ContainerAllocator> >::stream(s, indent + "  ", v.step_target);
    s << indent << "step_duration: ";
    s << std::endl;
    Printer< ::std_msgs::Duration_<ContainerAllocator> >::stream(s, indent + "  ", v.step_duration);
    s << indent << "step_list_size: ";
    Printer<int32_t>::stream(s, indent + "  ", v.step_list_size);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PAL_WALKING_MSGS_MESSAGE_WALKINGSTEP_H
