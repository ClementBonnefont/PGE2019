// Generated by gencpp from file pal_navigation_msgs/ChangeBuildingRequest.msg
// DO NOT EDIT!


#ifndef PAL_NAVIGATION_MSGS_MESSAGE_CHANGEBUILDINGREQUEST_H
#define PAL_NAVIGATION_MSGS_MESSAGE_CHANGEBUILDINGREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace pal_navigation_msgs
{
template <class ContainerAllocator>
struct ChangeBuildingRequest_
{
  typedef ChangeBuildingRequest_<ContainerAllocator> Type;

  ChangeBuildingRequest_()
    : building_name()
    , floor_name()  {
    }
  ChangeBuildingRequest_(const ContainerAllocator& _alloc)
    : building_name(_alloc)
    , floor_name(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _building_name_type;
  _building_name_type building_name;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _floor_name_type;
  _floor_name_type floor_name;





  typedef boost::shared_ptr< ::pal_navigation_msgs::ChangeBuildingRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::pal_navigation_msgs::ChangeBuildingRequest_<ContainerAllocator> const> ConstPtr;

}; // struct ChangeBuildingRequest_

typedef ::pal_navigation_msgs::ChangeBuildingRequest_<std::allocator<void> > ChangeBuildingRequest;

typedef boost::shared_ptr< ::pal_navigation_msgs::ChangeBuildingRequest > ChangeBuildingRequestPtr;
typedef boost::shared_ptr< ::pal_navigation_msgs::ChangeBuildingRequest const> ChangeBuildingRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::pal_navigation_msgs::ChangeBuildingRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::pal_navigation_msgs::ChangeBuildingRequest_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::pal_navigation_msgs::ChangeBuildingRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::pal_navigation_msgs::ChangeBuildingRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::pal_navigation_msgs::ChangeBuildingRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::pal_navigation_msgs::ChangeBuildingRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::pal_navigation_msgs::ChangeBuildingRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::pal_navigation_msgs::ChangeBuildingRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::pal_navigation_msgs::ChangeBuildingRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "9cd21d3150f8ada4b997571625fab346";
  }

  static const char* value(const ::pal_navigation_msgs::ChangeBuildingRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x9cd21d3150f8ada4ULL;
  static const uint64_t static_value2 = 0xb997571625fab346ULL;
};

template<class ContainerAllocator>
struct DataType< ::pal_navigation_msgs::ChangeBuildingRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "pal_navigation_msgs/ChangeBuildingRequest";
  }

  static const char* value(const ::pal_navigation_msgs::ChangeBuildingRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::pal_navigation_msgs::ChangeBuildingRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
string building_name\n\
string floor_name\n\
";
  }

  static const char* value(const ::pal_navigation_msgs::ChangeBuildingRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::pal_navigation_msgs::ChangeBuildingRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.building_name);
      stream.next(m.floor_name);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ChangeBuildingRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::pal_navigation_msgs::ChangeBuildingRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::pal_navigation_msgs::ChangeBuildingRequest_<ContainerAllocator>& v)
  {
    s << indent << "building_name: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.building_name);
    s << indent << "floor_name: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.floor_name);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PAL_NAVIGATION_MSGS_MESSAGE_CHANGEBUILDINGREQUEST_H
