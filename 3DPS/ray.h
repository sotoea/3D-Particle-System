/*
 Created by Tom Woudenberg and Eduardo Soto
 Monday December 2, 2013
 Assignment 3
 based off of R.Teather lighting code
 
 */

#ifndef __assignment3__ray__
#define __assignment3__ray__

#include <iostream>

//ray cast information is stored here

typedef struct
{
	float org[3];
    float dir[3];
    
}ray;

void normalize(float dir[3]);

#endif /* defined(__assignment3__ray__) */
