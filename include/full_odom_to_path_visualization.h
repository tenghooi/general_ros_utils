#ifndef _FULL_ODOM_TO_PATH_VISUALIZATION_H_
#define _FULL_ODOM_TO_PATH_VISUALIZATION_H_

#include <iostream>
#include <vector>
#include <string>

#include <nav_msgs/Path.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/PoseStamped.h>

#include <ros/ros.h>

class FullPathVisualizer
{
private:

    std::vector<geometry_msgs::PoseStamped> poses_;

    ros::Publisher path_msg_pub_;
    ros::Subscriber odom_msg_sub_;

public:
    
    FullPathVisualizer(ros::NodeHandle& node);
    ~FullPathVisualizer();

    void SetNodeParameters(const ros::NodeHandle& node);

    void OdomToPath(const std::vector<geometry_msgs::PoseStamped>& poses_) const;
    void OdomCallBack(const nav_msgs::OdometryConstPtr& odom_msg);
};

#endif //_FULL_ODOM_TO_PATH_VISUALIZATION_