#include "short_path_visualization.h"

ShortPathVisualizer::ShortPathVisualizer(ros::NodeHandle& node)
{
    queue_length_ = 500;
}

ShortPathVisualizer::~ShortPathVisualizer() { }

void ShortPathVisualizer::OdomToPath()
{

}

void ShortPathVisualizer::OdomCallBack(const nav_msgs::OdometryConstPtr& odom_msg)
{
    
}