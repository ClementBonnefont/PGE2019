// Generated by gencpp from file pal_interaction_msgs/I18nText.msg
// DO NOT EDIT!


#ifndef PAL_INTERACTION_MSGS_MESSAGE_I18NTEXT_H
#define PAL_INTERACTION_MSGS_MESSAGE_I18NTEXT_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <pal_interaction_msgs/I18nArgument.h>

namespace pal_interaction_msgs
{
template <class ContainerAllocator>
struct I18nText_
{
  typedef I18nText_<ContainerAllocator> Type;

  I18nText_()
    : section()
    , key()
    , lang_id()
    , arguments()  {
    }
  I18nText_(const ContainerAllocator& _alloc)
    : section(_alloc)
    , key(_alloc)
    , lang_id(_alloc)
    , arguments(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _section_type;
  _section_type section;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _key_type;
  _key_type key;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _lang_id_type;
  _lang_id_type lang_id;

   typedef std::vector< ::pal_interaction_msgs::I18nArgument_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::pal_interaction_msgs::I18nArgument_<ContainerAllocator> >::other >  _arguments_type;
  _arguments_type arguments;





  typedef boost::shared_ptr< ::pal_interaction_msgs::I18nText_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::pal_interaction_msgs::I18nText_<ContainerAllocator> const> ConstPtr;

}; // struct I18nText_

typedef ::pal_interaction_msgs::I18nText_<std::allocator<void> > I18nText;

typedef boost::shared_ptr< ::pal_interaction_msgs::I18nText > I18nTextPtr;
typedef boost::shared_ptr< ::pal_interaction_msgs::I18nText const> I18nTextConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::pal_interaction_msgs::I18nText_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::pal_interaction_msgs::I18nText_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::pal_interaction_msgs::I18nText_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::pal_interaction_msgs::I18nText_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::pal_interaction_msgs::I18nText_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::pal_interaction_msgs::I18nText_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::pal_interaction_msgs::I18nText_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::pal_interaction_msgs::I18nText_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::pal_interaction_msgs::I18nText_<ContainerAllocator> >
{
  static const char* value()
  {
    return "855c0cd82eb6837b039ea45087975cc2";
  }

  static const char* value(const ::pal_interaction_msgs::I18nText_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x855c0cd82eb6837bULL;
  static const uint64_t static_value2 = 0x039ea45087975cc2ULL;
};

template<class ContainerAllocator>
struct DataType< ::pal_interaction_msgs::I18nText_<ContainerAllocator> >
{
  static const char* value()
  {
    return "pal_interaction_msgs/I18nText";
  }

  static const char* value(const ::pal_interaction_msgs::I18nText_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::pal_interaction_msgs::I18nText_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# section/key is used as in examples in the pal_tts_cfg pkg.\n\
string section\n\
string key\n\
\n\
# language id, must be speficied using RFC 3066\n\
string lang_id\n\
\n\
# arguments contain the values by which \n\
# occurrences of '%s' will be replaced in the \n\
# main text.\n\
# This only supports up to 2 arguments and no recursion.\n\
# However, recursion and more argumnents are\n\
# planned to be supported in the future.\n\
I18nArgument[] arguments\n\
\n\
================================================================================\n\
MSG: pal_interaction_msgs/I18nArgument\n\
# section key, override the value in expanded.\n\
# Use expanded for text that do not need expansion.\n\
# Please note that expanded here will not be translated \n\
# to any language.\n\
\n\
string section\n\
string key\n\
string expanded\n\
\n\
";
  }

  static const char* value(const ::pal_interaction_msgs::I18nText_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::pal_interaction_msgs::I18nText_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.section);
      stream.next(m.key);
      stream.next(m.lang_id);
      stream.next(m.arguments);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct I18nText_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::pal_interaction_msgs::I18nText_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::pal_interaction_msgs::I18nText_<ContainerAllocator>& v)
  {
    s << indent << "section: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.section);
    s << indent << "key: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.key);
    s << indent << "lang_id: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.lang_id);
    s << indent << "arguments[]" << std::endl;
    for (size_t i = 0; i < v.arguments.size(); ++i)
    {
      s << indent << "  arguments[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::pal_interaction_msgs::I18nArgument_<ContainerAllocator> >::stream(s, indent + "    ", v.arguments[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // PAL_INTERACTION_MSGS_MESSAGE_I18NTEXT_H
