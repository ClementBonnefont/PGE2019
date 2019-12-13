# Install script for directory: /home/pge/tiago_pge/src/gazebo_ros_pkgs/gazebo_msgs

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/pge/tiago_pge/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  
      if (NOT EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}")
        file(MAKE_DIRECTORY "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}")
      endif()
      if (NOT EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/.catkin")
        file(WRITE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/.catkin" "")
      endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/pge/tiago_pge/install/_setup_util.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/pge/tiago_pge/install" TYPE PROGRAM FILES "/home/pge/tiago_pge/build/gazebo_msgs/catkin_generated/installspace/_setup_util.py")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/pge/tiago_pge/install/env.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/pge/tiago_pge/install" TYPE PROGRAM FILES "/home/pge/tiago_pge/build/gazebo_msgs/catkin_generated/installspace/env.sh")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/pge/tiago_pge/install/setup.bash;/home/pge/tiago_pge/install/local_setup.bash")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/pge/tiago_pge/install" TYPE FILE FILES
    "/home/pge/tiago_pge/build/gazebo_msgs/catkin_generated/installspace/setup.bash"
    "/home/pge/tiago_pge/build/gazebo_msgs/catkin_generated/installspace/local_setup.bash"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/pge/tiago_pge/install/setup.sh;/home/pge/tiago_pge/install/local_setup.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/pge/tiago_pge/install" TYPE FILE FILES
    "/home/pge/tiago_pge/build/gazebo_msgs/catkin_generated/installspace/setup.sh"
    "/home/pge/tiago_pge/build/gazebo_msgs/catkin_generated/installspace/local_setup.sh"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/pge/tiago_pge/install/setup.zsh;/home/pge/tiago_pge/install/local_setup.zsh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/pge/tiago_pge/install" TYPE FILE FILES
    "/home/pge/tiago_pge/build/gazebo_msgs/catkin_generated/installspace/setup.zsh"
    "/home/pge/tiago_pge/build/gazebo_msgs/catkin_generated/installspace/local_setup.zsh"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/pge/tiago_pge/install/.rosinstall")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/pge/tiago_pge/install" TYPE FILE FILES "/home/pge/tiago_pge/build/gazebo_msgs/catkin_generated/installspace/.rosinstall")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gazebo_msgs/msg" TYPE FILE FILES
    "/home/pge/tiago_pge/src/gazebo_ros_pkgs/gazebo_msgs/msg/ContactsState.msg"
    "/home/pge/tiago_pge/src/gazebo_ros_pkgs/gazebo_msgs/msg/ContactState.msg"
    "/home/pge/tiago_pge/src/gazebo_ros_pkgs/gazebo_msgs/msg/LinkState.msg"
    "/home/pge/tiago_pge/src/gazebo_ros_pkgs/gazebo_msgs/msg/LinkStates.msg"
    "/home/pge/tiago_pge/src/gazebo_ros_pkgs/gazebo_msgs/msg/ModelState.msg"
    "/home/pge/tiago_pge/src/gazebo_ros_pkgs/gazebo_msgs/msg/ModelStates.msg"
    "/home/pge/tiago_pge/src/gazebo_ros_pkgs/gazebo_msgs/msg/ODEJointProperties.msg"
    "/home/pge/tiago_pge/src/gazebo_ros_pkgs/gazebo_msgs/msg/ODEPhysics.msg"
    "/home/pge/tiago_pge/src/gazebo_ros_pkgs/gazebo_msgs/msg/WorldState.msg"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gazebo_msgs/srv" TYPE FILE FILES
    "/home/pge/tiago_pge/src/gazebo_ros_pkgs/gazebo_msgs/srv/ApplyBodyWrench.srv"
    "/home/pge/tiago_pge/src/gazebo_ros_pkgs/gazebo_msgs/srv/DeleteModel.srv"
    "/home/pge/tiago_pge/src/gazebo_ros_pkgs/gazebo_msgs/srv/DeleteLight.srv"
    "/home/pge/tiago_pge/src/gazebo_ros_pkgs/gazebo_msgs/srv/GetLinkState.srv"
    "/home/pge/tiago_pge/src/gazebo_ros_pkgs/gazebo_msgs/srv/GetPhysicsProperties.srv"
    "/home/pge/tiago_pge/src/gazebo_ros_pkgs/gazebo_msgs/srv/SetJointProperties.srv"
    "/home/pge/tiago_pge/src/gazebo_ros_pkgs/gazebo_msgs/srv/SetModelConfiguration.srv"
    "/home/pge/tiago_pge/src/gazebo_ros_pkgs/gazebo_msgs/srv/SpawnModel.srv"
    "/home/pge/tiago_pge/src/gazebo_ros_pkgs/gazebo_msgs/srv/ApplyJointEffort.srv"
    "/home/pge/tiago_pge/src/gazebo_ros_pkgs/gazebo_msgs/srv/GetJointProperties.srv"
    "/home/pge/tiago_pge/src/gazebo_ros_pkgs/gazebo_msgs/srv/GetModelProperties.srv"
    "/home/pge/tiago_pge/src/gazebo_ros_pkgs/gazebo_msgs/srv/GetWorldProperties.srv"
    "/home/pge/tiago_pge/src/gazebo_ros_pkgs/gazebo_msgs/srv/SetLinkProperties.srv"
    "/home/pge/tiago_pge/src/gazebo_ros_pkgs/gazebo_msgs/srv/SetModelState.srv"
    "/home/pge/tiago_pge/src/gazebo_ros_pkgs/gazebo_msgs/srv/BodyRequest.srv"
    "/home/pge/tiago_pge/src/gazebo_ros_pkgs/gazebo_msgs/srv/GetLinkProperties.srv"
    "/home/pge/tiago_pge/src/gazebo_ros_pkgs/gazebo_msgs/srv/GetModelState.srv"
    "/home/pge/tiago_pge/src/gazebo_ros_pkgs/gazebo_msgs/srv/JointRequest.srv"
    "/home/pge/tiago_pge/src/gazebo_ros_pkgs/gazebo_msgs/srv/SetLinkState.srv"
    "/home/pge/tiago_pge/src/gazebo_ros_pkgs/gazebo_msgs/srv/SetPhysicsProperties.srv"
    "/home/pge/tiago_pge/src/gazebo_ros_pkgs/gazebo_msgs/srv/SetJointTrajectory.srv"
    "/home/pge/tiago_pge/src/gazebo_ros_pkgs/gazebo_msgs/srv/GetLightProperties.srv"
    "/home/pge/tiago_pge/src/gazebo_ros_pkgs/gazebo_msgs/srv/SetLightProperties.srv"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gazebo_msgs/cmake" TYPE FILE FILES "/home/pge/tiago_pge/build/gazebo_msgs/catkin_generated/installspace/gazebo_msgs-msg-paths.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/pge/tiago_pge/devel/.private/gazebo_msgs/include/gazebo_msgs")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/pge/tiago_pge/devel/.private/gazebo_msgs/share/roseus/ros/gazebo_msgs")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/pge/tiago_pge/devel/.private/gazebo_msgs/share/common-lisp/ros/gazebo_msgs")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/pge/tiago_pge/devel/.private/gazebo_msgs/share/gennodejs/ros/gazebo_msgs")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  execute_process(COMMAND "/usr/bin/python" -m compileall "/home/pge/tiago_pge/devel/.private/gazebo_msgs/lib/python2.7/dist-packages/gazebo_msgs")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/pge/tiago_pge/devel/.private/gazebo_msgs/lib/python2.7/dist-packages/gazebo_msgs")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/pge/tiago_pge/build/gazebo_msgs/catkin_generated/installspace/gazebo_msgs.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gazebo_msgs/cmake" TYPE FILE FILES "/home/pge/tiago_pge/build/gazebo_msgs/catkin_generated/installspace/gazebo_msgs-msg-extras.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gazebo_msgs/cmake" TYPE FILE FILES
    "/home/pge/tiago_pge/build/gazebo_msgs/catkin_generated/installspace/gazebo_msgsConfig.cmake"
    "/home/pge/tiago_pge/build/gazebo_msgs/catkin_generated/installspace/gazebo_msgsConfig-version.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gazebo_msgs" TYPE FILE FILES "/home/pge/tiago_pge/src/gazebo_ros_pkgs/gazebo_msgs/package.xml")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/pge/tiago_pge/build/gazebo_msgs/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
