cmake_minimum_required(VERSION 2.8.3)
project(robot_gripper)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  arduino_servo_control
)

catkin_package(
  CATKIN_DEPENDS roscpp std_msgs arduino_servo_control
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(gripper_node src/gripper_node.cpp)
target_link_libraries(gripper_node ${catkin_LIBRARIES} )
add_dependencies(gripper_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
