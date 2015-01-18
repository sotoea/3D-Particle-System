/*
 Created by Tom Woudenberg and Eduardo Soto
 Monday December 2, 2013
 Assignment 3
 based off of R.Teather lighting code
 
 */

#include "ray.h"
#include <math.h>


//sets the direction to a normalized amount sqrt(x^2+y^2+z^2)
void normalize(float dir[3])
{

    float mag = sqrtf((dir[0]*dir[0])+(dir[1]*dir[1])+(dir[2]*dir[2]));

    
    dir[0] = dir[0]/mag;
    dir[1] = dir[1]/mag;
    dir[2] = dir[2]/mag;
    
}