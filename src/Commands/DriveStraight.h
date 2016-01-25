/*
 * DriveStraight.h
 *
 *  Created on: Jan 22, 2016
 *      Author: 461
 */

#ifndef SRC_COMMANDS_DRIVESTRAIGHT_H_
#define SRC_COMMANDS_DRIVESTRAIGHT_H_

#include "Commands/Subsystem.h"
#include "../Robot.h"

#define DRIVE_SPEED -0.7
#define CORRECTION_FACTOR 0.01

class DriveStraight: public Command {
public:

	DriveStraight(float duration, float speed=DRIVE_SPEED);

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:
	float m_speed;
	float m_duration;
	Timer *timer;
};

#endif /* SRC_COMMANDS_DRIVESTRAIGHT_H_ */
