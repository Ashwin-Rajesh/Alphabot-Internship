# Mapping

How do perform mapping using gmapping?

This is documenting the mapping done during eyantra 2020

1.  Launch the gazebo simulation and rviz visualisation. This depends on the robot and package you are working on.
2. Find the base frame. Enable tf display in rviz, and find the base link of the robot. This can also be done using ```rosrun rviz view_frames``` which will output a 'frames.pdf' file showing the tf tree heirarchy. Find the robot's base frame. For be, it was ebot_base
3. Use rostopic info and rqt_graph to find the laser(LIDAR) data topic. For be, it was /ebot/laser/scan. It will have the data type sensor_msgs/LaserScan
3. Create a parameter in the gmapping namespace to indicate the base frame of the robot. ```rosparam set /slam_gmapping/base_frame ebot_base```
4. Launch gmapping node ```rosrun gmapping slam_gmapping scan:=/ebot/laser/scan```. i.e, remap the scan topic to the actual laser sccan topic we use.
5. Add a map display in rviz with the topic ```/map```
6. Drive the robot around using some teleop interface.
7. The gray area in the map is the free space found by drawing straight lines from the robot to the obstacle points (black areas). Drive the robot around to fill in the required epmpty areas with gray.
8. Move into an appropriate folder to save the map. Then, run ```rosrun map_server map_saver -f sample_map```.
