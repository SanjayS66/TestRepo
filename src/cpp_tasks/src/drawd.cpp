#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "turtlesim/msg/pose.hpp"
#include <cmath>
#include <chrono>

class DrawD : public rclcpp::Node {
public:
    DrawD() : Node("DrawD") {
        cmd_vel_pub = this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10);
        pose_sub = this->create_subscription<turtlesim::msg::Pose>(
            "/turtle1/pose", 10, std::bind(&DrawD::update_pose, this, std::placeholders::_1));
        
        RCLCPP_INFO(this->get_logger(), "Drawing a D");
        
        start_x = 0.0;
        start_y = 0.0;

        drawD();
    }

private:
    void update_pose(const turtlesim::msg::Pose::SharedPtr pose) {
        current_pose = *pose;
        if (start_x == 0.0 && start_y == 0.0) {
            start_x = current_pose.x;
            start_y = current_pose.y;
        }
    }

    void drawD() {
        geometry_msgs::msg::Twist msg;

       
        draw_semicircle();

        
        double angle = M_PI / 2;
        rotate_turtle(angle);

        
        double duration = (2 * radius) / linear_speed;
        auto start_time = this->now();

        while ((this->now() - start_time).seconds() < duration) {
            msg.linear.x = linear_speed;
            cmd_vel_pub->publish(msg);
        }

        
        msg.linear.x = 0.0;
        cmd_vel_pub->publish(msg);

        RCLCPP_INFO(this->get_logger(), "Finished drawing D");
    }

    void draw_semicircle() {
        geometry_msgs::msg::Twist msg;

        radius = 1.5;
        linear_speed = 1.0;
        double angular_speed = linear_speed / radius;
        double duration = M_PI / angular_speed;
        auto start_time = this->now();

        while ((this->now() - start_time).seconds() < duration) {
            msg.angular.z = angular_speed;
            msg.linear.x = linear_speed;
            cmd_vel_pub->publish(msg);

            
            rclcpp::sleep_for(std::chrono::milliseconds(100));
        }

        
        msg.angular.z = 0.0;
        msg.linear.x = 0.0;
        cmd_vel_pub->publish(msg);
    }

    void rotate_turtle(double angle) {
        geometry_msgs::msg::Twist msg;

        double angular_speed = 1.0;  
        double duration = angle / angular_speed;
        auto start_time = this->now();

        while ((this->now() - start_time).seconds() < duration) {
            msg.angular.z = angular_speed;
            msg.linear.x = 0.0;
            cmd_vel_pub->publish(msg);

            
            rclcpp::sleep_for(std::chrono::milliseconds(100));
        }

        
        msg.angular.z = 0.0;
        cmd_vel_pub->publish(msg);
    }

    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_pub;
    rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr pose_sub;

    turtlesim::msg::Pose current_pose;

    double start_x, start_y;
    double radius;
    double linear_speed;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<DrawD>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
