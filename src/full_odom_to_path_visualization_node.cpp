#include "full_odom_to_path_visualization.h"

int main(int argc, char** argv)
{
    ros::init(argc, argv, "full_path_visualizer");
    ros::NodeHandle node("~");

    FullPathVisualizer full_path_visualizer_node(node);

    ros::spin();

    return 0;
}