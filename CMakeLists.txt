cmake_minimum_required(VERSION 2.8.3)
project(goal_publisher)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  tf
)

catkin_package()

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)


add_executable(goal_pub 
  src/goal_publisher.cpp
  # src/shape_pub.cpp
  # src/Visualize_test.cpp
)
target_link_libraries(goal_pub ${catkin_LIBRARIES})
add_dependencies(goal_pub ros_demo_generate_messages_cpp)