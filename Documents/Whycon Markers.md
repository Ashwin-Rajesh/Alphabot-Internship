# Whycon markers
	
Whycon is a type of vision-based [localisation](https://en.wikipedia.org/wiki/Robot_navigation) system. The objective of localisation is to obtain the position of an entity in its environment. There are two types of localisation systems : internal and external. Internal localisation systems use information form on-board sensors, like IMUs, LIDARs and cameras. [SLAM](https://en.wikipedia.org/wiki/Simultaneous_localization_and_mapping) techniques are internal localisation systems. External localisation systems use external references for calculating position. The most common external localisation system is GPS.

Whycon is an external localisation system. It uses black and white roundels as markers. The position of these markers are detected, and using the known dimensions of these markers, their position relative to the camera is computed. 

---

## References

1. [Github repository for ROS implementation of Whycon](https://github.com/lrse/whycon)
2. [T. Krajník, M. Nitsche et al.: External localization system for mobile robotics. International Conference on Advanced Robotics (ICAR), 2013](http://raw.githubusercontent.com/wiki/gestom/WhyCon/papers/2013_icar_whycon.pdf)
