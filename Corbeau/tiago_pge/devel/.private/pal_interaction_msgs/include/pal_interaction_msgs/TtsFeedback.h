// Generated by gencpp from file pal_interaction_msgs/TtsFeedback.msg
// DO NOT EDIT!


#ifndef PAL_INTERACTION_MSGS_MESSAGE_TTSFEEDBACK_H
#define PAL_INTERACTION_MSGS_MESSAGE_TTSFEEDBACK_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <pal_interaction_msgs/TtsMark.h>

namespace pal_interaction_msgs
{
template <class ContainerAllocator>
struct TtsFeedback_
{
  typedef TtsFeedback_<ContainerAllocator> Type;

  TtsFeedback_()
    : event_type(0)
    , timestamp()
    , text_said()
    , next_word()
    , viseme_id()
    , marks()  {
    }
  TtsFeedback_(const ContainerAllocator& _alloc)
    : event_type(0)
    , timestamp()
    , text_said(_alloc)
    , next_word(_alloc)
    , viseme_id(_alloc)
    , marks(_alloc)  {
  (void)_alloc;
    }



   typedef uint16_t _event_type_type;
  _event_type_type event_type;

   typedef ros::Time _timestamp_type;
  _timestamp_type timestamp;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _text_said_type;
  _text_said_type text_said;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _next_word_type;
  _next_word_type next_word;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _viseme_id_type;
  _viseme_id_type viseme_id;

   typedef  ::pal_interaction_msgs::TtsMark_<ContainerAllocator>  _marks_type;
  _marks_type marks;



  enum {
    TTS_EVENT_INITIALIZATION = 1u,
    TTS_EVENT_SHUTDOWN = 2u,
    TTS_EVENT_SYNCHRONIZATION = 4u,
    TTS_EVENT_FINISHED_PLAYING_UTTERANCE = 8u,
    TTS_EVENT_MARK = 16u,
    TTS_EVENT_STARTED_PLAYING_WORD = 32u,
    TTS_EVENT_FINISHED_PLAYING_PHRASE = 64u,
    TTS_EVENT_FINISHED_PLAYING_SENTENCE = 128u,
    TTS_EVENT_VISEME = 256u,
  };


  typedef boost::shared_ptr< ::pal_interaction_msgs::TtsFeedback_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::pal_interaction_msgs::TtsFeedback_<ContainerAllocator> const> ConstPtr;

}; // struct TtsFeedback_

typedef ::pal_interaction_msgs::TtsFeedback_<std::allocator<void> > TtsFeedback;

typedef boost::shared_ptr< ::pal_interaction_msgs::TtsFeedback > TtsFeedbackPtr;
typedef boost::shared_ptr< ::pal_interaction_msgs::TtsFeedback const> TtsFeedbackConstPtr;

// constants requiring out of line definition

   

   

   

   

   

   

   

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::pal_interaction_msgs::TtsFeedback_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::pal_interaction_msgs::TtsFeedback_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::pal_interaction_msgs::TtsFeedback_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::pal_interaction_msgs::TtsFeedback_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::pal_interaction_msgs::TtsFeedback_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::pal_interaction_msgs::TtsFeedback_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::pal_interaction_msgs::TtsFeedback_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::pal_interaction_msgs::TtsFeedback_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::pal_interaction_msgs::TtsFeedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "05870cd8b62fcb00e76ae3889c0ed8f1";
  }

  static const char* value(const ::pal_interaction_msgs::TtsFeedback_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x05870cd8b62fcb00ULL;
  static const uint64_t static_value2 = 0xe76ae3889c0ed8f1ULL;
};

template<class ContainerAllocator>
struct DataType< ::pal_interaction_msgs::TtsFeedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "pal_interaction_msgs/TtsFeedback";
  }

  static const char* value(const ::pal_interaction_msgs::TtsFeedback_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::pal_interaction_msgs::TtsFeedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
## feedback\n\
\n\
# Everytime one of the following events occuring\n\
# during the synthesis process a feedback message\n\
# will be published.\n\
# Only TTS_EVENT_STARTED_PLAYING_WORD and \n\
# TTS_EVENT_MARK are implemented now.\n\
\n\
uint16 TTS_EVENT_INITIALIZATION = 1\n\
uint16 TTS_EVENT_SHUTDOWN = 2\n\
uint16 TTS_EVENT_SYNCHRONIZATION = 4\n\
uint16 TTS_EVENT_FINISHED_PLAYING_UTTERANCE = 8\n\
uint16 TTS_EVENT_MARK = 16\n\
uint16 TTS_EVENT_STARTED_PLAYING_WORD = 32\n\
uint16 TTS_EVENT_FINISHED_PLAYING_PHRASE = 64\n\
uint16 TTS_EVENT_FINISHED_PLAYING_SENTENCE = 128\n\
uint16 TTS_EVENT_VISEME = 256\n\
\n\
# Store the event type and can be used\n\
# to filter messages depending on the type of \n\
# events we are interested in\n\
\n\
uint16 event_type\n\
\n\
# Time since the begining of the synthesis\n\
# at which the event occured.\n\
\n\
time timestamp\n\
\n\
# Text said until now, \n\
# it will contain the current word in case of WORD events\n\
\n\
string text_said\n\
\n\
# Next word to be pronounced\n\
# (not implemented)\n\
string next_word\n\
\n\
string viseme_id\n\
\n\
# Everytime a mark like this one\n\
# <mark name=\"markname\"/> is present in the text\n\
# a MARK event will be generated with the 'name' \n\
# argument value as mark id. Other fields\n\
# different from the mark_id are not implemented.\n\
\n\
TtsMark marks\n\
\n\
\n\
================================================================================\n\
MSG: pal_interaction_msgs/TtsMark\n\
# id will contain the value of name argument in the <mark/>\n\
# tags when they are placed in synthesised text.\n\
# Filling keys and value is not implemented yet.\n\
string id\n\
string[] keys\n\
string[] value\n\
";
  }

  static const char* value(const ::pal_interaction_msgs::TtsFeedback_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::pal_interaction_msgs::TtsFeedback_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.event_type);
      stream.next(m.timestamp);
      stream.next(m.text_said);
      stream.next(m.next_word);
      stream.next(m.viseme_id);
      stream.next(m.marks);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct TtsFeedback_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::pal_interaction_msgs::TtsFeedback_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::pal_interaction_msgs::TtsFeedback_<ContainerAllocator>& v)
  {
    s << indent << "event_type: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.event_type);
    s << indent << "timestamp: ";
    Printer<ros::Time>::stream(s, indent + "  ", v.timestamp);
    s << indent << "text_said: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.text_said);
    s << indent << "next_word: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.next_word);
    s << indent << "viseme_id: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.viseme_id);
    s << indent << "marks: ";
    s << std::endl;
    Printer< ::pal_interaction_msgs::TtsMark_<ContainerAllocator> >::stream(s, indent + "  ", v.marks);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PAL_INTERACTION_MSGS_MESSAGE_TTSFEEDBACK_H
