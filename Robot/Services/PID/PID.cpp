/*
 * PID.cpp
 *
 *  Created on: Nov 12, 2025
 *      Author: Kelvin Novais
 */

#include "../../Services/PID/PID.hpp"

#include "../../Context/RobotEnv.hpp"

float PID::lastError = 0;

void PID::reset(const int16_t irSensorError) { lastError = irSensorError; }

float PID::evaluate(const int16_t irSensorError) {
  float P   = irSensorError;
  float D   = irSensorError - lastError;
  float PID = (kp * P) + (kd * D);

  lastError = irSensorError;

  return PID;
}
