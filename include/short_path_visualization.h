#ifndef _SHORT_PATH_VISUALIZATION_H_
#define _SHORT_PATH_VISUALIZATION_H_

#include <iostream>
#include <vector>
#include <deque>
#include <string>

#include <nav_msgs/Path.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/PoseStamped.h>

#include <ros/ros.h>

struct NodeParameters
{
    int queue_length_;
};

class ShortPathVisualizer
{
private:

    NodeParameters parameters_;

    int msg_count_;
    std::deque<geometry_msgs::PoseStamped> poses_;

    ros::Publisher path_msg_pub_;
    ros::Subscriber odom_msg_sub_;

public:
    
    ShortPathVisualizer(ros::NodeHandle& node);
    ~ShortPathVisualizer();

    void SetNodeParameters(const ros::NodeHandle& node);

    void setMsgCount();
    int getMsgCount() const;

    void OdomToPath(const std::deque<geometry_msgs::PoseStamped>& poses_) const;
    void OdomCallBack(const nav_msgs::OdometryConstPtr& odom_msg);
};

#endif