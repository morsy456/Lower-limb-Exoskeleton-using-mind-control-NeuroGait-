#ifndef PATHPLANNING_H
#define PATHPLANNING_H

struct GaitPoint {
  float time;
  float leftHipAngle;
  float leftKneeAngle;
  float rightHipAngle;
  float rightKneeAngle;
};


GaitPoint gaitCycle[] = {
  // Step 1 (Left leg)
  {0.0, 0.0, 0.0, 0.0, 0.0},    // Initial position (heel strike of left foot)
  {0.125, 15.0, 5.0, -5.0, 15.0}, // Loading response (foot flat)
  {0.25, 25.0, 10.0, -10.0, 30.0}, // Mid-stance
  {0.375, 20.0, 5.0, 5.0, 20.0},  // Terminal stance (heel off)
  {0.5, 0.0, 15.0, 20.0, 0.0},   // Pre-swing (toe off)
  {0.625, -15.0, 60.0, 10.0, 5.0}, // Initial swing
  {0.75, -25.0, 40.0, 15.0, 10.0}, // Mid-swing
  {0.875, -5.0, 10.0, 5.0, 0.0},  // Terminal swing (preparation for heel strike)
  {1.0, 0.0, 0.0, 0.0, 0.0},    // Heel strike of the right foot (end of first step)

  // Step 2 (Right leg)
  {1.125, -5.0, 15.0, 15.0, 5.0}, // Loading response (foot flat)
  {1.25, -10.0, 30.0, 25.0, 10.0}, // Mid-stance
  {1.375, 5.0, 20.0, 20.0, 5.0},  // Terminal stance (heel off)
  {1.5, 20.0, 0.0, 0.0, 15.0},   // Pre-swing (toe off)
  {1.625, 10.0, 5.0, -15.0, 60.0}, // Initial swing
  {1.75, 15.0, 10.0, -25.0, 40.0}, // Mid-swing
  {1.875, 5.0, 0.0, -5.0, 10.0},  // Terminal swing (preparation for heel strike)
  {2.0, 0.0, 0.0, 0.0, 0.0}      // Heel strike of the left foot (end of second step)
};


const int numPoints = sizeof(gaitCycle) / sizeof(GaitPoint);

float interpolate(float t, float t0, float t1, float x0, float x1) {
  return  (x0 + (x1 - x0) * (float)((t - t0) / (t1 - t0)));
}
float angles[]={0,0,0,0};
void calculateTrajectory(float t) {
  for (int i = 0; i < numPoints - 1; i++) {
    if (t >= gaitCycle[i].time && t <= gaitCycle[i+1].time) {
      angles[0] = interpolate(t, gaitCycle[i].time, gaitCycle[i+1].time, gaitCycle[i].leftHipAngle, gaitCycle[i+1].leftHipAngle);
      angles[1] = interpolate(t, gaitCycle[i].time, gaitCycle[i+1].time, gaitCycle[i].leftKneeAngle, gaitCycle[i+1].leftKneeAngle);
      angles[2] = interpolate(t, gaitCycle[i].time, gaitCycle[i+1].time, gaitCycle[i].rightHipAngle, gaitCycle[i+1].rightHipAngle);
      angles[3] = interpolate(t, gaitCycle[i].time, gaitCycle[i+1].time, gaitCycle[i].rightKneeAngle, gaitCycle[i+1].rightKneeAngle);
      return;
    }
  }
}

#endif
