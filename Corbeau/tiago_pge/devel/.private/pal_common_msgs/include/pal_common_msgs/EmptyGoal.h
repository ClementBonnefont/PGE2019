// Generated by gencpp from file pal_common_msgs/EmptyGoal.msg
// DO NOT EDIT!


#ifndef PAL_COMMON_MSGS_MESSAGE_EMPTYGOAL_H
#define PAL_COMMON_MSGS_MESSAGE_EMPTYGOAL_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace pal_common_msgs
{
template <class ContainerAllocator>
struct EmptyGoal_
{
  typedef EmptyGoal_<ContainerAllocator> Type;

  EmptyGoal_()
    {
    }
  EmptyGoal_(const ContainerAllocator& _alloc)
    {
  (void)_alloc;
    }







  typedef boost::shared_ptr< ::pal_common_msgs::EmptyGoal_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::pal_common_msgs::EmptyGoal_<ContainerAllocator> const> ConstPtr;

}; // struct EmptyGoal_

typedef ::pal_common_msgs::EmptyGoal_<std::allocator<void> > EmptyGoal;

typedef boost::shared_ptr< ::pal_common_msgs::EmptyGoal > EmptyGoalPtr;
typedef boost::shared_ptr< ::pal_common_msgs::EmptyGoal const> EmptyGoalConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::pal_common_msgs::EmptyGoal_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::pal_common_msgs::EmptyGoal_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace pal_common_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'pal_common_msgs': ['/home/pge/tiago_pge/devel/.private/pal_common_msgs/share/pal_common_msgs/msg', '/home/pge/tiago_pge/src/pal_msgs/pal_common_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::pal_common_msgs::EmptyGoal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::pal_common_msgs::EmptyGoal_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::pal_common_msgs::EmptyGoal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::pal_common_msgs::EmptyGoal_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::pal_common_msgs::EmptyGoal_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::pal_common_msgs::EmptyGoal_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::pal_common_msgs::EmptyGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const ::pal_common_msgs::EmptyGoal_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd41d8cd98f00b204ULL;
  static const uint64_t static_value2 = 0xe9800998ecf8427eULL;
};

template<class ContainerAllocator>
struct DataType< ::pal_common_msgs::EmptyGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "pal_common_msgs/EmptyGoal";
  }

  static const char* value(const ::pal_common_msgs::EmptyGoal_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::pal_common_msgs::EmptyGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
";
  }

  static const char* value(const ::pal_common_msgs::EmptyGoal_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::pal_common_msgs::EmptyGoal_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream&, T)
    {}

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct EmptyGoal_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::pal_common_msgs::EmptyGoal_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream&, const std::string&, const ::pal_common_msgs::EmptyGoal_<ContainerAllocator>&)
  {}
};

} // namespace message_operations
} // namespace ros

#endif // PAL_COMMON_MSGS_MESSAGE_EMPTYGOAL_H
