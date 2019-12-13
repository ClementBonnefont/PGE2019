// Generated by gencpp from file pal_device_msgs/LedDataArrayParams.msg
// DO NOT EDIT!


#ifndef PAL_DEVICE_MSGS_MESSAGE_LEDDATAARRAYPARAMS_H
#define PAL_DEVICE_MSGS_MESSAGE_LEDDATAARRAYPARAMS_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/ColorRGBA.h>

namespace pal_device_msgs
{
template <class ContainerAllocator>
struct LedDataArrayParams_
{
  typedef LedDataArrayParams_<ContainerAllocator> Type;

  LedDataArrayParams_()
    : data()  {
    }
  LedDataArrayParams_(const ContainerAllocator& _alloc)
    : data(_alloc)  {
  (void)_alloc;
    }



   typedef std::vector< ::std_msgs::ColorRGBA_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::std_msgs::ColorRGBA_<ContainerAllocator> >::other >  _data_type;
  _data_type data;





  typedef boost::shared_ptr< ::pal_device_msgs::LedDataArrayParams_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::pal_device_msgs::LedDataArrayParams_<ContainerAllocator> const> ConstPtr;

}; // struct LedDataArrayParams_

typedef ::pal_device_msgs::LedDataArrayParams_<std::allocator<void> > LedDataArrayParams;

typedef boost::shared_ptr< ::pal_device_msgs::LedDataArrayParams > LedDataArrayParamsPtr;
typedef boost::shared_ptr< ::pal_device_msgs::LedDataArrayParams const> LedDataArrayParamsConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::pal_device_msgs::LedDataArrayParams_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::pal_device_msgs::LedDataArrayParams_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::pal_device_msgs::LedDataArrayParams_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::pal_device_msgs::LedDataArrayParams_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::pal_device_msgs::LedDataArrayParams_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::pal_device_msgs::LedDataArrayParams_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::pal_device_msgs::LedDataArrayParams_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::pal_device_msgs::LedDataArrayParams_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::pal_device_msgs::LedDataArrayParams_<ContainerAllocator> >
{
  static const char* value()
  {
    return "61714ccdbab6d68e5c7a3305a077f115";
  }

  static const char* value(const ::pal_device_msgs::LedDataArrayParams_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x61714ccdbab6d68eULL;
  static const uint64_t static_value2 = 0x5c7a3305a077f115ULL;
};

template<class ContainerAllocator>
struct DataType< ::pal_device_msgs::LedDataArrayParams_<ContainerAllocator> >
{
  static const char* value()
  {
    return "pal_device_msgs/LedDataArrayParams";
  }

  static const char* value(const ::pal_device_msgs::LedDataArrayParams_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::pal_device_msgs::LedDataArrayParams_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#Data of the effect, each element in the array represents a led, \n\
#length should match device led count\n\
#For devices with no RGB option, just the alpha channel will be used\n\
std_msgs/ColorRGBA[] data\n\
\n\
================================================================================\n\
MSG: std_msgs/ColorRGBA\n\
float32 r\n\
float32 g\n\
float32 b\n\
float32 a\n\
";
  }

  static const char* value(const ::pal_device_msgs::LedDataArrayParams_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::pal_device_msgs::LedDataArrayParams_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.data);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct LedDataArrayParams_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::pal_device_msgs::LedDataArrayParams_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::pal_device_msgs::LedDataArrayParams_<ContainerAllocator>& v)
  {
    s << indent << "data[]" << std::endl;
    for (size_t i = 0; i < v.data.size(); ++i)
    {
      s << indent << "  data[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::std_msgs::ColorRGBA_<ContainerAllocator> >::stream(s, indent + "    ", v.data[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // PAL_DEVICE_MSGS_MESSAGE_LEDDATAARRAYPARAMS_H
