// Generated by gencpp from file tf_lookup/Subscription.msg
// DO NOT EDIT!


#ifndef TF_LOOKUP_MESSAGE_SUBSCRIPTION_H
#define TF_LOOKUP_MESSAGE_SUBSCRIPTION_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace tf_lookup
{
template <class ContainerAllocator>
struct Subscription_
{
  typedef Subscription_<ContainerAllocator> Type;

  Subscription_()
    : target()
    , source()  {
    }
  Subscription_(const ContainerAllocator& _alloc)
    : target(_alloc)
    , source(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _target_type;
  _target_type target;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _source_type;
  _source_type source;





  typedef boost::shared_ptr< ::tf_lookup::Subscription_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::tf_lookup::Subscription_<ContainerAllocator> const> ConstPtr;

}; // struct Subscription_

typedef ::tf_lookup::Subscription_<std::allocator<void> > Subscription;

typedef boost::shared_ptr< ::tf_lookup::Subscription > SubscriptionPtr;
typedef boost::shared_ptr< ::tf_lookup::Subscription const> SubscriptionConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::tf_lookup::Subscription_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::tf_lookup::Subscription_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace tf_lookup

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'tf_lookup': ['/home/pge/tiago_pge/devel/.private/tf_lookup/share/tf_lookup/msg', '/home/pge/tiago_pge/src/tf_lookup/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::tf_lookup::Subscription_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::tf_lookup::Subscription_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::tf_lookup::Subscription_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::tf_lookup::Subscription_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::tf_lookup::Subscription_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::tf_lookup::Subscription_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::tf_lookup::Subscription_<ContainerAllocator> >
{
  static const char* value()
  {
    return "2f26b645cf5988fb447dd948d42f673d";
  }

  static const char* value(const ::tf_lookup::Subscription_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x2f26b645cf5988fbULL;
  static const uint64_t static_value2 = 0x447dd948d42f673dULL;
};

template<class ContainerAllocator>
struct DataType< ::tf_lookup::Subscription_<ContainerAllocator> >
{
  static const char* value()
  {
    return "tf_lookup/Subscription";
  }

  static const char* value(const ::tf_lookup::Subscription_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::tf_lookup::Subscription_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string target\n\
string source\n\
";
  }

  static const char* value(const ::tf_lookup::Subscription_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::tf_lookup::Subscription_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.target);
      stream.next(m.source);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Subscription_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::tf_lookup::Subscription_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::tf_lookup::Subscription_<ContainerAllocator>& v)
  {
    s << indent << "target: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.target);
    s << indent << "source: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.source);
  }
};

} // namespace message_operations
} // namespace ros

#endif // TF_LOOKUP_MESSAGE_SUBSCRIPTION_H
