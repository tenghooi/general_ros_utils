#ifndef _SHORT_PATH_VISUALIZATION_H_
#define _SHORT_PATH_VISUALIZATION_H_

#include <iostream>
#include <vector>
#include <queue>
#include <string>

#include <nav_msgs/Path.h>
#include <nav_msgs/Odometry.h>

#include <ros/ros.h>

class ShortPathVisualizer
{
private:

    uint16_t queue_length_;

    ros::Publisher path_msg_Pub_;
    ros::Subscriber odom_msg_sub_;

public:
    
    ShortPathVisualizer(ros::NodeHandle& node);
    ~ShortPathVisualizer();

    void OdomToPath();
    void OdomCallBack(const nav_msgs::OdometryConstPtr& odom_msg);
};

#endif