#!/usr/bin/env python3

import rclpy
from rclpy.node import Node 
from geometry_msgs.msg import Twist
import sys

class Drawcircle(Node):
    def __init__(self):
        super().__init__("Drawcircle")
        self.cmd_vel_pub=self.create_publisher(Twist,"/turtle1/cmd_vel",10)
        self.timer=self.create_timer(0.5,self.send_velocity_command)
        self.get_logger().info("Drawing a Circle")

    def send_velocity_command(self):
        radius = float(sys.argv[1])
        if radius > 2.75 :
            self.get_logger().info("Drawing circle of given radius is not possible")
        else:
            msg=Twist()
            msg.linear.x=1.5
            msg.angular.z=(1.5)/radius
            self.cmd_vel_pub.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    node=Drawcircle()
    rclpy.spin(node)
    rclpy.shutdown()

