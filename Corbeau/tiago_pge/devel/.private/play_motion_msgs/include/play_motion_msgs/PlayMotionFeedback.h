// Generated by gencpp from file play_motion_msgs/PlayMotionFeedback.msg
// DO NOT EDIT!


#ifndef PLAY_MOTION_MSGS_MESSAGE_PLAYMOTIONFEEDBACK_H
#define PLAY_MOTION_MSGS_MESSAGE_PLAYMOTIONFEEDBACK_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace play_motion_msgs
{
template <class ContainerAllocator>
struct PlayMotionFeedback_
{
  typedef PlayMotionFeedback_<ContainerAllocator> Type;

  PlayMotionFeedback_()
    {
    }
  PlayMotionFeedback_(const ContainerAllocator& _alloc)
    {
  (void)_alloc;
    }







  typedef boost::shared_ptr< ::play_motion_msgs::PlayMotionFeedback_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::play_motion_msgs::PlayMotionFeedback_<ContainerAllocator> const> ConstPtr;

}; // struct PlayMotionFeedback_

typedef ::play_motion_msgs::PlayMotionFeedback_<std::allocator<void> > PlayMotionFeedback;

typedef boost::shared_ptr< ::play_motion_msgs::PlayMotionFeedback > PlayMotionFeedbackPtr;
typedef boost::shared_ptr< ::play_motion_msgs::PlayMotionFeedback const> PlayMotionFeedbackConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::play_motion_msgs::PlayMotionFeedback_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::play_motion_msgs::PlayMotionFeedback_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace play_motion_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'play_motion_msgs': ['/home/pge/tiago_pge/src/play_motion/play_motion_msgs/msg', '/home/pge/tiago_pge/devel/.private/play_motion_msgs/share/play_motion_msgs/msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::play_motion_msgs::PlayMotionFeedback_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::play_motion_msgs::PlayMotionFeedback_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::play_motion_msgs::PlayMotionFeedback_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::play_motion_msgs::PlayMotionFeedback_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::play_motion_msgs::PlayMotionFeedback_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::play_motion_msgs::PlayMotionFeedback_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::play_motion_msgs::PlayMotionFeedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const ::play_motion_msgs::PlayMotionFeedback_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd41d8cd98f00b204ULL;
  static const uint64_t static_value2 = 0xe9800998ecf8427eULL;
};

template<class ContainerAllocator>
struct DataType< ::play_motion_msgs::PlayMotionFeedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "play_motion_msgs/PlayMotionFeedback";
  }

  static const char* value(const ::play_motion_msgs::PlayMotionFeedback_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::play_motion_msgs::PlayMotionFeedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
\n\
";
  }

  static const char* value(const ::play_motion_msgs::PlayMotionFeedback_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::play_motion_msgs::PlayMotionFeedback_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream&, T)
    {}

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct PlayMotionFeedback_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::play_motion_msgs::PlayMotionFeedback_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream&, const std::string&, const ::play_motion_msgs::PlayMotionFeedback_<ContainerAllocator>&)
  {}
};

} // namespace message_operations
} // namespace ros

#endif // PLAY_MOTION_MSGS_MESSAGE_PLAYMOTIONFEEDBACK_H
