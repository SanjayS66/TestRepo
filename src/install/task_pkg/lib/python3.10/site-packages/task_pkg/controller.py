#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose
import sys
import curses
import math
import time

class turtlecontrol(Node):
    def __init__(self):
        super().__init__('turtlesim_controller')
        self.cmd_vel_pub = self.create_publisher(Twist, "/turtle1/cmd_vel",10)
        self.pose_sub = self.create_subscription(Pose , "/turtle1/pose",self.rotate,10)
        self.velocity_msg = Twist()

    def move_forward(self):
        self.velocity_msg.linear.x = 1.0  
        self.velocity_msg.angular.z = 0.0  
        self.cmd_vel_pub.publish(self.velocity_msg)

    def move_backward(self):
        
        self.velocity_msg.linear.x = -1.0  
        self.velocity_msg.angular.z = 0.0  
        self.cmd_vel_pub.publish(self.velocity_msg)

    def turn_left(self):
        
        self.velocity_msg.linear.x = 0.0  
        self.velocity_msg.angular.z = 1.0 
        self.cmd_vel_pub.publish(self.velocity_msg)

    def turn_right(self):
        
        self.velocity_msg.linear.x = 0.0  
        self.velocity_msg.angular.z = -1.0  
        self.cmd_vel_pub.publish(self.velocity_msg)


    def rotate(self, angle_degrees):
        angle_radians = math.radians(angle_degrees)
        
        self.velocity_msg.angular.z = 1.0  
        self.velocity_msg.linear.x= 0.0
        self.velocity_msg.linear.y=0.0
        time_required = angle_radians / abs(self.velocity_msg.angular.z)
        start_time = self.get_clock().now().seconds_nanoseconds()[0]
        while self.get_clock().now().seconds_nanoseconds()[0] - start_time < time_required:
            self.cmd_vel_pub.publish(self.velocity_msg)
        
        self.velocity_msg.angular.z = 0.0
        self.velocity_msg.linear.x= 0.0
        self.velocity_msg.linear.y=0.0
        self.cmd_vel_pub.publish(self.velocity_msg) 

     




    def stop(self):
        
        self.velocity_msg.linear.x = 0.0
        self.velocity_msg.angular.z = 0.0
        self.cmd_vel_pub.publish(self.velocity_msg)


def get_key(stdscr):
    curses.curs_set(0)    #set cursor to zero
    stdscr.nodelay(1)      
    key = stdscr.getch()  
    return key

def main(args=None):
    rclpy.init(args= None)
    control= turtlecontrol()
    

    stdscr = curses.initscr()
    while True:
            key = get_key(stdscr)  #makes a terminal window for curse 

            if key == ord('w'):  
                control.move_forward()
            elif key == ord('s'):  
                control.move_backward()
            elif key == ord('a'):  
                control.turn_left()
            elif key == ord('d'): 
                control.turn_right()
            elif key == ord('6'):  
                control.rotate(0)
            elif key == ord('9'):  
                control.rotate(45)
            elif key == ord('8'):  
                control.rotate(90)
            elif key == ord('7'):  
                control.rotate(135)
            elif key == ord('4'):  
                control.rotate(180)
            elif key == ord('1'):  
                control.rotate(225)
            elif key == ord('2'):  
                control.rotate(270)
            elif key == ord('3'):  
                control.rotate(315)

            elif key == ord('q'):  
                control.stop()
            
            
            
                break



