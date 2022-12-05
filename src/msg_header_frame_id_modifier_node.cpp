#include "msg_header_frame_id_modifier.h"

int main(int argc, char** argv)
{
    ros::init(argc, argv, "msg_header_frame_id_modifier");
    ros::NodeHandle node("~");

    ShortPathVisualizer short_path_visualizer_node(node);

    ros::spin();

    return 0;
}