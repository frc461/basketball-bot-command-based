// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Shoot.h"

#define kDefaultFirePower 0.5
#define kDefaultStep 0.05

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

Shoot::Shoot(double firePower): Command() {
    m_firePower = firePower;
        // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::shooting.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void Shoot::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
bool buttonDown = false;
float currentFirePower = kDefaultFirePower;
void Shoot::Execute() {
	std::shared_ptr<Joystick> xbox = Robot::oi->getXboxController();
	if (xbox->GetRawAxis(3) > 0.5) {
		m_firePower = currentFirePower;
	}
	else {
		m_firePower = 0.0f;
	}

	if (xbox->GetRawButton(4)) {
		if (!buttonDown) {
			buttonDown = true;
			currentFirePower += kDefaultStep;
			if (currentFirePower > 1.0f) {
				currentFirePower = 1.0f;
			}
		}
	}
	else if (xbox->GetRawButton(3)) {
		if (!buttonDown) {
			buttonDown = true;
			currentFirePower -= kDefaultStep;
			if (currentFirePower < 0.0f) {
				currentFirePower = 0.0f;
			}
		}
	}
	else {
		buttonDown = false;
	}

	Robot::shooting->shootAtSpeed(m_firePower);
}

// Make this return true when this Command no longer needs to run execute()
bool Shoot::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void Shoot::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Shoot::Interrupted() {

}
