/**
 * @brief Frame conversions helper functions
 * @file uas_frame_conversions.cpp
 * @author Nuno Marques <n.marques21@hotmail.com>
 *
 * @addtogroup nodelib
 * @{
 */
/*
 * Copyright 2015 Nuno Marques.
 *
 * This file is part of the mavros package and subject to the license terms
 * in the top-level LICENSE file of the mavros repository.
 * https://github.com/mavlink/mavros/tree/master/LICENSE.md
 */
#include <array>
#include <mavros/mavros_uas.h>
#include <boost/math/constants/constants.hpp>

const double PI = boost::math::constants::pi<double>();

using namespace mavros;

static tf::Vector3 convert_position(float _x, float _y, float _z){
	float x =  _x;
	float y = -_y;
	float z = -_z;
	return tf::Vector3(x, y, z);
};

static tf::Vector3 convert_velocity(float _vx, float _vy, float _vz){
	float vx =  _vx;
	float vy = -_vy;
	float vz = -_vz;
	return tf::Vector3(vx, vy, vz);
};

static tf::Vector3 convert_accel(float _ax, float _ay, float _az){
	float ax =  _ax;
	float ay = -_ay;
	float az = -_az;
	return tf::Vector3(ax, ay, az);
};

static tf::Vector3 convert_general_xyz(float _x, float _y, float _z){
	float x =  _x;
	float y = -_y;
	float z = -_z;
	return tf::Vector3(x, y, z);
};

static tf::Quaternion convert_attitude_q(tf::Quaternion qo){
	double roll = PI, pitch = 0.0 , yaw = 0.0f; 
	tf::Quaternion qr = tf::createQuaternionFromRPY(roll, pitch, yaw);
	tf::Quaternion qt = qo * qr; 
	return qt;
};

static tf::Vector3 convert_attitude_rpy(float _roll, float _pitch, float _yaw){
	float roll = _roll + PI;
	float pitch = _pitch;
	float yaw = _yaw;
	return tf::Vector3(roll, pitch, yaw);
};
