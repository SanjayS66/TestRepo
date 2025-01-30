#include "rclcpp/rclcpp.hpp"
#include <geometry_msgs/msg/twist.hpp>
#include <turtlesim/msg/pose.hpp>
#include <iostream>
#include <cmath>

class togoal : public rclcpp::Node {
public:
    togoal() : Node("goal_nav") {
        pub = this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10);
        sub = this->create_subscription<turtlesim::msg::Pose>(
            "/turtle1/pose", 10, std::bind(&togoal::pose_callback, this, std::placeholders::_1));
        do {
        std::cout << "Enter goal coordinates (x y): ";
        std::cin >> goal_x >> goal_y;
        if (goal_x > 11 || goal_y >11){

            std::cout<<"Given coordinates out of bound!!! RETRY \n";
        }
        
        }while(goal_x >11 || goal_y >11);

    }

private:
    void pose_callback(const turtlesim::msg::Pose::SharedPtr msg) {
        current_x = msg->x;
        current_y = msg->y;

        
        float distance = std::sqrt(std::pow(goal_x - current_x, 2) + std::pow(goal_y - current_y, 2));
        float angle_to_goal = std::atan2(goal_y - current_y, goal_x - current_x);


        
        geometry_msgs::msg::Twist cmd_vel;

        if (distance < 0.4)  {
            
            cmd_vel.linear.x = 0;
            cmd_vel.angular.z = 0;
            pub->publish(cmd_vel);
            RCLCPP_INFO(this->get_logger(),"Goal reached!");
            
            return;
        }

        if (std::abs(angle_to_goal - msg->theta)> 0.1){
            cmd_vel.linear.x = 0.0;
            cmd_vel.angular.z = (2.0* (angle_to_goal- msg->theta)) ; 
            pub->publish(cmd_vel);
                                                } 
        else {
            cmd_vel.linear.x = 1.0 * distance ;
            cmd_vel.angular.z = 0.0;
            pub->publish(cmd_vel);
        }
        

        }
        
    

    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr pub;
    rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr sub;

    float goal_x=0, goal_y=0;
    float current_x, current_y;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<togoal>());
    rclcpp::shutdown();
    return 0;
}
