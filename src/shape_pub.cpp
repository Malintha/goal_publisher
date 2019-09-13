#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include "Visualize_test.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "basic_shapes");
    ros::NodeHandle n;
    ros::Rate r(1);
    Visualize vs(n,1);

    while (ros::ok())
    {
        vs.draw();
        r.sleep();
    }
}