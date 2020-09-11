# Getting Started
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
- Run the "catkin_create_pkg" command
  	```
	catkin_create_pkg sample_pkg sample_dependencies roscpp rospy std_msgs
	```
- Run catkin_make in the workspace 
	```
	catkin_make
	```
## Building and Running python scripts

- For python, there is no need to run catkin_make
- Just make the script executable using the command
	```
	chmod u+x sample_script.py
	```
- Advisable to place all python scripts in a scripts folder
