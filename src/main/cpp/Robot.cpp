/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <IterativeRobot.h>
#include <Joystick.h>
#include <Talon.h>
#include <Servo.h>
#include <SmartDashboard/SmartDashboard.h>
#include <string>

/**
 * This sample program shows how to control a motor using a joystick. In the
 * operator control part of the program, the joystick is read and the value is
 * written to the motor.
 *
 * Joystick analog values range from -1 to 1 and speed controller inputs as
 * range from -1 to 1 making it easy to work together.
 */
class Robot : public frc::IterativeRobot {
 public:
  void TeleopInit() override {
    servo.Set(0.5); //sets the servo to 90 degrees
  }
  
  void TeleopPeriodic() override { 
    m_motor.Set(m_stick.GetY()); //sets the motor to the joystick's Y value
    servo.Set(m_stick.GetX());  //sets the servo to the joystik's X value
    SmartDashboard::PutString("DigitalInput 0: ", std::to_string(m_stick.GetY()));
  }

 private:
  frc::Joystick m_stick{0};
  frc::Talon m_motor{0};
  frc::Servo servo{2};
};

START_ROBOT_CLASS(Robot)
