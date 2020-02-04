SET(execName ZED_Project)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(${execName})
 
if(COMMAND cmake_policy)
    cmake_policy(SET CMP0003 OLD)
    cmake_policy(SET CMP0015 OLD)
endif(COMMAND cmake_policy)
 
SET(EXECUTABLE_OUTPUT_PATH ".")
 
SET(VERSION_REQ_CUDA "8.0")
 
IF(WIN32) # Windows
    if (CMAKE_CL_64) 
        SET(ZED_INCLUDE_DIRS $ENV{ZED_INCLUDE_DIRS})
        SET(ZED_LIBRARIES $ENV{ZED_LIBRARIES_64})
        SET(ZED_LIBRARY_DIR $ENV{ZED_LIBRARY_DIR})
    else()
        message(FATAL_ERROR "You've selected the 32bit version of ${CMAKE_GENERATOR}. \n Please delete the cache (file->Delete Cache) and use the 64bit version. (${CMAKE_GENERATOR} Win64)")
    endif()
ELSE() # Linux
    find_package(ZED 2 REQUIRED)
    SET(SPECIAL_OS_LIBS "pthread")
ENDIF(WIN32)
 
find_package(CUDA ${VERSION_REQ_CUDA} REQUIRED)
  
include_directories(${CUDA_INCLUDE_DIRS})
include_directories(${ZED_INCLUDE_DIRS})
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

find_package( OpenCV REQUIRED )
if( OpenCV_FOUND )
list( APPEND ThirdParty_LIBS ${OpenCV_LIBS} )
    include_directories( ${OpenCV_INCLUDE_DIRS} )
endif( OpenCV_FOUND )

link_directories(${ZED_LIBRARY_DIR})
link_directories(${CUDA_LIBRARY_DIRS})
 
SET(SRC_FOLDER src)
FILE(GLOB_RECURSE SRC_FILES "${SRC_FOLDER}/*.cpp")  
ADD_EXECUTABLE(${execName} ${SRC_FILES})
 
add_definitions(-std=c++0x -g -O3)

# Add the required libraries for linking:
TARGET_LINK_LIBRARIES(${execName}
                        ${ZED_LIBRARIES}
                        ${SPECIAL_OS_LIBS}
                        ${CUDA_LIBRARIES}
			${CUDA_npps_LIBRARY}
			${CUDA_nppi_LIBRARY}
			${OpenCV_LIBS}
)

