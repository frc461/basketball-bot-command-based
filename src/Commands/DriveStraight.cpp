/*
 * DriveStraight.cpp
 *
 *  Created on: Jan 22, 2016
 *      Author: 461
 */


#include "DriveStraight.h"

DriveStraight::DriveStraight(float duration, float speed) : Command() {
	m_speed = speed;
	m_duration = duration;

	timer = new Timer();

	Requires(Robot::driving.get());
}

void DriveStraight::Initialize() {
	timer->Reset();
	timer->Start();
}

void DriveStraight::Execute() {
	float correction = Robot::gyro->GetAngle() * CORRECTION_FACTOR;
	Robot::driving->driveTank(m_speed + correction, m_speed - correction);
}

bool DriveStraight::IsFinished() {
	return timer->Get() > m_duration;
}

void DriveStraight::End() {
	Robot::driving->driveTank(0,0);
}

void DriveStraight::Interrupted() {
	Robot::driving->driveTank(0,0);
}
