#! /usr/bin/env python

import rospy

import numpy as np

from std_msgs.msg import Float64

from sensor_msgs.msg import Image

def create_pub():
    rospy.init_node("Publisher")

    pub1 = rospy.Publisher("/rrbot/joint1_position_controller/command", Float64, queue_size=10)
    pub2 = rospy.Publisher("/rrbot/joint2_position_controller/command", Float64, queue_size=10)

    rate = rospy.Rate(5)

    while(not rospy.is_shutdown()):
        time = rospy.get_time()

        # pos of joints is varied with time, just for fun
        joint1_pos = (time*0.01)%2*np.pi + np.pi
        joint2_pos = (time*0.1)%2*np.pi + np.pi

        msg1 = Float64(joint1_pos)
        msg2 = Float64(joint2_pos) 

        pub1.publish(msg1)
        pub2.publish(msg2)

        rate.sleep()

if __name__ == "__main__":
    try:
        create_pub()
    except rospy.ROSInterruptException:
        cv2.destroyAllWindows() 