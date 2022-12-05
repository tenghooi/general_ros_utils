#ifndef _MSG_HEADER_FRAME_ID_MODIFIER_H_
#define _MSG_HEADER_FRAME_ID_MODIFIER_H_

#include <iostream>
#include <string>

#include <nav_msgs/Odometry.h>

#include <ros/ros.h>

struct NodeParameters
{
    std::string frame_id;
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

#endif //_MSG_HEADER_FRAME_ID_MODIFIER_H_