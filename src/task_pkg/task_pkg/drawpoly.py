#!/usr/bin/env python3

import rclpy
from rclpy.node import Node 
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose 
import sys
import math

class drawpoly(Node):
    
    def __init__(self):
        super().__init__("Drawpolygon")
        self.cmd_vel_pub = self.create_publisher(Twist,"/turtle1/cmd_vel",10)
        self.side = int(sys.argv[1])

        if self.side  < 3:
            self.get_logger().info("Polygon must have minimum three side !!!")

        self.get_logger().info("Drawing a polygon")
        self.drawPoly()
    
  
    def drawPoly(self):

        msg = Twist()
        angle_deg= 360/ self.side
        angle_rad = (angle_deg/360)*(2*math.pi)
        side_length = 2.2

        
        
        for i in range(self.side):
            start_time_1= self.get_clock().now()
            while (self.get_clock().now() - start_time_1).nanoseconds < (side_length * 1e9):
                msg.linear.x = 1.0
                self.cmd_vel_pub.publish(msg)
            
            msg.linear.x = 0.0
            self.cmd_vel_pub.publish(msg)
                
            start_time_1= self.get_clock().now()
            while (self.get_clock().now() - start_time_1).nanoseconds < (angle_rad*1e9):
                msg.angular.z=1.0
                self.cmd_vel_pub.publish(msg)
            
            msg.angular.z=0.0
            self.cmd_vel_pub.publish(msg)
            
            
        msg.linear.x = 0.0
        msg.angular.z=0.0
        self.cmd_vel_pub.publish(msg)
        self.get_logger().info("Finished drawing the polygon.")





        

def main(args = None):
    rclpy.init(args=args)
    node= drawpoly()
    rclpy.spin(node)
    rclpy.shutdown()
