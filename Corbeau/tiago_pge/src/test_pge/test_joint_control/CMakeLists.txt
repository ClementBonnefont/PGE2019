cmake_minimum_required(VERSION 2.8.3)
project(test_joint_control)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  actionlib
  control_msgs
  trajectory_msgs
)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(test_joint_control_node src/test_joint_control_node.cpp)
target_link_libraries(test_joint_control_node ${catkin_LIBRARIES})

### INSTALL ###

install(TARGETS test_joint_control_node
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
