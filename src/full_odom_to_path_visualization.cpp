#include "full_odom_to_path_visualization.h"

FullPathVisualizer::FullPathVisualizer(ros::NodeHandle& node)
{
    poses_.reserve(500); // Preallocated for 1000 PoseStamped msgs.

    odom_msg_sub_ = node.subscribe<nav_msgs::Odometry>
                            ("laser_odom", 10, 
                             &FullPathVisualizer::OdomCallBack, this);

    path_msg_pub_ = node.advertise<nav_msgs::Path>("laser_path", 10);
}

FullPathVisualizer::~FullPathVisualizer() { }

void FullPathVisualizer::OdomToPath(const std::vector<geometry_msgs::PoseStamped>& poses_) const
{
    nav_msgs::Path path;
    
    path.header = poses_.back().header;
    path.poses = std::vector<geometry_msgs::PoseStamped> (poses_.begin(), poses_.end());

    path_msg_pub_.publish(path);
}

void FullPathVisualizer::OdomCallBack(const nav_msgs::OdometryConstPtr& odom_msg)
{
    geometry_msgs::PoseStamped current_pose;

    current_pose.header = odom_msg->header;
    current_pose.pose = odom_msg->pose.pose;

    poses_.push_back(current_pose);

    OdomToPath(poses_);
}