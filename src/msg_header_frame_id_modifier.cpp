#include "msg_header_frame_id_modifier.h"

MsgFrameIDModifier::MsgFrameIDModifier(ros::NodeHandle& node)
{
    SetNodeParameters(node);

    msg_pub_ = node.advertise<nav_msgs::Odometry>("pub_msg", 10);

    msg_sub_ = node.subscribe<nav_msgs::Odometry>
                            ("sub_msg", 10, 
                             &MsgFrameIDModifier::MsgCallBack, this);
}

MsgFrameIDModifier::~MsgFrameIDModifier() { }

void MsgFrameIDModifier::SetNodeParameters(const ros::NodeHandle& node)
{
    node.param<bool>("change_frame_id", parameters_.change_frame_id, false);
    node.param<std::string>("frame_id", parameters_.frame_id, "world");
}

void MsgFrameIDModifier::MsgCallBack(const nav_msgs::OdometryConstPtr& odom_msg)
{
    nav_msgs::Odometry new_odom_msg;

    new_odom_msg.header = odom_msg->header;
    new_odom_msg.child_frame_id = odom_msg->child_frame_id;
    new_odom_msg.pose = odom_msg->pose;
    new_odom_msg.twist = odom_msg->twist;

    if (parameters_.change_frame_id)
    {
        new_odom_msg.header.frame_id = parameters_.frame_id;

        msg_pub_.publish(new_odom_msg);
    }
    else
    {
        ROS_ERROR_STREAM("Param specifies no CHANGE of frame_id!");
        ROS_ERROR_STREAM("Shutting down node...");

        ros::shutdown();
    }
}