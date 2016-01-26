// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef AUTONOMOUS_COMMAND_H
#define AUTONOMOUS_COMMAND_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class CenterGoal: public Command {
public:
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR
	CenterGoal(float width, float centerX, /*float centerY,*/ float widthTolerance=0.1, float centerXTolerance=0.1/*, float centerYTolerance=0.1*/);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=VARIABLES


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=VARIABLES

	float m_width;
	float m_centerX;
//	float m_centerY;
	float m_widthTolerance;
	float m_centerXTolerance;
//	float m_centerYTolerance;

	bool aligned;

	bool IsCorrectWidth(float currentWidth);
	void AlignWidth(float currentWidth);

//	bool IsCorrectY(float currentY);
//	void AlignY(float currentY);

	bool IsCorrectX(float currentX);
	void AlignX(float currentX);
};

#endif
