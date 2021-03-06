// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "OI.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/Drive.h"
#include "Commands/DriveConveyor.h"
#include "Commands/DriveIntakeRollers.h"
#include "Commands/IntakeGroup.h"
#include "Commands/RotateTurret.h"
#include "Commands/Shoot.h"


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

OI::OI() {
    // Process operator interface input here.
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    xboxController.reset(new Joystick(0));
    
    intakeDownButton.reset(new JoystickButton(xboxController.get(), 2));
    intakeDownButton->WhileHeld(new IntakeGroup(false));
    intakeUpButton.reset(new JoystickButton(xboxController.get(), 1));
    intakeUpButton->WhileHeld(new IntakeGroup(true));
    fireButton.reset(new JoystickButton(xboxController.get(), 4));
    fireButton->WhileHeld(new Shoot(0));

    // SmartDashboard Buttons
    SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());
    SmartDashboard::PutData("DriveConveyor: Up", new DriveConveyor(true));
    SmartDashboard::PutData("DriveConveyor: Down", new DriveConveyor(false));
    SmartDashboard::PutData("Shoot: default", new Shoot(0.8));
    SmartDashboard::PutData("Shoot: off", new Shoot(0));
    SmartDashboard::PutData("RotateTurret: left", new RotateTurret(-1));
    SmartDashboard::PutData("RotateTurret: right", new RotateTurret(1));
    SmartDashboard::PutData("RotateTurret: stop", new RotateTurret(0));
    SmartDashboard::PutData("Drive: Stop", new Drive(0, 0));
    SmartDashboard::PutData("DriveIntakeRollers: In", new DriveIntakeRollers(true));
    SmartDashboard::PutData("DriveIntakeRollers: Out", new DriveIntakeRollers(false));
    SmartDashboard::PutData("IntakeGroup: Up", new IntakeGroup(true));
    SmartDashboard::PutData("IntakeGroup: Down", new IntakeGroup(false));

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

std::shared_ptr<Joystick> OI::getXboxController() {
   return xboxController;
}


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
