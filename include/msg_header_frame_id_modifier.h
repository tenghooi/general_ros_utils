#ifndef _MSG_HEADER_FRAME_ID_MODIFIER_H_
#define _MSG_HEADER_FRAME_ID_MODIFIER_H_

#include <iostream>
#include <string>

#include <nav_msgs/Odometry.h>

#include <ros/ros.h>

struct NodeParameters
{
    bool change_frame_id;
    std::string frame_id;
};

class MsgFrameIDModifier
{
private:

    NodeParameters parameters_;

    ros::Publisher msg_pub_;
    ros::Subscriber msg_sub_;

public:
    
    MsgFrameIDModifier(ros::NodeHandle& node);
    ~MsgFrameIDModifier();

    void SetNodeParameters(const ros::NodeHandle& node);

    void MsgCallBack(const nav_msgs::OdometryConstPtr& odom_msg);
};

#endif //_MSG_HEADER_FRAME_ID_MODIFIER_H_