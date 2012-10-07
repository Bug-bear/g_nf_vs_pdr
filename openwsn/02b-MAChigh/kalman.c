#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "kalman.h"
#include "openwsn.h"

// Globals

    //the noise in the system    
    const float Q = 0.022; //covariance of the process noise
    const float R = 0.617; //covariance of the observation noise
    
    //const float Q = 0; 
    //const float R = 0;  
    
    //initial values for the kalman filter
    float x_est_last = 0;
    //float P_last = 1;
    float P_last[] ={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    //float K;  //Kalman gain (key to the estimation)
    float K[16];
    
    float P;  //estimate covariance
    float P_temp;
    float x_temp_est;
    float x_est;  //updated estimation (final product)
    float z_measured; //the 'noisy' value we measured
  
float kalman(float raw, float last, uint8_t index){
    //take measure
    z_measured = (float)raw;
    
    //initialize with a measurement
    x_est_last = (float)last;
    x_temp_est = x_est_last;
    //x_temp_est = x_est_last[index];
    
    //do a prediction
    //P_temp = P_last + Q;
    P_temp = P_last[index] + Q;
    
    //calculate the Kalman gain
    //K = P_temp * (1.0/(P_temp + R));
    K[index] = P_temp * (1.0/(P_temp + R));
    
    //correction
    //x_est = x_temp_est + K * (z_measured - x_temp_est); 
    //P = (1- K) * P_temp;
    x_est = x_temp_est + K[index] * (z_measured - x_temp_est); 
    P = (1- K[index]) * P_temp;
    //we have our new system
        
    //update our last's
    //P_last = P;
    //x_est_last = x_est; // no longer needed
    P_last[index] = P;
    
    return x_est;
}