#include <ros/ros.h>

#include <geometry_msgs/PoseArray.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Pose.h>

class detect_whycon{
private:
    ros::NodeHandle n;
    ros::Subscriber s;
    geometry_msgs::Pose poses[4];

    void callback(const geometry_msgs::PoseArray::ConstPtr& msg)
    {
        for(int i = 0; i < 4; i++)
            poses[i] = msg->poses.at(i);

        std::stringstream ss;

        for(int i = 0; i < 4; i++)
        {
            std::cout << i << " : " << "{" << poses[i].position.x << "," << poses[i].position.y << "," << poses[i].position.z << "}"<<std::endl;
        }
        std::cout << std::endl;
    }

public:
    detect_whycon(){
        n = ros::NodeHandle("whycon_detection");

        s = n.subscribe("/whycon/poses", 10, &detect_whycon::callback, this);
    }
};

int main(int argc, char** argv)
{
    ros::init(argc, argv, "whycon_detection");
    detect_whycon detector = detect_whycon();
    ros::spin();
}