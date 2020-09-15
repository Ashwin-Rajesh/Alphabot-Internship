# Commands

Useful terminal commands and their usage

### roscore

```roscore```

- Launches the "**ros master**", the server that is responsible for establishing communications between nodes, maintaining parameter servers, etc
- The rosmaster **has to be** launched before starting any nodes

---
### roslaunch

```roslaunch <package_name> <launch_file>```

- Runs .launch files. **.launch** files can do various things, like launching nodes,
- Automatically launches **ros master**
- [Further documentation on launch files](Launchfiles.md)

---
### rosrun

```rosrun <package_name> <executable>```

- Simply runs executables. This could be executable files inside the package source folder or binaries that have been built by catkin
