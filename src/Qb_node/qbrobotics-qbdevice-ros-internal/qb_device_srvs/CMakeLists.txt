cmake_minimum_required(VERSION 3.5.1 FATAL_ERROR)
project(qb_device_srvs VERSION 0.11.3 LANGUAGES CXX)

# Dependency Settings
find_package(catkin REQUIRED
  COMPONENTS
    std_srvs
    qb_device_msgs
    message_generation
)

add_service_files(
  DIRECTORY srv
  FILES
    GetMeasurements.srv
    RegisterDevice.srv
    SetCommands.srv
    Trigger.srv
)

generate_messages(
  DEPENDENCIES
    std_srvs
    qb_device_msgs
)

include_directories(include
  ${catkin_INCLUDE_DIRS}
)

catkin_package(
  INCLUDE_DIRS
    include
  CATKIN_DEPENDS
    std_srvs
    qb_device_msgs
    message_runtime
)