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
    node.param<bool>("new_parent_frame", parameters_.new_parent_frame, "false");
    node.param<std::string>("parent_frame_id", parameters_.parent_frame_id, "world");

    node.param<bool>("new_child_frame", parameters_.new_child_frame, "false");
    node.param<std::string>("child_frame_id", parameters_.child_frame_id, "odom");

    node.param<bool>("pose_is_fixed", parameters_.pose_is_fixed, "true");

    node.param<double>("fix_translation_x", parameters_.fix_translation_x, 0.0);
    node.param<double>("fix_translation_y", parameters_.fix_translation_y, 0.0);
    node.param<double>("fix_translation_z", parameters_.fix_translation_z, 0.0);
    node.param<double>("fix_rotation_x", parameters_.fix_rotation_x, 0.0);
    node.param<double>("fix_rotation_y", parameters_.fix_rotation_y, 0.0);
    node.param<double>("fix_rotation_z", parameters_.fix_rotation_z, 0.0);
    node.param<double>("fix_rotation_w", parameters_.fix_rotation_w, 1.0);
}

void PoseTransformBroadcaster::PoseCallBack(const nav_msgs::OdometryConstPtr& pose_msg)
{
    geometry_msgs::TransformStamped transform_pose;

    transform_pose.header = pose_msg -> header;
    transform_pose.child_frame_id = pose_msg -> child_frame_id;

    if (parameters_.new_parent_frame)
    {
        transform_pose.header.frame_id = parameters_.parent_frame_id;
    }

    if (parameters_.new_child_frame)
    {
        transform_pose.child_frame_id = parameters_.child_frame_id;
    }

    if (parameters_.pose_is_fixed)
    {
        transform_pose.transform.translation.x = parameters_.fix_translation_x;
        transform_pose.transform.translation.y = parameters_.fix_translation_y;
        transform_pose.transform.translation.z = parameters_.fix_translation_z;

        transform_pose.transform.rotation.w = parameters_.fix_rotation_w;
        transform_pose.transform.rotation.x = parameters_.fix_rotation_x;
        transform_pose.transform.rotation.y = parameters_.fix_rotation_y;
        transform_pose.transform.rotation.z = parameters_.fix_rotation_z;
    }
    else
    {
        transform_pose.transform.translation.x = pose_msg -> pose.pose.position.x;
        transform_pose.transform.translation.y = pose_msg -> pose.pose.position.y;
        transform_pose.transform.translation.z = pose_msg -> pose.pose.position.z;

        transform_pose.transform.rotation.w = pose_msg -> pose.pose.orientation.w;
        transform_pose.transform.rotation.x = pose_msg -> pose.pose.orientation.x;
        transform_pose.transform.rotation.y = pose_msg -> pose.pose.orientation.y;
        transform_pose.transform.rotation.z = pose_msg -> pose.pose.orientation.z;
    }
    
    broadcaster.sendTransform(transform_pose);

}




