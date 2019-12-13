// Generated by gencpp from file mode_state_controller/ModeState.msg
// DO NOT EDIT!


#ifndef MODE_STATE_CONTROLLER_MESSAGE_MODESTATE_H
#define MODE_STATE_CONTROLLER_MESSAGE_MODESTATE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace mode_state_controller
{
template <class ContainerAllocator>
struct ModeState_
{
  typedef ModeState_<ContainerAllocator> Type;

  ModeState_()
    : header()
    , name()
    , mode()  {
    }
  ModeState_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , name(_alloc)
    , mode(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > , typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::other >  _name_type;
  _name_type name;

   typedef std::vector<int32_t, typename ContainerAllocator::template rebind<int32_t>::other >  _mode_type;
  _mode_type mode;



  enum {
    BEGIN = -1,
    MODE_POSITION = 0,
    MODE_VELOCITY = 1,
    MODE_EFFORT = 2,
    NOMODE = 3,
    EMERGENCY_STOP = 4,
    SWITCHING = 5,
    ERROR = 6,
  };


  typedef boost::shared_ptr< ::mode_state_controller::ModeState_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::mode_state_controller::ModeState_<ContainerAllocator> const> ConstPtr;

}; // struct ModeState_

typedef ::mode_state_controller::ModeState_<std::allocator<void> > ModeState;

typedef boost::shared_ptr< ::mode_state_controller::ModeState > ModeStatePtr;
typedef boost::shared_ptr< ::mode_state_controller::ModeState const> ModeStateConstPtr;

// constants requiring out of line definition

   

   

   

   

   

   

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::mode_state_controller::ModeState_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::mode_state_controller::ModeState_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace mode_state_controller

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'mode_state_controller': ['/home/pge/tiago_pge/src/ros_controllers/mode_state_controller/msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::mode_state_controller::ModeState_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::mode_state_controller::ModeState_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mode_state_controller::ModeState_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mode_state_controller::ModeState_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mode_state_controller::ModeState_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mode_state_controller::ModeState_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::mode_state_controller::ModeState_<ContainerAllocator> >
{
  static const char* value()
  {
    return "1876cce35893829a3c52c7fd8f021768";
  }

  static const char* value(const ::mode_state_controller::ModeState_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x1876cce35893829aULL;
  static const uint64_t static_value2 = 0x3c52c7fd8f021768ULL;
};

template<class ContainerAllocator>
struct DataType< ::mode_state_controller::ModeState_<ContainerAllocator> >
{
  static const char* value()
  {
    return "mode_state_controller/ModeState";
  }

  static const char* value(const ::mode_state_controller::ModeState_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::mode_state_controller::ModeState_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32 BEGIN = -1\n\
int32 MODE_POSITION = 0\n\
int32 MODE_VELOCITY = 1\n\
int32 MODE_EFFORT = 2\n\
int32 NOMODE = 3\n\
int32 EMERGENCY_STOP = 4\n\
int32 SWITCHING = 5\n\
int32 ERROR = 6\n\
Header header\n\
\n\
string[] name\n\
int32[] mode\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
";
  }

  static const char* value(const ::mode_state_controller::ModeState_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::mode_state_controller::ModeState_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.name);
      stream.next(m.mode);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ModeState_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::mode_state_controller::ModeState_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::mode_state_controller::ModeState_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "name[]" << std::endl;
    for (size_t i = 0; i < v.name.size(); ++i)
    {
      s << indent << "  name[" << i << "]: ";
      Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.name[i]);
    }
    s << indent << "mode[]" << std::endl;
    for (size_t i = 0; i < v.mode.size(); ++i)
    {
      s << indent << "  mode[" << i << "]: ";
      Printer<int32_t>::stream(s, indent + "  ", v.mode[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // MODE_STATE_CONTROLLER_MESSAGE_MODESTATE_H
