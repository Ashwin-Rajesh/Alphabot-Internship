## Creating a workspace
---
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
