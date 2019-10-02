#include <iostream>
#include <ros/ros.h>
#include <geometry_msgs/PoseArray.h>
#include <geometry_msgs/Pose.h>
#include <sstream>
#include <string>
#include <fstream>
#include <eigen3/Eigen/Dense>
#include "tf/tf.h"
#include <visualization_msgs/Marker.h>

using namespace std;
using namespace Eigen;

int main(int argc, char **argv) {
    ros::init(argc, argv, "goal_publisher");
    ros::NodeHandle n;
    ros::Publisher chatter_pub = n.advertise<geometry_msgs::PoseArray>("local_way_points", 10);

    ros::Rate loop_rate(0.25);
    int count = 0;
    vector<double> xv, yv;

    std::ifstream infile("/home/zheng/drone_demo/src/goal_publisher/resources/localgoals.txt");
    double x, y;
    while (infile >> x >> y) {
        cout<<x<<" , "<<y<<endl;
        xv.push_back(x);
        yv.push_back(y);
    }

    while(ros::ok()) {
        ROS_INFO_STREAM("Publishing array");
        geometry_msgs::PoseArray poseArr;
        for(int i=0;i<xv.size();i++) {
            geometry_msgs::Pose ps;
            geometry_msgs::Quaternion qt;
            ps.position.x = xv[i];
            ps.position.y = yv[i];
            ps.position.z = 2.5;
            tf::Quaternion temp_q = tf::Quaternion(0,0,0);
            tf::quaternionTFToMsg(temp_q, qt);
            ps.orientation = qt;
            poseArr.poses.push_back(ps);
        }
        
        chatter_pub.publish(poseArr);
        ros::spinOnce();
        loop_rate.sleep();
        ++count;
    }

}

