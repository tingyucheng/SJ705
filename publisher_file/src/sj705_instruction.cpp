#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <control_msgs/JointControllerState.h>
#include <stdio.h>
#include <math.h>
using namespace std;

#define PI 3.14159

int main(int argc, char **argv)
{
    ros::init(argc, argv, "sj705");
    ros::NodeHandle n;
    ros::Publisher joint1_pub = n.advertise<std_msgs::Float64>("/sj705/joint1_position_controller/command", 10);
    ros::Publisher joint2_pub = n.advertise<std_msgs::Float64>("/sj705/joint2_position_controller/command", 10);
    ros::Publisher joint3_pub = n.advertise<std_msgs::Float64>("/sj705/joint3_position_controller/command", 10);
    ros::Publisher joint4_pub = n.advertise<std_msgs::Float64>("/sj705/joint4_position_controller/command", 10);
    ros::Publisher joint5_pub = n.advertise<std_msgs::Float64>("/sj705/joint5_position_controller/command", 10);
    ros::Publisher joint6_pub = n.advertise<std_msgs::Float64>("/sj705/joint6_position_controller/command", 10);
    ros::Publisher joint7_pub = n.advertise<std_msgs::Float64>("/sj705/joint7_position_controller/command", 10);


    ros::Rate rate(10);

    std_msgs::Float64 joint1, joint2, joint3, joint4, joint5, joint6, joint7;

    double theta1, theta2, theta3, theta4, theta5, theta6, theta7;

    joint1.data = 0;
    joint2.data = 0;
    joint3.data = 0;
    joint4.data = 0;
    joint5.data = 0;
    joint6.data = 0;
    joint7.data = 0;

    char type;

    while (ros::ok())
    {
            cout << "*******************************************************************************" << endl;
            cout << " Input type : " << endl << endl;
            cout << " f : forward" << endl << endl;
            cout << " Usage : " << endl;
            cout << endl;            
            cout << "  f theta1 theta2 theta3 theta4 theta5 theta6 theta7" << endl;
            cout << endl << endl;
            cout << " You can type in your input type first and then type in your inputs, or you can type them in one line." << endl << endl;
            cout << " If you want to quit, press ctrl C and then type 'q' in the terminal." << endl;
            cout << "*******************************************************************************" << endl;
            cout << " Instruction : ";
            cin >> type ;
            switch(type) {
                case 'f':
                    cout << "Control joints (theta1~theta7) (degree): ";
                    cin >> joint1.data >> joint2.data >> joint3.data >> joint4.data >> joint5.data >> joint6.data >> joint7.data;
                    cout << endl;
                    
                    joint1.data = joint1.data / 180 * PI;
                    joint2.data = joint2.data / 180 * PI;
                    joint3.data = joint3.data / 180 * PI;
                    joint4.data = joint4.data / 180 * PI;
                    joint5.data = joint5.data / 180 * PI;
                    joint6.data = joint6.data / 180 * PI;
                    joint7.data = joint7.data / 180 * PI;

                    break;
                    
                case 'q':
                    cout << "Quit sj705 instruction." << endl;
                    break;
                                     
            }

            joint1_pub.publish(joint1);
            joint2_pub.publish(joint2);
            joint3_pub.publish(joint3);
            joint4_pub.publish(joint4);
            joint5_pub.publish(joint5);
            joint6_pub.publish(joint6);
            joint7_pub.publish(joint7);


        ros::spinOnce();
        rate.sleep();
    }

    return 0;
}
