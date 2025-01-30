import rclpy
from rclpy.node import Node
from custom_interface.srv import Drawpoly
from geometry_msgs.msg import Twist
import math

class draw_service(Node):

    def __init__(self):
        super().__init__("drawpolyservie")
        self.service = self.create_service(Drawpoly , "drawpoly", self.drawpoly_callback)
        self.cmd_vel_pub = self.create_publisher(Twist,"/turtle1/cmd_vel",10)
    def drawpoly_callback(self,request,response):
        msg = Twist()
        angle_deg= 360/ request.a
        angle_rad = (angle_deg/360)*(2*math.pi)
        side_length = 2.2

        self.get_logger().info(f"Drawing a polygon of side {request.a}")

        if request.a < 3:
            self.get_logger().info("Polygon must have minimum three side !!!")
            rclpy.shutdown()

        
        
        for i in range(request.a):
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
        response.x = int(0)
        self.get_logger().info("Finished drawing the polygon.")
        return response




def main(args = None):
    rclpy.init(args = args)
    node = draw_service()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()