#include "ros/ros.h"
#include "arduino_servo_control/SetServoAngles.h"

int main(int argc, char **argv){
    ros::init(argc, argv, "gripper");

    ros::NodeHandle nh;

    ros::ServiceClient client = nh.serviceClient<arduino_servo_control::SetServoAngles>("arduino_servo_control/set_servo_angles");


    arduino_servo_control::SetServoAngles srv;
    srv.request.angle_servo_0 = 0;
    srv.request.angle_servo_1 = 90;

    ros::Rate sleep_rate(0.2);

    if(client.call(srv)){
      ROS_INFO("Setting angle");
    }
    else{
      ROS_INFO("Failed to call service");
      return 1;
    }

    srv.request.angle_servo_1 = 0;

    sleep_rate.sleep();

    if(client.call(srv)){
      ROS_INFO("Setting angle");
    }
    else{
      ROS_INFO("Failed to call service");
      return 1;
    }
    return 0;
}
