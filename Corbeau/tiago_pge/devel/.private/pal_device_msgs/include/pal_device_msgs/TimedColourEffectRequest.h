// Generated by gencpp from file pal_device_msgs/TimedColourEffectRequest.msg
// DO NOT EDIT!


#ifndef PAL_DEVICE_MSGS_MESSAGE_TIMEDCOLOUREFFECTREQUEST_H
#define PAL_DEVICE_MSGS_MESSAGE_TIMEDCOLOUREFFECTREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <pal_device_msgs/LedGroup.h>
#include <std_msgs/ColorRGBA.h>

namespace pal_device_msgs
{
template <class ContainerAllocator>
struct TimedColourEffectRequest_
{
  typedef TimedColourEffectRequest_<ContainerAllocator> Type;

  TimedColourEffectRequest_()
    : leds()
    , color()
    , effectDuration()
    , priority(0)  {
    }
  TimedColourEffectRequest_(const ContainerAllocator& _alloc)
    : leds(_alloc)
    , color(_alloc)
    , effectDuration()
    , priority(0)  {
  (void)_alloc;
    }



   typedef  ::pal_device_msgs::LedGroup_<ContainerAllocator>  _leds_type;
  _leds_type leds;

   typedef  ::std_msgs::ColorRGBA_<ContainerAllocator>  _color_type;
  _color_type color;

   typedef ros::Duration _effectDuration_type;
  _effectDuration_type effectDuration;

   typedef uint8_t _priority_type;
  _priority_type priority;





  typedef boost::shared_ptr< ::pal_device_msgs::TimedColourEffectRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::pal_device_msgs::TimedColourEffectRequest_<ContainerAllocator> const> ConstPtr;

}; // struct TimedColourEffectRequest_

typedef ::pal_device_msgs::TimedColourEffectRequest_<std::allocator<void> > TimedColourEffectRequest;

typedef boost::shared_ptr< ::pal_device_msgs::TimedColourEffectRequest > TimedColourEffectRequestPtr;
typedef boost::shared_ptr< ::pal_device_msgs::TimedColourEffectRequest const> TimedColourEffectRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::pal_device_msgs::TimedColourEffectRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::pal_device_msgs::TimedColourEffectRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace pal_device_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'pal_device_msgs': ['/home/pge/tiago_pge/src/pal_msgs/pal_device_msgs/msg', '/home/pge/tiago_pge/devel/.private/pal_device_msgs/share/pal_device_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::pal_device_msgs::TimedColourEffectRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::pal_device_msgs::TimedColourEffectRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::pal_device_msgs::TimedColourEffectRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::pal_device_msgs::TimedColourEffectRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::pal_device_msgs::TimedColourEffectRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::pal_device_msgs::TimedColourEffectRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::pal_device_msgs::TimedColourEffectRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "a7f2577993c3ce4fd146dbd95f4a91d5";
  }

  static const char* value(const ::pal_device_msgs::TimedColourEffectRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xa7f2577993c3ce4fULL;
  static const uint64_t static_value2 = 0xd146dbd95f4a91d5ULL;
};

template<class ContainerAllocator>
struct DataType< ::pal_device_msgs::TimedColourEffectRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "pal_device_msgs/TimedColourEffectRequest";
  }

  static const char* value(const ::pal_device_msgs::TimedColourEffectRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::pal_device_msgs::TimedColourEffectRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
\n\
LedGroup leds\n\
\n\
\n\
std_msgs/ColorRGBA color\n\
\n\
\n\
duration effectDuration\n\
\n\
\n\
uint8 priority\n\
\n\
\n\
================================================================================\n\
MSG: pal_device_msgs/LedGroup\n\
byte LEFT_EAR = 1\n\
byte RIGHT_EAR = 2\n\
\n\
#OR-mask of the selected leds\n\
uint32 ledMask\n\
\n\
================================================================================\n\
MSG: std_msgs/ColorRGBA\n\
float32 r\n\
float32 g\n\
float32 b\n\
float32 a\n\
";
  }

  static const char* value(const ::pal_device_msgs::TimedColourEffectRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::pal_device_msgs::TimedColourEffectRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.leds);
      stream.next(m.color);
      stream.next(m.effectDuration);
      stream.next(m.priority);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct TimedColourEffectRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::pal_device_msgs::TimedColourEffectRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::pal_device_msgs::TimedColourEffectRequest_<ContainerAllocator>& v)
  {
    s << indent << "leds: ";
    s << std::endl;
    Printer< ::pal_device_msgs::LedGroup_<ContainerAllocator> >::stream(s, indent + "  ", v.leds);
    s << indent << "color: ";
    s << std::endl;
    Printer< ::std_msgs::ColorRGBA_<ContainerAllocator> >::stream(s, indent + "  ", v.color);
    s << indent << "effectDuration: ";
    Printer<ros::Duration>::stream(s, indent + "  ", v.effectDuration);
    s << indent << "priority: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.priority);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PAL_DEVICE_MSGS_MESSAGE_TIMEDCOLOUREFFECTREQUEST_H
