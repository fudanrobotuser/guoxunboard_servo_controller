#include <functional>
#include <memory>

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>

#include "ros/ros.h"
#include "std_msgs/String.h"
extern "C"
int main_test(int argc, char *argv[]);

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{

  char *args[] = {}; // 构造一个参数数组
  int argc1 = sizeof(args) / sizeof(args[0]); // 参数个数
  main_test(argc1,args);
  ros::init(argc, argv, "listener");
  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
  ros::spin();
  return 0;
}
