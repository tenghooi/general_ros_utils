#include <iostream>
#include <vector>
#include <string>

#include <ros/ros.h>

#include <nav_msgs/Odometry.h>
#include <geometry_msgs/TransformStamped.h>
#include <tf2_ros/transform_broadcaster.h>

struct NodeParameters
{



};

class PoseTransformBroadcaster
{
private:

    NodeParameters parameters_;

    ros::Subscriber pose_msg_sub_;

public:

    PoseTransformBroadcaster(ros::NodeHandle& node);
    ~PoseTransformBroadcaster();

    void SetNodeParameters(const ros::NodeHandle& node);

    void PoseCallBack(const nav_msgs::OdometryConstPtr& pose_msg);
};


