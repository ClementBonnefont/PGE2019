// Generated by gencpp from file pal_interaction_msgs/AudioDeviceDescription.msg
// DO NOT EDIT!


#ifndef PAL_INTERACTION_MSGS_MESSAGE_AUDIODEVICEDESCRIPTION_H
#define PAL_INTERACTION_MSGS_MESSAGE_AUDIODEVICEDESCRIPTION_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace pal_interaction_msgs
{
template <class ContainerAllocator>
struct AudioDeviceDescription_
{
  typedef AudioDeviceDescription_<ContainerAllocator> Type;

  AudioDeviceDescription_()
    : device_name()
    , sample_rate(0)
    , sample_size(0)
    , format(0)
    , buffer_size(0)
    , number_of_channels(0)  {
    }
  AudioDeviceDescription_(const ContainerAllocator& _alloc)
    : device_name(_alloc)
    , sample_rate(0)
    , sample_size(0)
    , format(0)
    , buffer_size(0)
    , number_of_channels(0)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _device_name_type;
  _device_name_type device_name;

   typedef uint32_t _sample_rate_type;
  _sample_rate_type sample_rate;

   typedef int8_t _sample_size_type;
  _sample_size_type sample_size;

   typedef int8_t _format_type;
  _format_type format;

   typedef uint16_t _buffer_size_type;
  _buffer_size_type buffer_size;

   typedef int8_t _number_of_channels_type;
  _number_of_channels_type number_of_channels;



  enum {
    SIGNED = 0,
    UNSIGNED = 1,
  };


  typedef boost::shared_ptr< ::pal_interaction_msgs::AudioDeviceDescription_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::pal_interaction_msgs::AudioDeviceDescription_<ContainerAllocator> const> ConstPtr;

}; // struct AudioDeviceDescription_

typedef ::pal_interaction_msgs::AudioDeviceDescription_<std::allocator<void> > AudioDeviceDescription;

typedef boost::shared_ptr< ::pal_interaction_msgs::AudioDeviceDescription > AudioDeviceDescriptionPtr;
typedef boost::shared_ptr< ::pal_interaction_msgs::AudioDeviceDescription const> AudioDeviceDescriptionConstPtr;

// constants requiring out of line definition

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::pal_interaction_msgs::AudioDeviceDescription_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::pal_interaction_msgs::AudioDeviceDescription_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace pal_interaction_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'pal_interaction_msgs': ['/home/pge/tiago_pge/src/pal_msgs/pal_interaction_msgs/msg', '/home/pge/tiago_pge/devel/.private/pal_interaction_msgs/share/pal_interaction_msgs/msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::pal_interaction_msgs::AudioDeviceDescription_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::pal_interaction_msgs::AudioDeviceDescription_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::pal_interaction_msgs::AudioDeviceDescription_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::pal_interaction_msgs::AudioDeviceDescription_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::pal_interaction_msgs::AudioDeviceDescription_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::pal_interaction_msgs::AudioDeviceDescription_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::pal_interaction_msgs::AudioDeviceDescription_<ContainerAllocator> >
{
  static const char* value()
  {
    return "e55171ed98aeb49e34453bc5efb47184";
  }

  static const char* value(const ::pal_interaction_msgs::AudioDeviceDescription_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xe55171ed98aeb49eULL;
  static const uint64_t static_value2 = 0x34453bc5efb47184ULL;
};

template<class ContainerAllocator>
struct DataType< ::pal_interaction_msgs::AudioDeviceDescription_<ContainerAllocator> >
{
  static const char* value()
  {
    return "pal_interaction_msgs/AudioDeviceDescription";
  }

  static const char* value(const ::pal_interaction_msgs::AudioDeviceDescription_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::pal_interaction_msgs::AudioDeviceDescription_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Description of an audio device.\n\
\n\
int8 SIGNED = 0\n\
int8 UNSIGNED = 1\n\
\n\
\n\
# name of the device (usually a portaudio name)\n\
string device_name\n\
\n\
# sample rate of the acquired audio signal\n\
uint32 sample_rate\n\
\n\
# sample size in bits\n\
int8 sample_size\n\
\n\
# format can be SIGNED or UNSIGNED\n\
int8 format\n\
\n\
# buffer size used to acquire data.\n\
uint16 buffer_size\n\
\n\
# number of recorded channels\n\
int8 number_of_channels\n\
";
  }

  static const char* value(const ::pal_interaction_msgs::AudioDeviceDescription_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::pal_interaction_msgs::AudioDeviceDescription_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.device_name);
      stream.next(m.sample_rate);
      stream.next(m.sample_size);
      stream.next(m.format);
      stream.next(m.buffer_size);
      stream.next(m.number_of_channels);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct AudioDeviceDescription_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::pal_interaction_msgs::AudioDeviceDescription_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::pal_interaction_msgs::AudioDeviceDescription_<ContainerAllocator>& v)
  {
    s << indent << "device_name: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.device_name);
    s << indent << "sample_rate: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.sample_rate);
    s << indent << "sample_size: ";
    Printer<int8_t>::stream(s, indent + "  ", v.sample_size);
    s << indent << "format: ";
    Printer<int8_t>::stream(s, indent + "  ", v.format);
    s << indent << "buffer_size: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.buffer_size);
    s << indent << "number_of_channels: ";
    Printer<int8_t>::stream(s, indent + "  ", v.number_of_channels);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PAL_INTERACTION_MSGS_MESSAGE_AUDIODEVICEDESCRIPTION_H
