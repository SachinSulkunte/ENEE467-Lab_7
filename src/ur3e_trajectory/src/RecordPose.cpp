#include <moveit_wrapper/arm_controller.hpp>

int main(int argc, char **argv)
{
     // Setup ROS node
    ros::init(argc, argv, "RecordPose");
    ros::AsyncSpinner spinner(4);
    spinner.start();
    ros::NodeHandle nh;
    ros::Rate rate(2);
    std::string out_path = "/home/labuser/workspace/src/ur3e_trajectory/src/squar_pose.csv";
    // std::string out_path = "/home/labuser/enee467_as/Lab_7/src/ur3e_trajectory/src/pose.csv";
    bool record_pose;
    int flag = 0;   

    moveit::planning_interface::MoveGroupInterface arm_move_group("manipulator");

    while (flag == 0) {
        nh.getParam("/record_pose", record_pose);
        if(record_pose == true) {
            flag = 1;
        }
        rate.sleep();

    }

    geometry_msgs::Pose current_pose;
    std::ofstream eef_file;
    eef_file.open(out_path);
    if (eef_file.is_open()){ std::cout << "yessssssssssssss"; }
    else { std::cout << "nooooooooooooooooooooo";}
    while(record_pose == true) {
        
        current_pose = arm_move_group.getCurrentPose().pose;
        eef_file << current_pose.position.x << "," << current_pose.position.y << "," << current_pose.position.z << std::endl;
        nh.getParam("/record_pose", record_pose);
        std::cout<< current_pose.position.x << "," << current_pose.position.y << "," << current_pose.position.z << std::endl;
        rate.sleep();
    }
    eef_file.close();

}
   