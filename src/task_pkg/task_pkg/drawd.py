#!/usr/bin/env python3

import rclpy
from rclpy.node import Node 
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose 
import sys
import math
import time

class drawd(Node):
    
    def __init__(self):
        super().__init__("DrawD")
        self.cmd_vel_pub = self.create_publisher(Twist,"/turtle1/cmd_vel",10)
        self.pose_sub = self.create_subscription(Pose , "/turtle1/pose",self.update_pose,10)
        self.get_logger().info("Drawing a D")
        pose = Pose
        self.start_x = pose.x
        self.start_y = pose.y
        self.drawd()
    

    def update_pose(self, pose: Pose):
        self.current_pose = pose
        if self.start_x is None and self.start_y is None:
            self.start_x = pose.x
            self.start_y = pose.y

    def drawd(self):
        msg = Twist()
        
        self.draw_semic()
        x= math.pi/2
        self.rotate_turtle(x)
        duration_l = (2*self.radius)/(self.linear_speed)
        start_time_l= self.get_clock().now()
        while (self.get_clock().now() - start_time_l).nanoseconds < (duration_l*1e9):
            msg.linear.x = 1.0
            self.cmd_vel_pub.publish(msg)
        
        msg.linear.x=0.0
        self.cmd_vel_pub.publish(msg)


        
        self.get_logger().info("Finished drawing D")


    def draw_semic(self):

        msg = Twist()
        self.radius = 1.5
        self.linear_speed = 1.0
        angular_speed = (self.linear_speed/self.radius)
        duration = math.pi/angular_speed
        start_time_1= self.get_clock().now()
        duration = math.pi / angular_speed
        while (self.get_clock().now() - start_time_1).nanoseconds < (duration*1e9):
            msg.angular.z=angular_speed
            msg.linear.x=self.linear_speed
            self.cmd_vel_pub.publish(msg)
            time.sleep(0.1) 

        msg.angular.z=0.0
        msg.linear.x=0.0
        self.cmd_vel_pub.publish(msg)




    def rotate_turtle(self, angle):
        msg = Twist()
        angular_speed = 1.0  
        duration = angle / angular_speed  
        start_time = self.get_clock().now()

        
        while (self.get_clock().now() - start_time).nanoseconds < (duration * 1e9):
            msg.angular.z = angular_speed  
            msg.linear.x = 0.0
            self.cmd_vel_pub.publish(msg)
            time.sleep(0.1)

        
        msg.angular.z = 0.0
        self.cmd_vel_pub.publish(msg)




        

def main(args = None):

    rclpy.init(args=args)
    node= drawd()
    rclpy.spin(node)
    rclpy.shutdown()
