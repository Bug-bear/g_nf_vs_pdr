#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "kalman.h"
#include "openwsn.h"

// Globals

    //the noise in the system    
    //covariance of the process noise
const float Q[] = {0.58,
                   0.6,
                   0.63,
                   0.53,
                   0.51,
                   0.53,
                   0.5,
                   0.52,
                   0.52,
                   0.5,
                   0.53,
                   0.49,
                   0.57,
                   0.54,
                   0.5,
                   0.51}; 
    //covariance of the observation noise
const float R[] = {2.8,
                   3.47,
                   2.64,
                   2.22,
                   0.6,
                   0.37,
                   0.46,
                   0.57,
                   0.47,
                   0.2,
                   2.51,
                   3.4,
                   3.13,
                   1.61,
                   0.21,
                   0.15}; 
    
    //const float Q = 0.022; 
    //const float R = 0.617;  
    
    //initial values for the kalman filter
    float x_est_last = 0;
    //float P_last = 1;
    float P_last[16] ={1};
    //float K;  //Kalman gain (key to the estimation)
    float K[16];
    
    float P;  //estimate covariance
    float P_temp;
    float x_temp_est;
    float x_est;  //updated estimation (final product)
    float z_measured; //the 'noisy' value we measured
    //float z_real = 0.5; //the ideal value we wish to measure
  
float kalman(float raw, float last, uint8_t index){
//uint32_t kalman(float raw, uint32_t last, uint8_t index){
    //measure
    z_measured = (float)raw;
    
    //srand(0);
    
    //initialize with a measurement
    x_est_last = (float)last;
    
    /*float sum_error_kalman = 0;
    float sum_error_measure = 0;*/
    
    //do a prediction
    x_temp_est = x_est_last;
    //P_temp = P_last + Q;
    //x_temp_est = x_est_last[index];
    P_temp = P_last[index] + Q[index];
    
    //calculate the Kalman gain
    //K = P_temp * (1.0/(P_temp + R));
    K[index] = P_temp * (1.0/(P_temp + R[index]));
    
    //correction
    //x_est = x_temp_est + K * (z_measured - x_temp_est); 
    //P = (1- K) * P_temp;
    x_est = x_temp_est + K[index] * (z_measured - x_temp_est); 
    P = (1- K[index]) * P_temp;
    //we have our new system
        
        /*printf("Ideal    position: %6.3f \n",z_real);
        printf("Mesaured position: %6.3f [diff:%.3f]\n",z_measured,fabs(z_real-z_measured));
        printf("Kalman   position: %6.3f [diff:%.3f]\n",x_est,fabs(z_real - x_est));
        
        sum_error_kalman += fabs(z_real - x_est);
        sum_error_measure += fabs(z_real-z_measured);*/
        
    //update our last's
    //P_last = P;
    x_est_last = x_est;
    P_last[index] = P;
    
      /*printf("Total error if using raw measured:  %f\n",sum_error_measure);
      printf("Total error if using kalman filter: %f\n",sum_error_kalman);
      printf("Reduction in error: %d%% \n",100-(int)((sum_error_kalman/sum_error_measure)*100));*/
    
    return (uint32_t) x_est;
}