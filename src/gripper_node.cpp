#include "ros/ros.h"
#include "ras_servo_control/SetServoAngles.h"

int main(int argc, char **argv){
    ros::init(argc, argv, "gripper");

    ros::NodeHandle nh;
    ros::ServiceClient client =  nh.ServiceClient<SetServoAngles>("set_servo_angles");

    SetServoAngles srv;
    srv.request.angle_servo_0 = 90;

    if(client.call(ServiceClient)){
      ROS_INFO("Setting angle to: %i",srv.request.angle_servo_0);
    }
    else{
      ROS_INFO("Failed to call service");
      return 1;
    }

    srv.request.angle_servo_0 = 0;

    if(client.call(ServiceClient)){
      ROS_INFO("Setting angle to: %i",srv.request.angle_servo_0);
    }
    else{
      ROS_INFO("Failed to call service");
      return 1;
    }

    return 0;
}
