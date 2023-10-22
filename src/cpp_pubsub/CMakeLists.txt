cmake_minimum_required(VERSION 3.8)
project(cpp_pubsub)

# Default to C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(tutorial_interfaces REQUIRED)  # For custom messages

# Create executable and able to run via ros2 run
add_executable(talker src/publisher_member_function.cpp)
ament_target_dependencies(talker rclcpp std_msgs)

add_executable(listener src/subscriber_member_function.cpp)
ament_target_dependencies(listener rclcpp std_msgs)

# Extra files for the custom message/service step
add_executable(talker_custom src/publisher_custom_message.cpp)
ament_target_dependencies(talker_custom rclcpp tutorial_interfaces)

add_executable(listener_custom src/subscriber_custom_message.cpp)
ament_target_dependencies(listener_custom rclcpp tutorial_interfaces)

add_executable(talker_custom2 src/publisher_custom_message2.cpp)
ament_target_dependencies(talker_custom2 rclcpp tutorial_interfaces)

add_executable(listener_custom2 src/subscriber_custom_message2.cpp)
ament_target_dependencies(listener_custom2 rclcpp tutorial_interfaces)

# install in lib directory so ros2 run can find the executable
install(TARGETS
  talker
  listener
  talker_custom
  listener_custom
  talker_custom2
  listener_custom2
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
