# general_ros_utils
Utilities for ROS project

## ROS nodes in this package
### short_path_visualizer
This node takes in a nav_msgs/Odometry message and output a nav_msgs/Path message with a certain length on FIFO basis.

### full_odom_to_path_visualizer
This node is similar to short_path_visualizer but aggregate odometry and output full path history.

### msg_header_frame_id_modifier
This node takes in ROS message with header and change the frame_id to user defined frame_id. Parameters are defined in launch file.

**NOTE:** Currently only accept nav_msgs/Odometry as incoming message type but can easily change to other types of message in the code.