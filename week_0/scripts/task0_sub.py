#! /usr/bin/env python

import rospy

from std_msgs.msg import String

def on_callback(msg):
    rospy.loginfo("I heard " + msg.data)

def create_sub():
    rospy.init_node("Subscriber")
    
    sub = rospy.Subscriber("time_msg", String, on_callback)

    rospy.spin()
    
if __name__ == "__main__":
    try:
        create_sub()
    except rospy.ROSInterruptException:
        pass
