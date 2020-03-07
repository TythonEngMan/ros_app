#include <ros/ros.h>
#include <rosbag/bag.h>
#include <std_msgs/Int32.h>
#include <std_msgs/String.h>

int main(int argc, char* argv[])
{
  // This must be called before anything else ROS-related
  ros::init(argc, argv, "rosbag_creator_node");

  // Create a ROS node handle
  ros::NodeHandle nh;

  ROS_INFO("Start creating a BAG file");
  rosbag::Bag bag;
  bag.open("test.bag", rosbag::bagmode::Write);

  std_msgs::String str;
  str.data = std::string("foo");

  std_msgs::Int32 i;
  i.data = 42;

  bag.write("/test/string", ros::Time::now(), str);
  bag.write("/test/int", ros::Time::now(), i);

  bag.close();
  ROS_INFO("Finish creating the BAG file");

  //ros::spin();
}
