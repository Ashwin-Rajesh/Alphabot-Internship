#define cpi 3.14

#include "ros/ros.h"

#include "cmath"

#include "std_msgs/Float64.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "Publisher");

    ros::NodeHandle n;

    ros::Publisher pub1 = n.advertise<std_msgs::Float64>("/rrbot/joint1_position_controller/command", 10);
    ros::Publisher pub2 = n.advertise<std_msgs::Float64>("/rrbot/joint2_position_controller/command", 10);

    ros::Rate rate(5);

    while(ros::ok())
    {
        std_msgs::Float64 msg1, msg2;
        
        double time = ros::Time::now().toSec();
        
        msg1.data = std::fmod(0.01*time,(2*cpi))+cpi;
        msg2.data = std::fmod(0.1*time,(2*cpi))+cpi;

        pub1.publish(msg1);
        pub2.publish(msg2);

        ros::spinOnce();

        rate.sleep();
    }
}