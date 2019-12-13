// Generated by gencpp from file controller_manager_msgs/ListControllerTypesResponse.msg
// DO NOT EDIT!


#ifndef CONTROLLER_MANAGER_MSGS_MESSAGE_LISTCONTROLLERTYPESRESPONSE_H
#define CONTROLLER_MANAGER_MSGS_MESSAGE_LISTCONTROLLERTYPESRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace controller_manager_msgs
{
template <class ContainerAllocator>
struct ListControllerTypesResponse_
{
  typedef ListControllerTypesResponse_<ContainerAllocator> Type;

  ListControllerTypesResponse_()
    : types()
    , base_classes()  {
    }
  ListControllerTypesResponse_(const ContainerAllocator& _alloc)
    : types(_alloc)
    , base_classes(_alloc)  {
  (void)_alloc;
    }



   typedef std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > , typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::other >  _types_type;
  _types_type types;

   typedef std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > , typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::other >  _base_classes_type;
  _base_classes_type base_classes;





  typedef boost::shared_ptr< ::controller_manager_msgs::ListControllerTypesResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::controller_manager_msgs::ListControllerTypesResponse_<ContainerAllocator> const> ConstPtr;

}; // struct ListControllerTypesResponse_

typedef ::controller_manager_msgs::ListControllerTypesResponse_<std::allocator<void> > ListControllerTypesResponse;

typedef boost::shared_ptr< ::controller_manager_msgs::ListControllerTypesResponse > ListControllerTypesResponsePtr;
typedef boost::shared_ptr< ::controller_manager_msgs::ListControllerTypesResponse const> ListControllerTypesResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::controller_manager_msgs::ListControllerTypesResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::controller_manager_msgs::ListControllerTypesResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace controller_manager_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'controller_manager_msgs': ['/home/pge/tiago_pge/src/ros_control/controller_manager_msgs/msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::controller_manager_msgs::ListControllerTypesResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::controller_manager_msgs::ListControllerTypesResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::controller_manager_msgs::ListControllerTypesResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::controller_manager_msgs::ListControllerTypesResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::controller_manager_msgs::ListControllerTypesResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::controller_manager_msgs::ListControllerTypesResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::controller_manager_msgs::ListControllerTypesResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "c1d4cd11aefa9f97ba4aeb5b33987f4e";
  }

  static const char* value(const ::controller_manager_msgs::ListControllerTypesResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xc1d4cd11aefa9f97ULL;
  static const uint64_t static_value2 = 0xba4aeb5b33987f4eULL;
};

template<class ContainerAllocator>
struct DataType< ::controller_manager_msgs::ListControllerTypesResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "controller_manager_msgs/ListControllerTypesResponse";
  }

  static const char* value(const ::controller_manager_msgs::ListControllerTypesResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::controller_manager_msgs::ListControllerTypesResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string[] types\n\
string[] base_classes\n\
\n\
";
  }

  static const char* value(const ::controller_manager_msgs::ListControllerTypesResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::controller_manager_msgs::ListControllerTypesResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.types);
      stream.next(m.base_classes);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ListControllerTypesResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::controller_manager_msgs::ListControllerTypesResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::controller_manager_msgs::ListControllerTypesResponse_<ContainerAllocator>& v)
  {
    s << indent << "types[]" << std::endl;
    for (size_t i = 0; i < v.types.size(); ++i)
    {
      s << indent << "  types[" << i << "]: ";
      Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.types[i]);
    }
    s << indent << "base_classes[]" << std::endl;
    for (size_t i = 0; i < v.base_classes.size(); ++i)
    {
      s << indent << "  base_classes[" << i << "]: ";
      Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.base_classes[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // CONTROLLER_MANAGER_MSGS_MESSAGE_LISTCONTROLLERTYPESRESPONSE_H
