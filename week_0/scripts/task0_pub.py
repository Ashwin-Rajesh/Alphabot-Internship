#! /usr/bin/env python

import rospy

from std_msgs.msg import String

from sensor_msgs.msg import Image

def create_pub():
    rospy.init_node("Publisher")

    pub = rospy.Publisher("time_msg", String, queue_size=10)

    rate = rospy.Rate(10)

    while(not rospy.is_shutdown()):
        msg = str(rospy.get_time())
        
        rospy.loginfo("I told "+msg) 

        pub.publish(msg)

        rate.sleep()

if __name__ == "__main__":
    try:
        create_pub()
    except rospy.ROSInterruptException:
        cv2.destroyAllWindows() 