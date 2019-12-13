execute_process(COMMAND "/home/pge/tiago_pge/build/rqt_controller_manager/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/pge/tiago_pge/build/rqt_controller_manager/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
