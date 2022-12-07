#include <iostream>
#include <vector>
#include <string>

#include <ros/ros.h>

#include <nav_msgs/Odometry.h>
#include <geometry_msgs/TransformStamped.h>
#include <tf2_ros/transform_broadcaster.h>

struct NodeParameters
{
    std::string parent_frame_id;
    bool pose_is_fixed;

    double fix_translation_x;
    double fix_translation_y;
    double fix_translation_z;
    double fix_rotation_x;
    double fix_rotation_y;
    double fix_rotation_z;
    double fix_rotation_w;
};

class PoseTransformBroadcaster
{
private:

    NodeParameters parameters_;

    tf2_ros::TransformBroadcaster broadcaster;

    ros::Subscriber pose_msg_sub_;

public:

    PoseTransformBroadcaster(ros::NodeHandle& node);
    ~PoseTransformBroadcaster();

    void SetNodeParameters(const ros::NodeHandle& node);

    void PoseCallBack(const nav_msgs::OdometryConstPtr& pose_msg);
};


