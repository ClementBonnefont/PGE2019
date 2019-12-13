// Generated by gencpp from file pal_interaction_msgs/ASRFileGoal.msg
// DO NOT EDIT!


#ifndef PAL_INTERACTION_MSGS_MESSAGE_ASRFILEGOAL_H
#define PAL_INTERACTION_MSGS_MESSAGE_ASRFILEGOAL_H


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
struct ASRFileGoal_
{
  typedef ASRFileGoal_<ContainerAllocator> Type;

  ASRFileGoal_()
    : file()
    , lang_id()
    , grammar()  {
    }
  ASRFileGoal_(const ContainerAllocator& _alloc)
    : file(_alloc)
    , lang_id(_alloc)
    , grammar(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _file_type;
  _file_type file;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _lang_id_type;
  _lang_id_type lang_id;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _grammar_type;
  _grammar_type grammar;





  typedef boost::shared_ptr< ::pal_interaction_msgs::ASRFileGoal_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::pal_interaction_msgs::ASRFileGoal_<ContainerAllocator> const> ConstPtr;

}; // struct ASRFileGoal_

typedef ::pal_interaction_msgs::ASRFileGoal_<std::allocator<void> > ASRFileGoal;

typedef boost::shared_ptr< ::pal_interaction_msgs::ASRFileGoal > ASRFileGoalPtr;
typedef boost::shared_ptr< ::pal_interaction_msgs::ASRFileGoal const> ASRFileGoalConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::pal_interaction_msgs::ASRFileGoal_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::pal_interaction_msgs::ASRFileGoal_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::pal_interaction_msgs::ASRFileGoal_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::pal_interaction_msgs::ASRFileGoal_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::pal_interaction_msgs::ASRFileGoal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::pal_interaction_msgs::ASRFileGoal_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::pal_interaction_msgs::ASRFileGoal_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::pal_interaction_msgs::ASRFileGoal_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::pal_interaction_msgs::ASRFileGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "31bee1dbb9e7542a0b7c4085dead9edf";
  }

  static const char* value(const ::pal_interaction_msgs::ASRFileGoal_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x31bee1dbb9e7542aULL;
  static const uint64_t static_value2 = 0x0b7c4085dead9edfULL;
};

template<class ContainerAllocator>
struct DataType< ::pal_interaction_msgs::ASRFileGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "pal_interaction_msgs/ASRFileGoal";
  }

  static const char* value(const ::pal_interaction_msgs::ASRFileGoal_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::pal_interaction_msgs::ASRFileGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
##goal definition\n\
# absolute path to the file to be recognised.\n\
# format has to be PCM 16 bits signed integer\n\
string file\n\
# language id. (i.e., en_US, es_ES, ...)\n\
string lang_id\n\
# grammar name\n\
string grammar\n\
";
  }

  static const char* value(const ::pal_interaction_msgs::ASRFileGoal_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::pal_interaction_msgs::ASRFileGoal_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.file);
      stream.next(m.lang_id);
      stream.next(m.grammar);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ASRFileGoal_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::pal_interaction_msgs::ASRFileGoal_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::pal_interaction_msgs::ASRFileGoal_<ContainerAllocator>& v)
  {
    s << indent << "file: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.file);
    s << indent << "lang_id: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.lang_id);
    s << indent << "grammar: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.grammar);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PAL_INTERACTION_MSGS_MESSAGE_ASRFILEGOAL_H
