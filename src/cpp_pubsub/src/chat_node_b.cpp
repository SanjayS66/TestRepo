#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <iostream>
#include <thread>
#include <mutex>



class ChatNode2 : public rclcpp::Node{
    public:
        ChatNode2():Node("chat_node_b"){
        pub = this->create_publisher<std_msgs::msg::String>("chat_1_to_2", 10);
        sub = this->create_subscription<std_msgs::msg::String>(
            "chat_2_to_1", 10, std::bind(&ChatNode2::receive_CallBack, this, std::placeholders::_1));
        
        input_thread = std::thread(&ChatNode2::handleUser_Input, this);
         }

        
    ~ChatNode2() {
        if (input_thread.joinable()) {
            input_thread.join(); 
        }
    }



    private:
        
        void handleUser_Input(){
        while (rclcpp::ok()){
            std::string input;
            std::cout<<"Send [NODE B] Enter your message :";
            std::getline(std::cin,input);

            if(!input.empty()){
                std::lock_guard<std::mutex> lock(mutex_);
                auto msg = std_msgs::msg::String();
                msg.data = input ;
                pub->publish(msg);
                
                
            }
        }
        
        }
    

        void receive_CallBack(const std_msgs::msg::String::SharedPtr msg){
    
      
            std::cout <<"\nReceived [Node A]: "<< msg->data << std::endl;
            
            }


            
    


        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub;
        std::thread input_thread;
        std::mutex mutex_ ;

    

};

int main(int argc,char **argv){

    rclcpp::init(argc,argv);
    rclcpp::spin(std::make_shared<ChatNode2>());
    rclcpp::shutdown();
    return 0 ;
}