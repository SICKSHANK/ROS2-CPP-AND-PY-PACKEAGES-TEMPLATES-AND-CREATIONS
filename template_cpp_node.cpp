#include "rclcpp/rclcpp.hpp"

class MyCustomNode : public rclcpp::Node // MODIFY NAME
{
public:
    MyCustomNode() : Node("cpp_test")
    {
    
    }
private:
    
};

int main(int argc, char **argv)
{ 
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MyCustomNode>();  // MODIFY NAME
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
    }