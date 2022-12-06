#include "pose_tf_broadcaster.h"

PoseTransformBroadcaster::PoseTransformBroadcaster(ros::NodeHandle& node)
{
    pose_msg_sub_ = node.subscribe<nav_msgs::Odometry>
                                  ("odom", 10,
                                   &PoseTransformBroadcaster::PoseCallBack, this);
}

PoseTransformBroadcaster::~PoseTransformBroadcaster() { }

void PoseTransformBroadcaster::SetNodeParameters(const ros::NodeHandle& node)
{

}

void PoseTransformBroadcaster::PoseCallBack(const nav_msgs::OdometryConstPtr& pose_msg)
{

}




