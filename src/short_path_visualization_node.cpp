#include "short_path_visualization.h"

int main(int argc, char** argv)
{
    ros::init(argc, argv, "short_path_visualizer");
    ros::NodeHandle node("~");

    ShortPathVisualizer short_path_visualizer_node(node);

    ros::spin();

    return 0;
}