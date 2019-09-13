#include "Visualize_test.h"
#include "geometry_msgs/Point.h"

Visualize::Visualize(ros::NodeHandle nh, int nDrones) {
    this->marker_pub = nh.advertise<visualization_msgs::Marker>("visualization_marker", 10);

    for(int i=0;i<nDrones;i++) {
        visualization_msgs::Marker m;

        m.header.frame_id="map";
        m.header.stamp = ros::Time::now();
        m.ns = "path";
        m.id = 100;

        m.type = visualization_msgs::Marker::LINE_STRIP;
        m.action = visualization_msgs::Marker::ADD;
        m.color.r=1; 
        m.color.g=0; 
        m.color.b=0;
        m.color.a = 1;
        m.scale.x = 0.05;
        m.scale.y = 0.05;
        m.scale.z = 0.05;
        m.pose.orientation.x = 0.0;
        m.pose.orientation.y = 0.0;
        m.pose.orientation.z = 0.0;
        m.pose.orientation.w = 1.0;
        m.lifetime = ros::Duration();

        this->markerVec.push_back(m);
    }
}

void Visualize::draw() {
    ROS_DEBUG_STREAM("draw");
   
    for(int k=0;k<10;k++) {
        geometry_msgs::Point mp;
        mp.x = k;
        mp.y = k;
        mp.z = 2;
        this->markerVec[0].points.push_back(mp);
    }

    marker_pub.publish(markerVec[0]);
}
