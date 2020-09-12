#include "ros/ros.h"

#include "std_msgs/String.h"

void callback(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO((*msg).data.c_str());
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "Subscriber");

    ros::NodeHandle n;
    
    ros::Subscriber sub = n.subscribe("Chatter", 10, callback);

    ros::spin();

    return 0;
}