/*
 * DriveStraight.cpp
 *
 *  Created on: Jan 22, 2016
 *      Author: 461
 */


#include "TurnWithAngle.h"

TurnWithAngle::TurnWithAngle(double angle) : Command() {

	m_angle = angle;
	startingAngle = 0;
	turningLeft = false;


	Requires(Robot::driving.get());
}

void TurnWithAngle::Initialize() {
	Robot::gyro->Reset();
	startingAngle = Robot::gyro->GetAngle();
	turningLeft = m_angle < startingAngle;
}

void TurnWithAngle::Execute() {
	if (turningLeft) {
		Robot::driving->driveTank(-TURN_SPEED, TURN_SPEED);
	}
	else {
		Robot::driving->driveTank(TURN_SPEED, -TURN_SPEED);
	}

	SmartDashboard::PutNumber("Current angle", Robot::gyro->GetAngle());
	SmartDashboard::PutBoolean("Turning left?", turningLeft);
}

bool TurnWithAngle::IsFinished() {
	float currentAngle = Robot::gyro->GetAngle();
	if (turningLeft) {
		return currentAngle <= m_angle;
	}

	else {
		return currentAngle >= m_angle;
	}
}

void TurnWithAngle::End() {
	Robot::driving->driveTank(0,0);
}

void TurnWithAngle::Interrupted() {
	Robot::driving->driveTank(0,0);
}
