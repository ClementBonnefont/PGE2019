// Generated by gencpp from file pal_device_msgs/DoTimedLedEffectGoal.msg
// DO NOT EDIT!


#ifndef PAL_DEVICE_MSGS_MESSAGE_DOTIMEDLEDEFFECTGOAL_H
#define PAL_DEVICE_MSGS_MESSAGE_DOTIMEDLEDEFFECTGOAL_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <pal_device_msgs/LedEffectParams.h>

namespace pal_device_msgs
{
template <class ContainerAllocator>
struct DoTimedLedEffectGoal_
{
  typedef DoTimedLedEffectGoal_<ContainerAllocator> Type;

  DoTimedLedEffectGoal_()
    : devices()
    , params()
    , effectDuration()
    , priority(0)  {
    }
  DoTimedLedEffectGoal_(const ContainerAllocator& _alloc)
    : devices(_alloc)
    , params(_alloc)
    , effectDuration()
    , priority(0)  {
  (void)_alloc;
    }



   typedef std::vector<uint32_t, typename ContainerAllocator::template rebind<uint32_t>::other >  _devices_type;
  _devices_type devices;

   typedef  ::pal_device_msgs::LedEffectParams_<ContainerAllocator>  _params_type;
  _params_type params;

   typedef ros::Duration _effectDuration_type;
  _effectDuration_type effectDuration;

   typedef uint8_t _priority_type;
  _priority_type priority;





  typedef boost::shared_ptr< ::pal_device_msgs::DoTimedLedEffectGoal_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::pal_device_msgs::DoTimedLedEffectGoal_<ContainerAllocator> const> ConstPtr;

}; // struct DoTimedLedEffectGoal_

typedef ::pal_device_msgs::DoTimedLedEffectGoal_<std::allocator<void> > DoTimedLedEffectGoal;

typedef boost::shared_ptr< ::pal_device_msgs::DoTimedLedEffectGoal > DoTimedLedEffectGoalPtr;
typedef boost::shared_ptr< ::pal_device_msgs::DoTimedLedEffectGoal const> DoTimedLedEffectGoalConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::pal_device_msgs::DoTimedLedEffectGoal_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::pal_device_msgs::DoTimedLedEffectGoal_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace pal_device_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'pal_device_msgs': ['/home/pge/tiago_pge/src/pal_msgs/pal_device_msgs/msg', '/home/pge/tiago_pge/devel/.private/pal_device_msgs/share/pal_device_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::pal_device_msgs::DoTimedLedEffectGoal_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::pal_device_msgs::DoTimedLedEffectGoal_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::pal_device_msgs::DoTimedLedEffectGoal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::pal_device_msgs::DoTimedLedEffectGoal_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::pal_device_msgs::DoTimedLedEffectGoal_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::pal_device_msgs::DoTimedLedEffectGoal_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::pal_device_msgs::DoTimedLedEffectGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "e94eafb34df9ab3216d4d9fc90569af3";
  }

  static const char* value(const ::pal_device_msgs::DoTimedLedEffectGoal_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xe94eafb34df9ab32ULL;
  static const uint64_t static_value2 = 0x16d4d9fc90569af3ULL;
};

template<class ContainerAllocator>
struct DataType< ::pal_device_msgs::DoTimedLedEffectGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "pal_device_msgs/DoTimedLedEffectGoal";
  }

  static const char* value(const ::pal_device_msgs::DoTimedLedEffectGoal_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::pal_device_msgs::DoTimedLedEffectGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
#uint16 because uint8 is char[] in Python\n\
uint32[] devices\n\
\n\
#Contains parameters for all led effects, but only the selected effect type parameters shall be provided\n\
LedEffectParams params\n\
#Duration of the effect, when the time is over the previous effect will be restored. 0 will make it display forever\n\
duration effectDuration\n\
\n\
#priority of the effect, 0 is no priority, 255 is max priority\n\
uint8 priority\n\
\n\
================================================================================\n\
MSG: pal_device_msgs/LedEffectParams\n\
uint8 FIXED_COLOR=0\n\
uint8 RAINBOW=1\n\
uint8 FADE=2\n\
uint8 BLINK=3\n\
uint8 PROGRESS=4\n\
uint8 FLOW=5\n\
uint8 PREPROGRAMMED_EFFECT=6\n\
uint8 EFFECT_VIA_TOPIC=7\n\
uint8 DATA_ARRAY=8\n\
\n\
uint8 effectType\n\
\n\
# RGBA of color, alpha will be used as intensity if supported by the led\n\
pal_device_msgs/LedFixedColorParams fixed_color\n\
pal_device_msgs/LedRainbowParams rainbow\n\
pal_device_msgs/LedFadeParams fade\n\
pal_device_msgs/LedBlinkParams blink\n\
pal_device_msgs/LedProgressParams progress\n\
pal_device_msgs/LedFlowParams flow\n\
#Below are device specific, avoid them if you can\n\
pal_device_msgs/LedPreProgrammedParams preprogrammed\n\
pal_device_msgs/LedEffectViaTopicParams effect_via_topic\n\
pal_device_msgs/LedDataArrayParams data_array\n\
\n\
================================================================================\n\
MSG: pal_device_msgs/LedFixedColorParams\n\
# RGBA of color, alpha will be used as intensity if supported by the led\n\
std_msgs/ColorRGBA color\n\
\n\
================================================================================\n\
MSG: std_msgs/ColorRGBA\n\
float32 r\n\
float32 g\n\
float32 b\n\
float32 a\n\
\n\
================================================================================\n\
MSG: pal_device_msgs/LedRainbowParams\n\
# Time to perform rainbow\n\
duration transition_duration\n\
\n\
================================================================================\n\
MSG: pal_device_msgs/LedFadeParams\n\
# RGBA of color, alpha will be used as intensity if supported by the led\n\
std_msgs/ColorRGBA first_color\n\
std_msgs/ColorRGBA second_color\n\
\n\
#Duration of the transition from one color to the other\n\
duration transition_duration\n\
\n\
#Perform a fade when going from secondColor to firstColor\n\
bool reverse_fade\n\
\n\
\n\
================================================================================\n\
MSG: pal_device_msgs/LedBlinkParams\n\
# RGBA of color, alpha will be used as intensity if supported by the led\n\
std_msgs/ColorRGBA first_color\n\
std_msgs/ColorRGBA second_color\n\
\n\
duration first_color_duration\n\
duration second_color_duration\n\
\n\
\n\
================================================================================\n\
MSG: pal_device_msgs/LedProgressParams\n\
# RGBA of color, alpha will be used as intensity if supported by the led\n\
std_msgs/ColorRGBA first_color\n\
std_msgs/ColorRGBA second_color\n\
\n\
#Percentage of pixels painted with the first color\n\
float32 percentage\n\
#Offset to begin painting the first color\n\
float32 led_offset \n\
\n\
\n\
================================================================================\n\
MSG: pal_device_msgs/LedFlowParams\n\
# RGBA of color, alpha will be used as intensity if supported by the led\n\
std_msgs/ColorRGBA first_color\n\
std_msgs/ColorRGBA second_color\n\
\n\
# Percentage of pixels painted with the first color\n\
float32 percentage\n\
# Flow velocity\n\
float32 velocity\n\
\n\
\n\
================================================================================\n\
MSG: pal_device_msgs/LedPreProgrammedParams\n\
#Id of pre-programmed effect, most likely device specific\n\
uint8 preprogrammed_id\n\
\n\
================================================================================\n\
MSG: pal_device_msgs/LedEffectViaTopicParams\n\
#Topic name, must be of type pal_device_msgs/LedDataArray\n\
string topic_name\n\
\n\
================================================================================\n\
MSG: pal_device_msgs/LedDataArrayParams\n\
#Data of the effect, each element in the array represents a led, \n\
#length should match device led count\n\
#For devices with no RGB option, just the alpha channel will be used\n\
std_msgs/ColorRGBA[] data\n\
";
  }

  static const char* value(const ::pal_device_msgs::DoTimedLedEffectGoal_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::pal_device_msgs::DoTimedLedEffectGoal_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.devices);
      stream.next(m.params);
      stream.next(m.effectDuration);
      stream.next(m.priority);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct DoTimedLedEffectGoal_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::pal_device_msgs::DoTimedLedEffectGoal_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::pal_device_msgs::DoTimedLedEffectGoal_<ContainerAllocator>& v)
  {
    s << indent << "devices[]" << std::endl;
    for (size_t i = 0; i < v.devices.size(); ++i)
    {
      s << indent << "  devices[" << i << "]: ";
      Printer<uint32_t>::stream(s, indent + "  ", v.devices[i]);
    }
    s << indent << "params: ";
    s << std::endl;
    Printer< ::pal_device_msgs::LedEffectParams_<ContainerAllocator> >::stream(s, indent + "  ", v.params);
    s << indent << "effectDuration: ";
    Printer<ros::Duration>::stream(s, indent + "  ", v.effectDuration);
    s << indent << "priority: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.priority);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PAL_DEVICE_MSGS_MESSAGE_DOTIMEDLEDEFFECTGOAL_H
