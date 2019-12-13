// Generated by gencpp from file tiago_pick_demo/PickUpPoseAction.msg
// DO NOT EDIT!


#ifndef TIAGO_PICK_DEMO_MESSAGE_PICKUPPOSEACTION_H
#define TIAGO_PICK_DEMO_MESSAGE_PICKUPPOSEACTION_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <tiago_pick_demo/PickUpPoseActionGoal.h>
#include <tiago_pick_demo/PickUpPoseActionResult.h>
#include <tiago_pick_demo/PickUpPoseActionFeedback.h>

namespace tiago_pick_demo
{
template <class ContainerAllocator>
struct PickUpPoseAction_
{
  typedef PickUpPoseAction_<ContainerAllocator> Type;

  PickUpPoseAction_()
    : action_goal()
    , action_result()
    , action_feedback()  {
    }
  PickUpPoseAction_(const ContainerAllocator& _alloc)
    : action_goal(_alloc)
    , action_result(_alloc)
    , action_feedback(_alloc)  {
  (void)_alloc;
    }



   typedef  ::tiago_pick_demo::PickUpPoseActionGoal_<ContainerAllocator>  _action_goal_type;
  _action_goal_type action_goal;

   typedef  ::tiago_pick_demo::PickUpPoseActionResult_<ContainerAllocator>  _action_result_type;
  _action_result_type action_result;

   typedef  ::tiago_pick_demo::PickUpPoseActionFeedback_<ContainerAllocator>  _action_feedback_type;
  _action_feedback_type action_feedback;





  typedef boost::shared_ptr< ::tiago_pick_demo::PickUpPoseAction_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::tiago_pick_demo::PickUpPoseAction_<ContainerAllocator> const> ConstPtr;

}; // struct PickUpPoseAction_

typedef ::tiago_pick_demo::PickUpPoseAction_<std::allocator<void> > PickUpPoseAction;

typedef boost::shared_ptr< ::tiago_pick_demo::PickUpPoseAction > PickUpPoseActionPtr;
typedef boost::shared_ptr< ::tiago_pick_demo::PickUpPoseAction const> PickUpPoseActionConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::tiago_pick_demo::PickUpPoseAction_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::tiago_pick_demo::PickUpPoseAction_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace tiago_pick_demo

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'tiago_pick_demo': ['/home/pge/tiago_pge/devel/.private/tiago_pick_demo/share/tiago_pick_demo/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::tiago_pick_demo::PickUpPoseAction_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::tiago_pick_demo::PickUpPoseAction_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::tiago_pick_demo::PickUpPoseAction_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::tiago_pick_demo::PickUpPoseAction_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::tiago_pick_demo::PickUpPoseAction_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::tiago_pick_demo::PickUpPoseAction_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::tiago_pick_demo::PickUpPoseAction_<ContainerAllocator> >
{
  static const char* value()
  {
    return "8e8c1679c6712e2937cfc19e6ab86b6e";
  }

  static const char* value(const ::tiago_pick_demo::PickUpPoseAction_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x8e8c1679c6712e29ULL;
  static const uint64_t static_value2 = 0x37cfc19e6ab86b6eULL;
};

template<class ContainerAllocator>
struct DataType< ::tiago_pick_demo::PickUpPoseAction_<ContainerAllocator> >
{
  static const char* value()
  {
    return "tiago_pick_demo/PickUpPoseAction";
  }

  static const char* value(const ::tiago_pick_demo::PickUpPoseAction_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::tiago_pick_demo::PickUpPoseAction_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
\n\
PickUpPoseActionGoal action_goal\n\
PickUpPoseActionResult action_result\n\
PickUpPoseActionFeedback action_feedback\n\
\n\
================================================================================\n\
MSG: tiago_pick_demo/PickUpPoseActionGoal\n\
# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
\n\
Header header\n\
actionlib_msgs/GoalID goal_id\n\
PickUpPoseGoal goal\n\
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
\n\
================================================================================\n\
MSG: actionlib_msgs/GoalID\n\
# The stamp should store the time at which this goal was requested.\n\
# It is used by an action server when it tries to preempt all\n\
# goals that were requested before a certain time\n\
time stamp\n\
\n\
# The id provides a way to associate feedback and\n\
# result message with specific goal requests. The id\n\
# specified must be unique.\n\
string id\n\
\n\
\n\
================================================================================\n\
MSG: tiago_pick_demo/PickUpPoseGoal\n\
# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
geometry_msgs/PoseStamped object_pose\n\
\n\
================================================================================\n\
MSG: geometry_msgs/PoseStamped\n\
# A Pose with reference coordinate frame and timestamp\n\
Header header\n\
Pose pose\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Pose\n\
# A representation of pose in free space, composed of position and orientation. \n\
Point position\n\
Quaternion orientation\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Point\n\
# This contains the position of a point in free space\n\
float64 x\n\
float64 y\n\
float64 z\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Quaternion\n\
# This represents an orientation in free space in quaternion form.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
float64 w\n\
\n\
================================================================================\n\
MSG: tiago_pick_demo/PickUpPoseActionResult\n\
# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
\n\
Header header\n\
actionlib_msgs/GoalStatus status\n\
PickUpPoseResult result\n\
\n\
================================================================================\n\
MSG: actionlib_msgs/GoalStatus\n\
GoalID goal_id\n\
uint8 status\n\
uint8 PENDING         = 0   # The goal has yet to be processed by the action server\n\
uint8 ACTIVE          = 1   # The goal is currently being processed by the action server\n\
uint8 PREEMPTED       = 2   # The goal received a cancel request after it started executing\n\
                            #   and has since completed its execution (Terminal State)\n\
uint8 SUCCEEDED       = 3   # The goal was achieved successfully by the action server (Terminal State)\n\
uint8 ABORTED         = 4   # The goal was aborted during execution by the action server due\n\
                            #    to some failure (Terminal State)\n\
uint8 REJECTED        = 5   # The goal was rejected by the action server without being processed,\n\
                            #    because the goal was unattainable or invalid (Terminal State)\n\
uint8 PREEMPTING      = 6   # The goal received a cancel request after it started executing\n\
                            #    and has not yet completed execution\n\
uint8 RECALLING       = 7   # The goal received a cancel request before it started executing,\n\
                            #    but the action server has not yet confirmed that the goal is canceled\n\
uint8 RECALLED        = 8   # The goal received a cancel request before it started executing\n\
                            #    and was successfully cancelled (Terminal State)\n\
uint8 LOST            = 9   # An action client can determine that a goal is LOST. This should not be\n\
                            #    sent over the wire by an action server\n\
\n\
#Allow for the user to associate a string with GoalStatus for debugging\n\
string text\n\
\n\
\n\
================================================================================\n\
MSG: tiago_pick_demo/PickUpPoseResult\n\
# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
#result definition\n\
# Comes from moveit_msgs/MoveItErrorCodes\n\
int32 error_code\n\
\n\
================================================================================\n\
MSG: tiago_pick_demo/PickUpPoseActionFeedback\n\
# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
\n\
Header header\n\
actionlib_msgs/GoalStatus status\n\
PickUpPoseFeedback feedback\n\
\n\
================================================================================\n\
MSG: tiago_pick_demo/PickUpPoseFeedback\n\
# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
#feedback\n\
\n\
";
  }

  static const char* value(const ::tiago_pick_demo::PickUpPoseAction_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::tiago_pick_demo::PickUpPoseAction_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.action_goal);
      stream.next(m.action_result);
      stream.next(m.action_feedback);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct PickUpPoseAction_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::tiago_pick_demo::PickUpPoseAction_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::tiago_pick_demo::PickUpPoseAction_<ContainerAllocator>& v)
  {
    s << indent << "action_goal: ";
    s << std::endl;
    Printer< ::tiago_pick_demo::PickUpPoseActionGoal_<ContainerAllocator> >::stream(s, indent + "  ", v.action_goal);
    s << indent << "action_result: ";
    s << std::endl;
    Printer< ::tiago_pick_demo::PickUpPoseActionResult_<ContainerAllocator> >::stream(s, indent + "  ", v.action_result);
    s << indent << "action_feedback: ";
    s << std::endl;
    Printer< ::tiago_pick_demo::PickUpPoseActionFeedback_<ContainerAllocator> >::stream(s, indent + "  ", v.action_feedback);
  }
};

} // namespace message_operations
} // namespace ros

#endif // TIAGO_PICK_DEMO_MESSAGE_PICKUPPOSEACTION_H
