#!/usr/bin/env python

import rospy
import roslib
import tf

from geometry_msgs.msg import PoseArray
from geometry_msgs.msg import Point

#Define a class
class Whycon_detect():

	def __init__(self):
		rospy.init_node("whycon_detection")
		self.whycon_coordinates = {}
		self.sub = rospy.Subscriber("/whycon/poses", PoseArray, self.callback)
	
	def callback(self, msg):
		for i,pos in enumerate(msg.poses):
			p = pos.position
			self.whycon_coordinates[i] = map(lambda x : round(x, 3), [p.x,p.y,p.z])
		print(self.whycon_coordinates)

if __name__=="__main__":
	marker = Whycon_detect()
	while not rospy.is_shutdown():
		rospy.spin()
