#include <ros/ros.h>
#include <ros/network.h>
#include <string>
#include <std_msgs/String.h>
#include <sstream>
#include "../include/hardWare_setting/qnode.hpp"
#include <stdlib.h>

#define PI 3.14159265359

extern std::vector<float> Fixed_ID;
extern std::vector<int>    CAN_ID;
extern std::vector<float> speed_pid_p;
extern std::vector<float> speed_pid_i;
extern std::vector<float> speed_pid_d;
extern std::vector<float> position_pid_p;
extern std::vector<float> position_pid_i;
extern std::vector<float> position_pid_d;
extern bool key_modify_id;
extern bool key_debug_speed;
extern bool key_debug_position;
extern bool key_write_speed;
extern bool key_write_position;
extern bool key_test_speed;
extern bool key_test_position;
extern bool key_test_current;
extern bool key_test_position2;
extern int global_index;
extern int CAN_ID_modify;
extern float speed_pid_p_modify,speed_pid_i_modify,speed_pid_d_modify,position_pid_p_modify,position_pid_i_modify,position_pid_d_modify;
extern double speed_draw,position_draw,current_draw;
extern int   num;
extern float A ;
extern float w ;
extern float A_square;
extern int num_square;
namespace hardWare_setting {
void my_callBack(robot_msgs::DownToUp msg)
{
    if(msg.TYPE == "HARDWARE_ID")
    {
        int i=0;
        for(i=0; i<Fixed_ID.size(); i++)
        {
            if(Fixed_ID[i] == msg.DATA[0])
            {
                CAN_ID[i] = msg.ID;
                break;
            }
        }
        if(i == Fixed_ID.size())
        {
            Fixed_ID.push_back(msg.DATA[0]);
            CAN_ID.push_back(msg.ID);
            speed_pid_p.resize(CAN_ID.size());
            speed_pid_i.resize(CAN_ID.size());
            speed_pid_d.resize(CAN_ID.size());
            position_pid_p.resize(CAN_ID.size());
            position_pid_i.resize(CAN_ID.size());
            position_pid_d.resize(CAN_ID.size());
        }
    }
    else if(msg.TYPE == "SPEED_PID")
    {
        if(CAN_ID.size()>0)
        {
            for(int i=0; i<CAN_ID.size(); i++)
            {
                if(msg.ID == CAN_ID[i])
                {
                    speed_pid_p[i] = msg.DATA[0];
                    speed_pid_i[i] = msg.DATA[1];
                    speed_pid_d[i] = msg.DATA[2];
                }
            }
        }
    }
    else if(msg.TYPE == "POSITION_PID")
    {
        if(CAN_ID.size()>0)
        {
            for(int i=0; i<CAN_ID.size(); i++)
            {
                if(msg.ID == CAN_ID[i])
                {
                    position_pid_p[i] = msg.DATA[0];
                    position_pid_i[i] = msg.DATA[1];
                    position_pid_d[i] = msg.DATA[2];
                }
            }
        }
    }
    else if(msg.TYPE == "SPEED")
    {
        speed_draw = msg.DATA[0];
    }
    else if(msg.TYPE == "POSITION")
    {
        position_draw = msg.DATA[0];
    }
	else if(msg.TYPE == "CURRENT")
	{
		current_draw = msg.DATA[0];
	}
}
CDownToUp_Listen::CDownToUp_Listen(int argc, char** argv ) : init_argc(argc), init_argv(argv){}
CDownToUp_Listen::~CDownToUp_Listen() {
    if(ros::isStarted()) {
      ros::shutdown();
      ros::waitForShutdown();
    }
	wait();
}
bool CDownToUp_Listen::init() {
    ros::init(init_argc,init_argv,"hardWare_setting_down_to_up");
	if ( ! ros::master::check() ) {
		return false;
	}
    ros::start();
	ros::NodeHandle n;
    sub_down_to_up = n.subscribe("down_to_up", 1000, my_callBack);
    start();
	return true;
}
void CDownToUp_Listen::run() {
    ros::spin();
}

CUpToDown::CUpToDown(int argc, char** argv ) : init_argc(argc), init_argv(argv){}
CUpToDown::~CUpToDown() {
    if(ros::isStarted()) {
      ros::shutdown();
      ros::waitForShutdown();
    }
    wait();
}
bool CUpToDown::init() {
    ros::init(init_argc,init_argv,"hardWare_setting_up_to_down");
    if ( ! ros::master::check() ) {
        return false;
    }
    ros::start();
    ros::NodeHandle n;
    pub_up_to_down = n.advertise<robot_msgs::UpToDown>("up_to_down", 1000);
    start();
    return true;
}
void CUpToDown::run() {
    ros::Rate loop_rate(100);
    while(ros::ok())
    {
        if(key_modify_id)
        {
            msg_up_to_down.ID.resize(2);
            if(global_index == -1)
            {
                ROS_ERROR("select a Fixed ID first!");
                exit(0);
            }
            msg_up_to_down.ID[0] = CAN_ID[global_index];
            msg_up_to_down.ID[1] = CAN_ID_modify;
            msg_up_to_down.MODE = 3;
            pub_up_to_down.publish(msg_up_to_down);
            key_modify_id = false;
        }
        else if(key_debug_position)
        {
            msg_up_to_down.ID.resize(1);
            if(global_index == -1)
            {
                ROS_ERROR("select a Fixed ID first!");
                exit(0);
            }
            msg_up_to_down.ID[0] = CAN_ID[global_index];
            msg_up_to_down.POSITION.resize(3);
            msg_up_to_down.POSITION[0] = position_pid_p_modify;
            msg_up_to_down.POSITION[1] = position_pid_i_modify;
            msg_up_to_down.POSITION[2] = position_pid_d_modify;
            msg_up_to_down.MODE = 5;
            pub_up_to_down.publish(msg_up_to_down);
            key_debug_position = false;
        }
        else if(key_write_position)
        {
            msg_up_to_down.ID.resize(1);
            if(global_index == -1)
            {
                ROS_ERROR("select a Fixed ID first!");
                exit(0);
            }
            msg_up_to_down.ID[0] = CAN_ID[global_index];
            msg_up_to_down.POSITION.resize(3);
            msg_up_to_down.POSITION[0] = position_pid_p_modify;
            msg_up_to_down.POSITION[1] = position_pid_i_modify;
            msg_up_to_down.POSITION[2] = position_pid_d_modify;
            msg_up_to_down.MODE = 7;
            pub_up_to_down.publish(msg_up_to_down);
            key_write_position = false;
        }
        else if(key_debug_speed)
        {
            msg_up_to_down.ID.resize(1);
            if(global_index == -1)
            {
                ROS_ERROR("select a Fixed ID first!");
                exit(0);
            }
            msg_up_to_down.ID[0] = CAN_ID[global_index];
            //msg_up_to_down.ID[0] = 127;
            msg_up_to_down.POSITION.resize(3);
            msg_up_to_down.POSITION[0] = speed_pid_p_modify;
            msg_up_to_down.POSITION[1] = speed_pid_i_modify;
            msg_up_to_down.POSITION[2] = speed_pid_d_modify;
            msg_up_to_down.MODE = 6;
            pub_up_to_down.publish(msg_up_to_down);
            key_debug_speed = false;
        }
        else if(key_test_speed)
        {
            msg_up_to_down.ID.resize(1);
  			for(int j=0; j<2; j++)
            {
                for(int i=0; i<25; i++)//发送方波速度曲线
                {
                    if(global_index == -1)
                    {
                        ROS_ERROR("select a Fixed ID first!");
                        exit(0);
                    }
                    msg_up_to_down.ID[0] = CAN_ID[global_index];
                    msg_up_to_down.SPEED.resize(1);
                    msg_up_to_down.SPEED[0] = 1.0;
                    msg_up_to_down.CURRENT.resize(0);
                    msg_up_to_down.MODE = 9;
                    pub_up_to_down.publish(msg_up_to_down);
                    ros::Duration(0.05).sleep();
                }
                for(int i=0; i<25; i++)
                {
                    if(global_index == -1)
                    {
                        ROS_ERROR("select a Fixed ID first!");
                        exit(0);
                    }
                    msg_up_to_down.ID[0] = CAN_ID[global_index];
                    msg_up_to_down.SPEED.resize(1);
                    msg_up_to_down.SPEED[0] = 1.0;
                    msg_up_to_down.CURRENT.resize(0);
                    msg_up_to_down.MODE = 9;
                    pub_up_to_down.publish(msg_up_to_down);
                    ros::Duration(0.05).sleep();
                }
            }
            key_test_speed = false;
        }
        else if(key_test_current)
        {
            msg_up_to_down.ID.resize(1);
            for(int j=0; j<2; j++)
            {
                for(int i=0; i<24; i++)//发送方波电流曲线
                {
                    if(global_index == -1)
                    {
                        ROS_ERROR("select a Fixed ID first!");
                        exit(0);
                    }
                    msg_up_to_down.ID[0] = CAN_ID[global_index];
                    msg_up_to_down.SPEED.resize(1);
                    msg_up_to_down.SPEED[0] = -0.2;
                    msg_up_to_down.CURRENT.resize(1);
                    msg_up_to_down.CURRENT[0] = 0.5;
                    msg_up_to_down.MODE = 11;
                    pub_up_to_down.publish(msg_up_to_down);
                    ros::Duration(0.05).sleep();
                }
                for(int i=0; i<24; i++)
                {
                    if(global_index == -1)
                    {
                        ROS_ERROR("select a Fixed ID first!");
                        exit(0);
                    }
                    msg_up_to_down.ID[0] = CAN_ID[global_index];
                    msg_up_to_down.SPEED.resize(1);
                    msg_up_to_down.SPEED[0] = 0.2;
                    msg_up_to_down.CURRENT.resize(1);
                    msg_up_to_down.CURRENT[0] = -0.5;
                    msg_up_to_down.MODE = 11;
                    pub_up_to_down.publish(msg_up_to_down);
                    ros::Duration(0.05).sleep();
                }
            }
            key_test_current = false;
        }
        else if(key_test_position)
        {
            msg_up_to_down.ID.resize(1);
            for(int j=0; j<2; j++)
            {
                for(int i=0; i<300; i++)//发送方波位置曲线
                {
                    if(global_index == -1)
                    {
                        ROS_ERROR("select a Fixed ID first!");
                        exit(0);
                    }
                    msg_up_to_down.ID[0] = CAN_ID[global_index];
                    msg_up_to_down.POSITION.resize(1);
                    msg_up_to_down.SPEED.resize(1);
                    float t = (float)i / 1000 * 20;
                    msg_up_to_down.POSITION[0] = A * sin(w * t);
                    msg_up_to_down.SPEED[0] = A * w *cos(w * t);
                    msg_up_to_down.MODE = 1;
                    pub_up_to_down.publish(msg_up_to_down);
                    ros::Duration(0.02).sleep();
                }
            }
            key_test_position = false;
        }
        else if(key_test_position2)
        {
            msg_up_to_down.ID.resize(1);

            for(int j=0; j<num_square; j++)
            {
                msg_up_to_down.ID[0] = CAN_ID[global_index];
                msg_up_to_down.POSITION.resize(1);
                msg_up_to_down.SPEED.resize(1);
                msg_up_to_down.POSITION[0] = A_square;
                msg_up_to_down.SPEED[0] = 0.2;
                msg_up_to_down.MODE = 1;
                pub_up_to_down.publish(msg_up_to_down);
                ros::Duration(0.02).sleep();

                for(int i=1; i<(300/num_square); i++)
                {
                    if(global_index == -1)
                    {
                        ROS_ERROR("select a Fixed ID first!");
                        exit(0);
                    }
                    msg_up_to_down.ID[0] = CAN_ID[global_index];
                    msg_up_to_down.POSITION.resize(1);
                    msg_up_to_down.SPEED.resize(1);
                    msg_up_to_down.POSITION[0] = A_square;
                    msg_up_to_down.SPEED[0] = 0;
                    msg_up_to_down.MODE = 1;
                    pub_up_to_down.publish(msg_up_to_down);
                    ros::Duration(0.02).sleep();
                }
/*
                msg_up_to_down.ID[0] = CAN_ID[global_index];
                msg_up_to_down.POSITION.resize(1);
                msg_up_to_down.SPEED.resize(1);
                msg_up_to_down.POSITION[0] = A_square;
                msg_up_to_down.SPEED[0] = 0.2;
                msg_up_to_down.MODE = 1;
                pub_up_to_down.publish(msg_up_to_down);
                ros::Duration(0.02).sleep();
*/
                for(int i=0; i<(300/num_square); i++)
                {
                    if(global_index == -1)
                    {
                        ROS_ERROR("select a Fixed ID first!");
                        exit(0);
                    }
                    msg_up_to_down.ID[0] = CAN_ID[global_index];
                    msg_up_to_down.POSITION.resize(1);
                    msg_up_to_down.SPEED.resize(1);
                    msg_up_to_down.POSITION[0] = A_square;
                    msg_up_to_down.SPEED[0] = 0;
                    msg_up_to_down.MODE = 1;
                    pub_up_to_down.publish(msg_up_to_down);
                    ros::Duration(0.02).sleep();
                }
            }
            key_test_position2 = false;
        }
        else if(key_write_speed)
        {
            msg_up_to_down.ID.resize(1);
            if(global_index == -1)
            {
                ROS_ERROR("select a Fixed ID first!");
                exit(0);
            }
            msg_up_to_down.ID[0] = CAN_ID[global_index];
            msg_up_to_down.POSITION.resize(3);
            msg_up_to_down.POSITION[0] = speed_pid_p_modify;
            msg_up_to_down.POSITION[1] = speed_pid_i_modify;
            msg_up_to_down.POSITION[2] = speed_pid_d_modify;
            msg_up_to_down.MODE = 8;
            pub_up_to_down.publish(msg_up_to_down);
            key_write_speed = false;
        }
        loop_rate.sleep();
    }
    ros::shutdown();
}
}
