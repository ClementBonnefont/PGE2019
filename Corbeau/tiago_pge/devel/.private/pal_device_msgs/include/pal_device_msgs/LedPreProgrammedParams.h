// Generated by gencpp from file pal_device_msgs/LedPreProgrammedParams.msg
// DO NOT EDIT!


#ifndef PAL_DEVICE_MSGS_MESSAGE_LEDPREPROGRAMMEDPARAMS_H
#define PAL_DEVICE_MSGS_MESSAGE_LEDPREPROGRAMMEDPARAMS_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace pal_device_msgs
{
template <class ContainerAllocator>
struct LedPreProgrammedParams_
{
  typedef LedPreProgrammedParams_<ContainerAllocator> Type;

  LedPreProgrammedParams_()
    : preprogrammed_id(0)  {
    }
  LedPreProgrammedParams_(const ContainerAllocator& _alloc)
    : preprogrammed_id(0)  {
  (void)_alloc;
    }



   typedef uint8_t _preprogrammed_id_type;
  _preprogrammed_id_type preprogrammed_id;





  typedef boost::shared_ptr< ::pal_device_msgs::LedPreProgrammedParams_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::pal_device_msgs::LedPreProgrammedParams_<ContainerAllocator> const> ConstPtr;

}; // struct LedPreProgrammedParams_

typedef ::pal_device_msgs::LedPreProgrammedParams_<std::allocator<void> > LedPreProgrammedParams;

typedef boost::shared_ptr< ::pal_device_msgs::LedPreProgrammedParams > LedPreProgrammedParamsPtr;
typedef boost::shared_ptr< ::pal_device_msgs::LedPreProgrammedParams const> LedPreProgrammedParamsConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::pal_device_msgs::LedPreProgrammedParams_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::pal_device_msgs::LedPreProgrammedParams_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::pal_device_msgs::LedPreProgrammedParams_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::pal_device_msgs::LedPreProgrammedParams_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::pal_device_msgs::LedPreProgrammedParams_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::pal_device_msgs::LedPreProgrammedParams_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::pal_device_msgs::LedPreProgrammedParams_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::pal_device_msgs::LedPreProgrammedParams_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::pal_device_msgs::LedPreProgrammedParams_<ContainerAllocator> >
{
  static const char* value()
  {
    return "269ccb5728503bb2fd4261e5b289d3c1";
  }

  static const char* value(const ::pal_device_msgs::LedPreProgrammedParams_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x269ccb5728503bb2ULL;
  static const uint64_t static_value2 = 0xfd4261e5b289d3c1ULL;
};

template<class ContainerAllocator>
struct DataType< ::pal_device_msgs::LedPreProgrammedParams_<ContainerAllocator> >
{
  static const char* value()
  {
    return "pal_device_msgs/LedPreProgrammedParams";
  }

  static const char* value(const ::pal_device_msgs::LedPreProgrammedParams_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::pal_device_msgs::LedPreProgrammedParams_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#Id of pre-programmed effect, most likely device specific\n\
uint8 preprogrammed_id\n\
";
  }

  static const char* value(const ::pal_device_msgs::LedPreProgrammedParams_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::pal_device_msgs::LedPreProgrammedParams_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.preprogrammed_id);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct LedPreProgrammedParams_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::pal_device_msgs::LedPreProgrammedParams_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::pal_device_msgs::LedPreProgrammedParams_<ContainerAllocator>& v)
  {
    s << indent << "preprogrammed_id: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.preprogrammed_id);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PAL_DEVICE_MSGS_MESSAGE_LEDPREPROGRAMMEDPARAMS_H
