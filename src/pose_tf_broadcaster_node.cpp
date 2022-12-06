#include "pose_tf_broadcaster.h"

int main(int argc, char** argv)
{
    ros::init(argc, argv, "pose_tf_broadcaster");
    ros::NodeHandle node("~");

    PoseTransformBroadcaster pose_tf_broadcaster_node(node);

    ros::spin();

    return 0;
}