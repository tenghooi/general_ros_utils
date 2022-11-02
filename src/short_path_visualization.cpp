#include "short_path_visualization.h"

ShortPathVisualizer::ShortPathVisualizer(ros::NodeHandle& node)
{

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