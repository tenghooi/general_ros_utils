#include "pose_tf_broadcaster.h"

PoseTransformBroadcaster::PoseTransformBroadcaster(ros::NodeHandle& node)
{   
    SetNodeParameters(node);

    pose_msg_sub_ = node.subscribe<nav_msgs::Odometry>
                                  ("odom", 10,
                                   &PoseTransformBroadcaster::PoseCallBack, this);
}

PoseTransformBroadcaster::~PoseTransformBroadcaster() { }

void PoseTransformBroadcaster::SetNodeParameters(const ros::NodeHandle& node)
{
    node.param<std::string>("frame_id", parameters_.parent_frame_id, "world");
}

void PoseTransformBroadcaster::PoseCallBack(const nav_msgs::OdometryConstPtr& pose_msg)
{
    geometry_msgs::TransformStamped transform_pose;

    transform_pose.header = pose_msg -> header;
    transform_pose.header.frame_id = parameters_.parent_frame_id;
    transform_pose.child_frame_id = pose_msg -> header.frame_id;

    transform_pose.transform.translation.x = pose_msg -> pose.pose.position.x;
    transform_pose.transform.translation.y = pose_msg -> pose.pose.position.y;
    transform_pose.transform.translation.z = pose_msg -> pose.pose.position.z;

    transform_pose.transform.rotation.w = pose_msg -> pose.pose.orientation.w;
    transform_pose.transform.rotation.x = pose_msg -> pose.pose.orientation.x;
    transform_pose.transform.rotation.y = pose_msg -> pose.pose.orientation.y;
    transform_pose.transform.rotation.z = pose_msg -> pose.pose.orientation.z;

    broadcaster.sendTransform(transform_pose);

}




