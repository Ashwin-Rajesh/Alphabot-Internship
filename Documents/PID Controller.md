# PID control
PID Controllers, are in control systems lingo, a closed loop control system. The objective of [control systems](https://en.wikipedia.org/wiki/Control_system) are 
to vary the output and/or the behavior of a system, according to our needs. This could be vaying the termerature using an air conditioner to a particular temperature, 
to moving an aircraft in a certain way, or moving the joint on a robotic arm to a certain position. As you can imagine, control systems are used everywhere in engineering,
and are really important in robotics.

### What are closed loop controllers?
  Closed loop controllers take feedback from the output of the system. They use the error of the actual output from the required output, to control whatever we want to
  control. This is in contrast to open loop controllers that give inputs to the system that does not depend on the actual output of that system. Open loop controllers
  do not have any idea of the actual output, so often they act in a pre-programmed way, and cannot respond to dynamic situations. This makes the more complicated closed loop controllers
  much more preferred.
  
  ![Nighttime driving](/Images/PID Controller/open_closed_controllers.png)
