// Generated by gencpp from file gazebo_msgs/GetWorldPropertiesRequest.msg
// DO NOT EDIT!


#ifndef GAZEBO_MSGS_MESSAGE_GETWORLDPROPERTIESREQUEST_H
#define GAZEBO_MSGS_MESSAGE_GETWORLDPROPERTIESREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace gazebo_msgs
{
template <class ContainerAllocator>
struct GetWorldPropertiesRequest_
{
  typedef GetWorldPropertiesRequest_<ContainerAllocator> Type;

  GetWorldPropertiesRequest_()
    {
    }
  GetWorldPropertiesRequest_(const ContainerAllocator& _alloc)
    {
  (void)_alloc;
    }







  typedef boost::shared_ptr< ::gazebo_msgs::GetWorldPropertiesRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::gazebo_msgs::GetWorldPropertiesRequest_<ContainerAllocator> const> ConstPtr;

}; // struct GetWorldPropertiesRequest_

typedef ::gazebo_msgs::GetWorldPropertiesRequest_<std::allocator<void> > GetWorldPropertiesRequest;

typedef boost::shared_ptr< ::gazebo_msgs::GetWorldPropertiesRequest > GetWorldPropertiesRequestPtr;
typedef boost::shared_ptr< ::gazebo_msgs::GetWorldPropertiesRequest const> GetWorldPropertiesRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::gazebo_msgs::GetWorldPropertiesRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::gazebo_msgs::GetWorldPropertiesRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace gazebo_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'sensor_msgs': ['/opt/ros/kinetic/share/sensor_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'trajectory_msgs': ['/opt/ros/kinetic/share/trajectory_msgs/cmake/../msg'], 'gazebo_msgs': ['/home/pge/tiago_pge/src/gazebo_ros_pkgs/gazebo_msgs/msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::gazebo_msgs::GetWorldPropertiesRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::gazebo_msgs::GetWorldPropertiesRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::gazebo_msgs::GetWorldPropertiesRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::gazebo_msgs::GetWorldPropertiesRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::gazebo_msgs::GetWorldPropertiesRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::gazebo_msgs::GetWorldPropertiesRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::gazebo_msgs::GetWorldPropertiesRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const ::gazebo_msgs::GetWorldPropertiesRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd41d8cd98f00b204ULL;
  static const uint64_t static_value2 = 0xe9800998ecf8427eULL;
};

template<class ContainerAllocator>
struct DataType< ::gazebo_msgs::GetWorldPropertiesRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "gazebo_msgs/GetWorldPropertiesRequest";
  }

  static const char* value(const ::gazebo_msgs::GetWorldPropertiesRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::gazebo_msgs::GetWorldPropertiesRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
";
  }

  static const char* value(const ::gazebo_msgs::GetWorldPropertiesRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::gazebo_msgs::GetWorldPropertiesRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream&, T)
    {}

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GetWorldPropertiesRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::gazebo_msgs::GetWorldPropertiesRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream&, const std::string&, const ::gazebo_msgs::GetWorldPropertiesRequest_<ContainerAllocator>&)
  {}
};

} // namespace message_operations
} // namespace ros

#endif // GAZEBO_MSGS_MESSAGE_GETWORLDPROPERTIESREQUEST_H
