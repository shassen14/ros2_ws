#include <functional>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "tutorial_interfaces/msg/sphere.hpp"                                       // CHANGE

using std::placeholders::_1;

class MinimalSubscriber : public rclcpp::Node
{
public:
  MinimalSubscriber()
  : Node("minimal_subscriber")
  {
    subscription_ = this->create_subscription<tutorial_interfaces::msg::Sphere>(    // CHANGE
      "topic", 10, std::bind(&MinimalSubscriber::topic_callback, this, _1));
  }

private:
  void topic_callback(const tutorial_interfaces::msg::Sphere & msg) const  // CHANGE
  {
    RCLCPP_INFO_STREAM(this->get_logger(), "I heard Center: {" << msg.center.x << ", " << 
                       msg.center.y << ", " << msg.center.z << "} Radius: " << msg.radius);    // CHANGE
  }
  rclcpp::Subscription<tutorial_interfaces::msg::Sphere>::SharedPtr subscription_;  // CHANGE
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}