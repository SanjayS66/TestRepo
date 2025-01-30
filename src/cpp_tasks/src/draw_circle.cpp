#include "rclcpp/rclcpp.hpp"
#include <chrono>
#include <geometry_msgs/msg/twist.hpp>
#include <iostream>

class Drawcirlce : public rclcpp::Node {
    
    public:
        Drawcirlce():Node("draw_circle"){
            pub = this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel",10);
            timer = this->create_wall_timer(std::chrono::milliseconds(500),std::bind(&Drawcirlce::snd_msg, this));
            std::cout<<"Draw circle has started";
        }

        void snd_msg(){

                auto msg = geometry_msgs::msg::Twist();
                float radius = 1.5;
                msg.linear.x = 1.0;
                msg.angular.z = (msg.linear.x/radius);
                pub-> publish(msg); 

        }

    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr pub;
    rclcpp::TimerBase::SharedPtr timer ;
};

int main(int argc, char **argv) {

        rclcpp::init(argc, argv);
        rclcpp::spin(std::make_shared<Drawcirlce>());
        rclcpp::shutdown();
        return 0 ;


}

