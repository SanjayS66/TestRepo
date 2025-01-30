#!/usr/bin/env python3

import rclpy
from rclpy.node import Node 
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose 
import sys
import math

class togoal(Node):
    
    def __init__(self):
        super().__init__("togoal")
        self.cmd_vel_pub = self.create_publisher(Twist,"/turtle1/cmd_vel",10)
        self.pose_sub= self.create_subscription(Pose,"/turtle1/pose",self.go_to_goal,10)
        self.goal = Pose()
        
        while True:

            self.goal.x = float(input("Enter x : "))
            self.goal.y = float(input("Enter y : "))
            if (self.goal.x > 11 or self.goal.y >11):
                self.get_logger().info("Given point is out of bound !!! Retry")
            else :
                break
        
        
        self.dist_tolerence = 0.5
        self.angle_tolerence = 0.1
    
    def go_to_goal(self,pose: Pose):

        new_vel = Twist()
        dist_to_goal = math.sqrt((self.goal.x-pose.x)**2 + (self.goal.y - pose.y)**2)
        ang_to_goal = math.atan2((self.goal.y-pose.y),(self.goal.x-pose.x))
        ang_diff= ang_to_goal - pose.theta

        if dist_to_goal< self.dist_tolerence:
            self.get_logger().info("Goal reached!")
            stop_msg = Twist()
            self.cmd_vel_pub.publish(stop_msg) 
            rclpy.shutdown()
            return

        if abs(ang_diff) > self.angle_tolerence:
            new_vel.angular.z = 2.0 * ang_diff  
            new_vel.linear.x = 0.0  
        else:
            new_vel.linear.x = 1.0 * dist_to_goal  
            new_vel.angular.z = 0.0 
        self.cmd_vel_pub.publish(new_vel)

def main(args = None):
    rclpy.init(args=args)
    node= togoal()
    rclpy.spin(node)
    rclpy.shutdown()
