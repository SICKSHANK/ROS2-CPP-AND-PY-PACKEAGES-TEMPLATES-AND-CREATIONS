basic code with spin
#include "rclcpp/rclcpp.hpp"

int main(int argc, char **argv)
{ 
    rclcpp::init(argc, argv);
    auto node = std::make_shared<rclcpp::Node>("cpp_test");
    RCLCPP_INFO(node->get_logger(), "Hello, ROS2!");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
    }

    basic code without spin
#include "rclcpp/rclcpp.hpp"

int main(int argc, char **argv)
{ 
    rclcpp::init(argc, argv);
    auto node = std::make_shared<rclcpp::Node>("cpp_test");
    RCLCPP_INFO(node->get_logger(), "Hello, ROS2!");
    rclcpp::shutdown();
    return 0;
    }



this is one is with the timer and counters

#include "rclcpp/rclcpp.hpp"

class MyNode : public rclcpp::Node
{
public:
    MyNode() : Node("cpp_test")
    {
        RCLCPP_INFO(this->get_logger(), "Hello, ROS2!");
        timer_= this ->create_wall_timer(std::chrono::seconds(1), 
                                         std::bind(&MyNode::timer_callback, this));
    }
private:
    Void timer_callback()
    {
        RCLCPP_INFO(this->get_logger(), "Hello");
        counter_++;
    }
      rclpp ::TimerBase::SharedPtr timer_;
      int counter_ ;
        
    // You can add publishers, subscribers, timers, etc. here
};

int main(int argc, char **argv)
{ 
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MyNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
    }


    THIS IS THE CMAKE ONE 

    cmake_minimum_required(VERSION 3.8)
project(my_cpp_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

add_executable(cpp_node src/my_first_node.cpp)
ament_target_dependencies(cpp_node rclcpp)

install(TARGETS
  cpp_node
  DESTINATION lib/${PROJECT_NAME}
  )

ament_package()

WHICH HAS EXECUTABLENAME Node 


also the terminal code to check the frequency and bandwidth of the iterative execution of main file in another terminal is $; ros2 topic hz /number (topic name))
