import rclpy
from rclpy.node import Node
from custom_interface.srv import Drawpoly
import sys

class draw_client(Node):
    def __init__(self):

        super().__init__("drawpolyclient")
        self.client = self.create_client(Drawpoly , "drawpoly")
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info("Service not available , Waiting ...")
    def send_request(self,a):
        request = Drawpoly.Request()
        request.a = a
        self.future = self.client.call_async(request)






def main(args = None):
    rclpy.init(args = args)
    node = draw_client()

    a= int(sys.argv[1])
    node.send_request(a)

    while rclpy.ok():
        rclpy.spin_once(node)
        response = node.future.result()
        if node.future.done():
            if response.x == int(0):
                print("Polygon drawn successfully!")
            else:
                print("Failed to draw the polygon.")
            
    rclpy.shutdown()


