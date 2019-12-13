# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "pal_control_msgs: 17 messages, 1 services")

set(MSG_I_FLAGS "-Ipal_control_msgs:/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/msg;-Ipal_control_msgs:/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg;-Iactionlib_msgs:/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/kinetic/share/geometry_msgs/cmake/../msg;-Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(pal_control_msgs_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerAction.msg" NAME_WE)
add_custom_target(_pal_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "pal_control_msgs" "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerAction.msg" "std_msgs/Header:pal_control_msgs/MotionManagerGoal:pal_control_msgs/MotionManagerResult:pal_control_msgs/MotionManagerActionGoal:pal_control_msgs/MotionManagerActionResult:pal_control_msgs/MotionManagerFeedback:pal_control_msgs/MotionManagerActionFeedback:actionlib_msgs/GoalID:actionlib_msgs/GoalStatus"
)

get_filename_component(_filename "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/srv/CurrentLimit.srv" NAME_WE)
add_custom_target(_pal_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "pal_control_msgs" "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/srv/CurrentLimit.srv" ""
)

get_filename_component(_filename "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/msg/RigidBodyTrajectoryPoint.msg" NAME_WE)
add_custom_target(_pal_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "pal_control_msgs" "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/msg/RigidBodyTrajectoryPoint.msg" "geometry_msgs/Accel:geometry_msgs/Twist:geometry_msgs/Quaternion:geometry_msgs/Point:geometry_msgs/Vector3:geometry_msgs/Pose"
)

get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerActionResult.msg" NAME_WE)
add_custom_target(_pal_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "pal_control_msgs" "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerActionResult.msg" "pal_control_msgs/MotionManagerResult:actionlib_msgs/GoalID:std_msgs/Header:actionlib_msgs/GoalStatus"
)

get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryActionFeedback.msg" NAME_WE)
add_custom_target(_pal_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "pal_control_msgs" "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryActionFeedback.msg" "pal_control_msgs/RigidBodyTrajectoryFeedback:actionlib_msgs/GoalID:std_msgs/Header:actionlib_msgs/GoalStatus"
)

get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerGoal.msg" NAME_WE)
add_custom_target(_pal_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "pal_control_msgs" "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerGoal.msg" ""
)

get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryAction.msg" NAME_WE)
add_custom_target(_pal_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "pal_control_msgs" "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryAction.msg" "pal_control_msgs/RigidBodyTrajectoryActionGoal:pal_control_msgs/RigidBodyTrajectoryPoint:geometry_msgs/Pose:geometry_msgs/Twist:std_msgs/Header:geometry_msgs/Accel:geometry_msgs/Quaternion:geometry_msgs/Point:geometry_msgs/Vector3:pal_control_msgs/RigidBodyTrajectoryActionFeedback:pal_control_msgs/RigidBodyTrajectoryFeedback:pal_control_msgs/RigidBodyTrajectoryResult:pal_control_msgs/RigidBodyTrajectoryGoal:pal_control_msgs/RigidBodyTrajectoryActionResult:actionlib_msgs/GoalID:actionlib_msgs/GoalStatus"
)

get_filename_component(_filename "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/msg/OperationalSpaceGoal.msg" NAME_WE)
add_custom_target(_pal_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "pal_control_msgs" "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/msg/OperationalSpaceGoal.msg" "geometry_msgs/Quaternion:geometry_msgs/Pose:std_msgs/Header:geometry_msgs/Point"
)

get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerActionFeedback.msg" NAME_WE)
add_custom_target(_pal_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "pal_control_msgs" "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerActionFeedback.msg" "actionlib_msgs/GoalID:std_msgs/Header:pal_control_msgs/MotionManagerFeedback:actionlib_msgs/GoalStatus"
)

get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryGoal.msg" NAME_WE)
add_custom_target(_pal_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "pal_control_msgs" "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryGoal.msg" "pal_control_msgs/RigidBodyTrajectoryPoint:geometry_msgs/Pose:std_msgs/Header:geometry_msgs/Accel:geometry_msgs/Quaternion:geometry_msgs/Point:geometry_msgs/Vector3:geometry_msgs/Twist"
)

get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryActionGoal.msg" NAME_WE)
add_custom_target(_pal_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "pal_control_msgs" "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryActionGoal.msg" "pal_control_msgs/RigidBodyTrajectoryPoint:geometry_msgs/Pose:geometry_msgs/Twist:std_msgs/Header:geometry_msgs/Accel:geometry_msgs/Quaternion:geometry_msgs/Point:geometry_msgs/Vector3:pal_control_msgs/RigidBodyTrajectoryGoal:actionlib_msgs/GoalID"
)

get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerResult.msg" NAME_WE)
add_custom_target(_pal_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "pal_control_msgs" "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerResult.msg" ""
)

get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryFeedback.msg" NAME_WE)
add_custom_target(_pal_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "pal_control_msgs" "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryFeedback.msg" ""
)

get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerActionGoal.msg" NAME_WE)
add_custom_target(_pal_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "pal_control_msgs" "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerActionGoal.msg" "actionlib_msgs/GoalID:std_msgs/Header:pal_control_msgs/MotionManagerGoal"
)

get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryResult.msg" NAME_WE)
add_custom_target(_pal_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "pal_control_msgs" "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryResult.msg" ""
)

get_filename_component(_filename "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/msg/ActuatorCurrentLimit.msg" NAME_WE)
add_custom_target(_pal_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "pal_control_msgs" "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/msg/ActuatorCurrentLimit.msg" ""
)

get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerFeedback.msg" NAME_WE)
add_custom_target(_pal_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "pal_control_msgs" "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerFeedback.msg" ""
)

get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryActionResult.msg" NAME_WE)
add_custom_target(_pal_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "pal_control_msgs" "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryActionResult.msg" "actionlib_msgs/GoalID:pal_control_msgs/RigidBodyTrajectoryResult:std_msgs/Header:actionlib_msgs/GoalStatus"
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(pal_control_msgs
  "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/msg/RigidBodyTrajectoryPoint.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Accel.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_cpp(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerActionResult.msg"
  "${MSG_I_FLAGS}"
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerResult.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_cpp(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryFeedback.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_cpp(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerGoal.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_cpp(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryAction.msg"
  "${MSG_I_FLAGS}"
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryActionGoal.msg;/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/msg/RigidBodyTrajectoryPoint.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Accel.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryActionFeedback.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryFeedback.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryResult.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryGoal.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryActionResult.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_cpp(pal_control_msgs
  "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/msg/OperationalSpaceGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_cpp(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerFeedback.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_cpp(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryGoal.msg"
  "${MSG_I_FLAGS}"
  "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/msg/RigidBodyTrajectoryPoint.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Accel.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Twist.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_cpp(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/msg/RigidBodyTrajectoryPoint.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Accel.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryGoal.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_cpp(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerResult.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_cpp(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryFeedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_cpp(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerGoal.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_cpp(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryActionResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryResult.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_cpp(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryResult.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_cpp(pal_control_msgs
  "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/msg/ActuatorCurrentLimit.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_cpp(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerFeedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_cpp(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerAction.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerGoal.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerResult.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerActionGoal.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerActionResult.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerFeedback.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerActionFeedback.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/pal_control_msgs
)

### Generating Services
_generate_srv_cpp(pal_control_msgs
  "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/srv/CurrentLimit.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/pal_control_msgs
)

### Generating Module File
_generate_module_cpp(pal_control_msgs
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/pal_control_msgs
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(pal_control_msgs_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(pal_control_msgs_generate_messages pal_control_msgs_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerAction.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_cpp _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/srv/CurrentLimit.srv" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_cpp _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/msg/RigidBodyTrajectoryPoint.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_cpp _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerActionResult.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_cpp _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryActionFeedback.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_cpp _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerGoal.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_cpp _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryAction.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_cpp _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/msg/OperationalSpaceGoal.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_cpp _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerActionFeedback.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_cpp _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryGoal.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_cpp _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryActionGoal.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_cpp _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerResult.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_cpp _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryFeedback.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_cpp _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerActionGoal.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_cpp _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryResult.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_cpp _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/msg/ActuatorCurrentLimit.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_cpp _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerFeedback.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_cpp _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryActionResult.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_cpp _pal_control_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(pal_control_msgs_gencpp)
add_dependencies(pal_control_msgs_gencpp pal_control_msgs_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS pal_control_msgs_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(pal_control_msgs
  "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/msg/RigidBodyTrajectoryPoint.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Accel.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_eus(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerActionResult.msg"
  "${MSG_I_FLAGS}"
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerResult.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_eus(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryFeedback.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_eus(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerGoal.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_eus(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryAction.msg"
  "${MSG_I_FLAGS}"
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryActionGoal.msg;/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/msg/RigidBodyTrajectoryPoint.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Accel.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryActionFeedback.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryFeedback.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryResult.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryGoal.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryActionResult.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_eus(pal_control_msgs
  "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/msg/OperationalSpaceGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_eus(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerFeedback.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_eus(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryGoal.msg"
  "${MSG_I_FLAGS}"
  "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/msg/RigidBodyTrajectoryPoint.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Accel.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Twist.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_eus(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/msg/RigidBodyTrajectoryPoint.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Accel.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryGoal.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_eus(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerResult.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_eus(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryFeedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_eus(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerGoal.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_eus(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryActionResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryResult.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_eus(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryResult.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_eus(pal_control_msgs
  "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/msg/ActuatorCurrentLimit.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_eus(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerFeedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_eus(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerAction.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerGoal.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerResult.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerActionGoal.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerActionResult.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerFeedback.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerActionFeedback.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/pal_control_msgs
)

### Generating Services
_generate_srv_eus(pal_control_msgs
  "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/srv/CurrentLimit.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/pal_control_msgs
)

### Generating Module File
_generate_module_eus(pal_control_msgs
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/pal_control_msgs
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(pal_control_msgs_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(pal_control_msgs_generate_messages pal_control_msgs_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerAction.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_eus _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/srv/CurrentLimit.srv" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_eus _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/msg/RigidBodyTrajectoryPoint.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_eus _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerActionResult.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_eus _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryActionFeedback.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_eus _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerGoal.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_eus _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryAction.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_eus _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/msg/OperationalSpaceGoal.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_eus _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerActionFeedback.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_eus _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryGoal.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_eus _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryActionGoal.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_eus _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerResult.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_eus _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryFeedback.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_eus _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerActionGoal.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_eus _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryResult.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_eus _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/msg/ActuatorCurrentLimit.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_eus _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerFeedback.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_eus _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryActionResult.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_eus _pal_control_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(pal_control_msgs_geneus)
add_dependencies(pal_control_msgs_geneus pal_control_msgs_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS pal_control_msgs_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(pal_control_msgs
  "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/msg/RigidBodyTrajectoryPoint.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Accel.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_lisp(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerActionResult.msg"
  "${MSG_I_FLAGS}"
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerResult.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_lisp(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryFeedback.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_lisp(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerGoal.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_lisp(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryAction.msg"
  "${MSG_I_FLAGS}"
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryActionGoal.msg;/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/msg/RigidBodyTrajectoryPoint.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Accel.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryActionFeedback.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryFeedback.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryResult.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryGoal.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryActionResult.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_lisp(pal_control_msgs
  "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/msg/OperationalSpaceGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_lisp(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerFeedback.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_lisp(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryGoal.msg"
  "${MSG_I_FLAGS}"
  "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/msg/RigidBodyTrajectoryPoint.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Accel.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Twist.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_lisp(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/msg/RigidBodyTrajectoryPoint.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Accel.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryGoal.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_lisp(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerResult.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_lisp(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryFeedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_lisp(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerGoal.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_lisp(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryActionResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryResult.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_lisp(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryResult.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_lisp(pal_control_msgs
  "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/msg/ActuatorCurrentLimit.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_lisp(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerFeedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_lisp(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerAction.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerGoal.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerResult.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerActionGoal.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerActionResult.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerFeedback.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerActionFeedback.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/pal_control_msgs
)

### Generating Services
_generate_srv_lisp(pal_control_msgs
  "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/srv/CurrentLimit.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/pal_control_msgs
)

### Generating Module File
_generate_module_lisp(pal_control_msgs
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/pal_control_msgs
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(pal_control_msgs_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(pal_control_msgs_generate_messages pal_control_msgs_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerAction.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_lisp _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/srv/CurrentLimit.srv" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_lisp _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/msg/RigidBodyTrajectoryPoint.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_lisp _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerActionResult.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_lisp _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryActionFeedback.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_lisp _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerGoal.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_lisp _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryAction.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_lisp _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/msg/OperationalSpaceGoal.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_lisp _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerActionFeedback.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_lisp _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryGoal.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_lisp _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryActionGoal.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_lisp _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerResult.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_lisp _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryFeedback.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_lisp _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerActionGoal.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_lisp _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryResult.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_lisp _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/msg/ActuatorCurrentLimit.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_lisp _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerFeedback.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_lisp _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryActionResult.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_lisp _pal_control_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(pal_control_msgs_genlisp)
add_dependencies(pal_control_msgs_genlisp pal_control_msgs_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS pal_control_msgs_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(pal_control_msgs
  "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/msg/RigidBodyTrajectoryPoint.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Accel.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_nodejs(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerActionResult.msg"
  "${MSG_I_FLAGS}"
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerResult.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_nodejs(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryFeedback.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_nodejs(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerGoal.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_nodejs(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryAction.msg"
  "${MSG_I_FLAGS}"
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryActionGoal.msg;/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/msg/RigidBodyTrajectoryPoint.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Accel.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryActionFeedback.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryFeedback.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryResult.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryGoal.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryActionResult.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_nodejs(pal_control_msgs
  "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/msg/OperationalSpaceGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_nodejs(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerFeedback.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_nodejs(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryGoal.msg"
  "${MSG_I_FLAGS}"
  "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/msg/RigidBodyTrajectoryPoint.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Accel.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Twist.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_nodejs(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/msg/RigidBodyTrajectoryPoint.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Accel.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryGoal.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_nodejs(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerResult.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_nodejs(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryFeedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_nodejs(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerGoal.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_nodejs(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryActionResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryResult.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_nodejs(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryResult.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_nodejs(pal_control_msgs
  "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/msg/ActuatorCurrentLimit.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_nodejs(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerFeedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_nodejs(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerAction.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerGoal.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerResult.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerActionGoal.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerActionResult.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerFeedback.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerActionFeedback.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/pal_control_msgs
)

### Generating Services
_generate_srv_nodejs(pal_control_msgs
  "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/srv/CurrentLimit.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/pal_control_msgs
)

### Generating Module File
_generate_module_nodejs(pal_control_msgs
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/pal_control_msgs
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(pal_control_msgs_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(pal_control_msgs_generate_messages pal_control_msgs_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerAction.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_nodejs _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/srv/CurrentLimit.srv" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_nodejs _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/msg/RigidBodyTrajectoryPoint.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_nodejs _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerActionResult.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_nodejs _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryActionFeedback.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_nodejs _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerGoal.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_nodejs _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryAction.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_nodejs _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/msg/OperationalSpaceGoal.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_nodejs _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerActionFeedback.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_nodejs _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryGoal.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_nodejs _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryActionGoal.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_nodejs _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerResult.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_nodejs _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryFeedback.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_nodejs _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerActionGoal.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_nodejs _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryResult.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_nodejs _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/msg/ActuatorCurrentLimit.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_nodejs _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerFeedback.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_nodejs _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryActionResult.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_nodejs _pal_control_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(pal_control_msgs_gennodejs)
add_dependencies(pal_control_msgs_gennodejs pal_control_msgs_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS pal_control_msgs_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(pal_control_msgs
  "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/msg/RigidBodyTrajectoryPoint.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Accel.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_py(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerActionResult.msg"
  "${MSG_I_FLAGS}"
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerResult.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_py(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryFeedback.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_py(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerGoal.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_py(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryAction.msg"
  "${MSG_I_FLAGS}"
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryActionGoal.msg;/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/msg/RigidBodyTrajectoryPoint.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Accel.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryActionFeedback.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryFeedback.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryResult.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryGoal.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryActionResult.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_py(pal_control_msgs
  "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/msg/OperationalSpaceGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_py(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerFeedback.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_py(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryGoal.msg"
  "${MSG_I_FLAGS}"
  "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/msg/RigidBodyTrajectoryPoint.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Accel.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Twist.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_py(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/msg/RigidBodyTrajectoryPoint.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Accel.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryGoal.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_py(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerResult.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_py(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryFeedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_py(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerGoal.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_py(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryActionResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryResult.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_py(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryResult.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_py(pal_control_msgs
  "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/msg/ActuatorCurrentLimit.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_py(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerFeedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/pal_control_msgs
)
_generate_msg_py(pal_control_msgs
  "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerAction.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerGoal.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerResult.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerActionGoal.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerActionResult.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerFeedback.msg;/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerActionFeedback.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/pal_control_msgs
)

### Generating Services
_generate_srv_py(pal_control_msgs
  "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/srv/CurrentLimit.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/pal_control_msgs
)

### Generating Module File
_generate_module_py(pal_control_msgs
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/pal_control_msgs
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(pal_control_msgs_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(pal_control_msgs_generate_messages pal_control_msgs_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerAction.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_py _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/srv/CurrentLimit.srv" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_py _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/msg/RigidBodyTrajectoryPoint.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_py _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerActionResult.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_py _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryActionFeedback.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_py _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerGoal.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_py _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryAction.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_py _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/msg/OperationalSpaceGoal.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_py _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerActionFeedback.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_py _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryGoal.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_py _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryActionGoal.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_py _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerResult.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_py _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryFeedback.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_py _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerActionGoal.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_py _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryResult.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_py _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/src/pal_msgs/pal_control_msgs/msg/ActuatorCurrentLimit.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_py _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/MotionManagerFeedback.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_py _pal_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pge/tiago_pge/devel/.private/pal_control_msgs/share/pal_control_msgs/msg/RigidBodyTrajectoryActionResult.msg" NAME_WE)
add_dependencies(pal_control_msgs_generate_messages_py _pal_control_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(pal_control_msgs_genpy)
add_dependencies(pal_control_msgs_genpy pal_control_msgs_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS pal_control_msgs_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/pal_control_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/pal_control_msgs
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET actionlib_msgs_generate_messages_cpp)
  add_dependencies(pal_control_msgs_generate_messages_cpp actionlib_msgs_generate_messages_cpp)
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(pal_control_msgs_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/pal_control_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/pal_control_msgs
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET actionlib_msgs_generate_messages_eus)
  add_dependencies(pal_control_msgs_generate_messages_eus actionlib_msgs_generate_messages_eus)
endif()
if(TARGET geometry_msgs_generate_messages_eus)
  add_dependencies(pal_control_msgs_generate_messages_eus geometry_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/pal_control_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/pal_control_msgs
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET actionlib_msgs_generate_messages_lisp)
  add_dependencies(pal_control_msgs_generate_messages_lisp actionlib_msgs_generate_messages_lisp)
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(pal_control_msgs_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/pal_control_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/pal_control_msgs
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET actionlib_msgs_generate_messages_nodejs)
  add_dependencies(pal_control_msgs_generate_messages_nodejs actionlib_msgs_generate_messages_nodejs)
endif()
if(TARGET geometry_msgs_generate_messages_nodejs)
  add_dependencies(pal_control_msgs_generate_messages_nodejs geometry_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/pal_control_msgs)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/pal_control_msgs\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/pal_control_msgs
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET actionlib_msgs_generate_messages_py)
  add_dependencies(pal_control_msgs_generate_messages_py actionlib_msgs_generate_messages_py)
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(pal_control_msgs_generate_messages_py geometry_msgs_generate_messages_py)
endif()
