// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Robot.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
std::shared_ptr<Conveyor> Robot::conveyor;
std::shared_ptr<Driving> Robot::driving;
std::shared_ptr<Shooting> Robot::shooting;
std::shared_ptr<Aiming> Robot::aiming;
std::shared_ptr<IntakeRollers> Robot::intakeRollers;
std::unique_ptr<OI> Robot::oi;
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION

std::shared_ptr<ADXRS450_Gyro> Robot::gyro;
std::shared_ptr<CameraServer> Robot::cameraServer;
std::shared_ptr<NetworkTable> Robot::networkTable;

void Robot::RobotInit() {
	RobotMap::init();
	gyro = std::shared_ptr<ADXRS450_Gyro>(new ADXRS450_Gyro(SPI::kOnboardCS0));
	gyro->Calibrate();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    conveyor.reset(new Conveyor());
    driving.reset(new Driving());
    shooting.reset(new Shooting());
    aiming.reset(new Aiming());
    intakeRollers.reset(new IntakeRollers());
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi.reset(new OI());

	// instantiate the command used for the autonomous period
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
	autonomousCommand.reset(new AutonomousCommand());
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS

	driveStraightAuto.reset(new DriveStraight(5));
	turnWithAngleAuto.reset(new TurnWithAngle(90));

	CameraServer::GetInstance()->StartAutomaticCapture("cam0");
	networkTable = NetworkTable::GetTable("myContoursReport");

	printf("Robot inited");
  }

/**
 * This function is called when the disabled button is hit.
 * You can use it to reset subsystems before shutting down.
 */
void Robot::DisabledInit(){

}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
//	if (autonomousCommand.get() != nullptr)
//		autonomousCommand->Start();

//	if (driveStraightAuto.get() != nullptr) {
//		driveStraightAuto->Start();
//	}

	if (turnWithAngleAuto.get() != nullptr) {
		turnWithAngleAuto->Start();
	}
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// these lines or comment it out.
	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Cancel();

	if (driveStraightAuto.get() != nullptr) {
		driveStraightAuto->Cancel();
	}

	if (turnWithAngleAuto.get() != nullptr) {
		turnWithAngleAuto->Cancel();
	}
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
	SmartDashboard::PutNumber("Gyro Angle", gyro->GetAngle());
	SmartDashboard::PutNumber("Gyro Rate", gyro->GetRate());
//	SmartDashboard::PutData("Cam", )
}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot);

