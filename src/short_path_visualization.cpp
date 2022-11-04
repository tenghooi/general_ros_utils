#include "short_path_visualization.h"

ShortPathVisualizer::ShortPathVisualizer(ros::NodeHandle& node)
{
    SetNodeParameters(node);

    odom_msg_sub_ = node.subscribe<nav_msgs::Odometry>
                            ("laser_odom", 10, 
                             &ShortPathVisualizer::OdomCallBack, this);

    path_msg_pub_ = node.advertise<nav_msgs::Path>("laser_path", 10);
}

ShortPathVisualizer::~ShortPathVisualizer() { }

void ShortPathVisualizer::SetNodeParameters(const ros::NodeHandle& node)
{
    node.param<int>("path_length", parameters_.queue_length_, 500);
}

void ShortPathVisualizer::OdomToPath(const geometry_msgs::PoseStamped& pose)
{

}

void ShortPathVisualizer::OdomCallBack(const nav_msgs::OdometryConstPtr& odom_msg)
{
    geometry_msgs::PoseStamped current_pose;

    current_pose.header = odom_msg->header;
    current_pose.pose = odom_msg->pose.pose;

    OdomToPath(current_pose);
}