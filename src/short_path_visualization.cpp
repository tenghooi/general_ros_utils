#include "short_path_visualization.h"

ShortPathVisualizer::ShortPathVisualizer(ros::NodeHandle& node)
{
    SetNodeParameters(node);

    msg_count_ = 0;

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

void ShortPathVisualizer::setMsgCount()
{
    msg_count_ += 1;
}

int ShortPathVisualizer::getMsgCount() const
{
    return msg_count_;
}

void ShortPathVisualizer::OdomToPath(const std::deque<geometry_msgs::PoseStamped>& poses_) const
{
    nav_msgs::Path path;
    
    path.header = poses_.back().header;
    


}

void ShortPathVisualizer::OdomCallBack(const nav_msgs::OdometryConstPtr& odom_msg)
{
    geometry_msgs::PoseStamped current_pose;

    current_pose.header = odom_msg->header;
    current_pose.pose = odom_msg->pose.pose;

    if (getMsgCount() <= parameters_.queue_length_)
    {
        setMsgCount();
        poses_.push_back(current_pose);
    } 
    else 
    {
        poses_.pop_front();
        poses_.push_back(current_pose);
    }

    OdomToPath(poses_);
}