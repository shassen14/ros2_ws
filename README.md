### Summary

Product of following ROS 2 tutorials to create a workspace, packages, messages, services, etc. Found using this [link](https://docs.ros.org/en/humble/Tutorials.html) with ROS 2 humble.


Assuming one has ROS 2 installed and also colcon, use the following steps

1. run `colcon build` in the root directory of this workspace
2. open a new terminal, then run `source /opt/ros/<ros_distro>/setup.bash`
3. same terminal, run `source install/local_setup.bash` in the `ros2_ws` directory
4. then run `ros2 run <package_name> <node_name>` to use any of the simple applications
5. Use different terminals to run publisher/subscriber type of nodes

