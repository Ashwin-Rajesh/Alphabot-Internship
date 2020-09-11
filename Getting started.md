# Getting Started
This file documents the general procedure for starting a ROS project

---
## Creating a workspace

- Create a diretory that will serve as our workspace (here, ~/sample_dir/sample_ws), with an src folder inside
  	```
  	cd ~/sample_dir
  	mkdir -p sample_ws/src
  	```
- Go into the directory and run the command "catkin_make"
  	```
  	cd sample_ws
  	catkin_make
  	```
- Source the devel/setup.bash file to setup the workspace in the current environment
  	```
  	source devel/setup.bash
  	```
---
## Creating a package

- First, go to the source folder of the concerned workspace. The following will do this, if the workspace has been initialized
  	```
  	roscd
  	cd ../src
  	```
- Run the "catkin_create_pkg" command (Here name of package is *sample_pkg*)
  	```
	catkin_create_pkg sample_pkg sample_dependencies roscpp rospy std_msgs
	```
- Run catkin_make in the workspace 
	```
	catkin_make
	```
---
## Building and Running python scripts

- For python, there is no need to run catkin_make, or update the CMakeLists file
- Just make the script executable using the command
	```
	chmod u+x sample_script.py
	```
- Advisable to place all python scripts in a scripts folder
- Use rosrun to run the script (even if script is inside a folder, only script name is required
	```
	rosrun sample_pkg sample_script.py
	```
- The python interpreter can also be used from the command line to run the script
---
## Building and Running C++ scripts

- We have to use the CMake files for building C++ files. Here are the steps
- add genmsgs to find_package at the beginning. It will look like
	```
	find_package(catkin REQUIRED COMPONENTS
  		roscpp
  		std_msgs
  		rospy
  		genmsg
	)
	```
- Add the messages used to generate_messages() 
	```
	generate_messages(
  		DEPENDENCIES
  		std_msgs
	)
	```
- Now, add the following 3 lines to the end:
	```
	add_executable(sample_node 		src/sample_code.cpp)
	target_link_libraries(sample_node 	${catkin_LIBRARIES})
	add_dependencies(sample_node	 	sample_pkg_generate_messages_cpp)
	```
