/*
 Created by Tom Woudenberg and Eduardo Soto
 Monday December 2, 2013
 Assignment 3
 based off of R.Teather lighting code
 
 */

#ifndef __assignment3__object__
#define __assignment3__object__

#include <iostream>

//objects information is stored in this structure

typedef struct
{
    bool existance = false;
	float pos[3];
    float color[3];
    float scale[3];
    int shape;
    float collisionSize = 0;
    float rotate[3];
    int light = 0;
    float intensity = 1;
    
    
}object;



#endif /* defined(__assignment3__object__) */
