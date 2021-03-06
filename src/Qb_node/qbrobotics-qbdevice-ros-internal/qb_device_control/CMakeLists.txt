cmake_minimum_required(VERSION 3.5.1 FATAL_ERROR)
project(qb_device_control VERSION 0.11.3 LANGUAGES CXX)

# Dependency Settings
find_package(catkin REQUIRED
  COMPONENTS
    roscpp
    actionlib
    control_msgs
    controller_manager
    qb_device_hardware_interface
)

include_directories(include
  ${catkin_INCLUDE_DIRS}
)

catkin_package(
  INCLUDE_DIRS
    include
  LIBRARIES
    lib${PROJECT_NAME}
  CATKIN_DEPENDS
    roscpp
    actionlib
    control_msgs
    controller_manager
    qb_device_hardware_interface
)

# Exported libraries
add_library(lib${PROJECT_NAME}
  src/qb_device_control.cpp
)

set_target_properties(lib${PROJECT_NAME}
  PROPERTIES
    OUTPUT_NAME ${PROJECT_NAME}  # avoid "liblib" name
)

# C++ Settings
set_property(
  TARGET
    lib${PROJECT_NAME}
  PROPERTY CXX_STANDARD 14
)

set_property(
  TARGET
    lib${PROJECT_NAME}
  PROPERTY CXX_STANDARD_REQUIRED ON
)