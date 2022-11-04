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

void ShortPathVisualizer::OdomToPath()
{

}

void ShortPathVisualizer::OdomCallBack(const nav_msgs::OdometryConstPtr& odom_msg)
{
    
}