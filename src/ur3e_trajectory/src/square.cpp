// #include "../include/square.hpp"

// int main(int argc, char **argv)
// {
//      // Setup ROS node
//     ros::init(argc, argv, "square");
//     ros::AsyncSpinner spinner(4);
//     spinner.start();
//     ros::NodeHandle n;
    
//     // Create PlanningOptions
//     MoveitPlanning::PlanningOptions planning_options =
//     MoveitPlanning::PlanningOptions();
//     planning_options.num_attempts = 10;
//     planning_options.allow_replanning = true;
//     planning_options.set_planning_time = 30.0;
//     planning_options.goal_position_tolerance = 0.01;
//     planning_options.goal_orientation_tolerance = 0.01;
//     planning_options.goal_joint_tolerance = 0.01;
//     planning_options.velocity_scaling_factor = 0.1;
//     planning_options.acceleration_scaling_factor = 0.1;

//     // Create instance of MoveGroupInterface for given joint group
//     moveit::planning_interface::MoveGroupInterface arm_move_group("manipulator");

//     //Write your code for following the square trajectory here.

//     // Create instance of joint target plan

//     moveit::planning_interface::MoveGroupInterface::Plan joint_plan;

//     std::map<std::string, double> joint_targets;
//     joint_targets["elbow_joint"] = 1.01229;
//     joint_targets["shoulder_lift_joint"] = -0.366519;
//     joint_targets["shoulder_pan_joint"] = -3.52557;
//     joint_targets["wrist_1_joint"] = -2.21657;
//     joint_targets["wrist_2_joint"] = 1.5708;
//     joint_targets["wrist_3_joint"] = 4.97419;

//     bool joint_plan_success;
//     joint_plan_success = ArmController::planToJointTargets(planning_options, arm_move_group, joint_plan, joint_targets);

//     if(joint_plan_success){
//         ROS_INFO("Moving to joint target");
//         arm_move_group.execute(joint_plan);
//     }
    
//     geometry_msgs::Pose waypoint_1;
//     waypoint_1.position.x = -0.53;
//     waypoint_1.position.y = 0.0;
//     waypoint_1.position.z = 1.0;
//     waypoint_1.orientation.x = 0.0;
//     waypoint_1.orientation.y = 0.0;
//     waypoint_1.orientation.z = 1;
//     waypoint_1.orientation.w = 0;
    
//     geometry_msgs::Pose waypoint_2;
//     waypoint_2.position.x = 0.0;
//     waypoint_2.position.y = -0.53;
//     waypoint_2.position.z = 1.0;
//     waypoint_2.orientation.x = 0.0;
//     waypoint_2.orientation.y = 0.0;
//     waypoint_2.orientation.z = 1;
//     waypoint_2.orientation.w = 0;
   
//     geometry_msgs::Pose waypoint_3;
//     waypoint_3.position.x = 0.53;
//     waypoint_3.position.y = 0.0;
//     waypoint_3.position.z = 1.1;
//     waypoint_3.orientation.x = 0.0;
//     waypoint_3.orientation.y = 0.0;
//     waypoint_3.orientation.z = 1;
//     waypoint_3.orientation.w = 0;

//     geometry_msgs::Pose waypoint_4;
//     waypoint_4.position.x = 0;
//     waypoint_4.position.y = 0.53;
//     waypoint_4.position.z = 1.1;
//     waypoint_4.orientation.x = 0.0;
//     waypoint_4.orientation.y = 0.0;
//     waypoint_4.orientation.z = 1;
//     waypoint_4.orientation.w = 0;


//     moveit::planning_interface::MoveGroupInterface::Plan pose_plan;
    
//     bool pose_plan_success;
//     std::string reference_frame = "base_link";
//     pose_plan_success = ArmController::planToPoseTarget(planning_options, arm_move_group, waypoint_1, reference_frame, pose_plan);
//     if(pose_plan_success){
//         arm_move_group.execute(pose_plan);
//     }


//     std::vector<geometry_msgs::Pose> waypoints;
//     waypoints.push_back(waypoint_1);
//     waypoints.push_back(waypoint_2);
//     waypoints.push_back(waypoint_3);
//     waypoints.push_back(waypoint_4);
//     waypoints.push_back(waypoint_1);

//     geometry_msgs::Pose start_pose = arm_move_group.getCurrentPose().pose;

//     moveit_msgs::RobotTrajectory trajectory;
//     trajectory = ArmController::planCartesianPath(start_pose, waypoints, reference_frame, arm_move_group);

//     n.setParam("/record_pose", true);
//     arm_move_group.execute(trajectory);
//     n.setParam("/record_pose", false);



// }

#include "../include/square.hpp"

int main(int argc, char **argv)
{
     // Setup ROS node
    ros::init(argc, argv, "square");
    ros::AsyncSpinner spinner(4);
    spinner.start();
    ros::NodeHandle n;
    
    // Create PlanningOptions
    MoveitPlanning::PlanningOptions planning_options =
    MoveitPlanning::PlanningOptions();
    planning_options.num_attempts = 10;
    planning_options.allow_replanning = true;
    planning_options.set_planning_time = 30.0;
    planning_options.goal_position_tolerance = 0.01;
    planning_options.goal_orientation_tolerance = 0.01;
    planning_options.goal_joint_tolerance = 0.01;
    planning_options.velocity_scaling_factor = 0.5;
    planning_options.acceleration_scaling_factor = 0.5;

    // Create instance of MoveGroupInterface for given joint group
    moveit::planning_interface::MoveGroupInterface arm_move_group("manipulator");

    //Write your code for following the square trajectory here.

    // Create instance of joint target plan

    moveit::planning_interface::MoveGroupInterface::Plan joint_plan;

    std::map<std::string, double> joint_targets;
    joint_targets["elbow_joint"] = 1.01229;
    joint_targets["shoulder_lift_joint"] = -0.366519;
    joint_targets["shoulder_pan_joint"] = -3.52557;
    joint_targets["wrist_1_joint"] = -2.21657;
    joint_targets["wrist_2_joint"] = 1.5708;
    joint_targets["wrist_3_joint"] = 4.97419;

    bool joint_plan_success;
    joint_plan_success = ArmController::planToJointTargets(planning_options, arm_move_group, joint_plan, joint_targets);

    if(joint_plan_success){
        ROS_INFO("Moving to joint target");
        arm_move_group.execute(joint_plan);
    }
    
    geometry_msgs::Pose waypoint_1;
    waypoint_1.position.x = -0.55;
    waypoint_1.position.y = 0.0;
    waypoint_1.position.z = 1.0;
    waypoint_1.orientation.x = 0.0;
    waypoint_1.orientation.y = 0.0;
    waypoint_1.orientation.z = 1;
    waypoint_1.orientation.w = 0;
    
    geometry_msgs::Pose waypoint_2;
    waypoint_2.position.x = 0.0;
    waypoint_2.position.y = -0.55;
    waypoint_2.position.z = 1.0;
    waypoint_2.orientation.x = 0.0;
    waypoint_2.orientation.y = 0.0;
    waypoint_2.orientation.z = 1;
    waypoint_2.orientation.w = 0;
   
    geometry_msgs::Pose waypoint_3;
    waypoint_3.position.x = 0.55;
    waypoint_3.position.y = 0.0;
    waypoint_3.position.z = 1.1;
    waypoint_3.orientation.x = 0.0;
    waypoint_3.orientation.y = 0.0;
    waypoint_3.orientation.z = 1;
    waypoint_3.orientation.w = 0;

    geometry_msgs::Pose waypoint_4;
    waypoint_4.position.x = 0;
    waypoint_4.position.y = 0.55;
    waypoint_4.position.z = 1.1;
    waypoint_4.orientation.x = 0.0;
    waypoint_4.orientation.y = 0.0;
    waypoint_4.orientation.z = 1;
    waypoint_4.orientation.w = 0;


    moveit::planning_interface::MoveGroupInterface::Plan pose_plan;
    
    bool pose_plan_success;
    std::string reference_frame = "base_link";
    pose_plan_success = ArmController::planToPoseTarget(planning_options, arm_move_group, waypoint_1, reference_frame, pose_plan);
    if(pose_plan_success){
        arm_move_group.execute(pose_plan);
    }


    std::vector<geometry_msgs::Pose> waypoints;
    waypoints.push_back(waypoint_1);
    waypoints.push_back(waypoint_2);
    waypoints.push_back(waypoint_3);
    waypoints.push_back(waypoint_4);
    waypoints.push_back(waypoint_1);

    geometry_msgs::Pose start_pose = arm_move_group.getCurrentPose().pose;

    moveit_msgs::RobotTrajectory trajectory;
    trajectory = ArmController::planCartesianPath(start_pose, waypoints, reference_frame, arm_move_group);

    n.setParam("/record_pose", true);
    arm_move_group.execute(trajectory);
    n.setParam("/record_pose", false);

    // testing

}