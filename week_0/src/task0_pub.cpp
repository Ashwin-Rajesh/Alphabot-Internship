#include "ros/ros.h"

#include "std_msgs/String.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "Publisher");

    ros::NodeHandle n;

    ros::Publisher pub = n.advertise<std_msgs::String>("Chatter", 10);

    ros::Rate rate(10);

    while(ros::ok())
    {
        std_msgs::String msg;
        
        std::stringstream stream;

        stream << "Hey! The time is : ";
        stream << ros::Time::now().toSec();

        msg.data = stream.str();

        pub.publish(msg);

        ros::spinOnce();

        rate.sleep();
    }
}