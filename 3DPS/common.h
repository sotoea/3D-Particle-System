/*
 Created by Tom Woudenberg and Eduardo Soto
 Monday December 2, 2013
 Assignment 3
 based off of R.Teather lighting code
 
 */

#ifndef assignment3_common_h
#define assignment3_common_h

#include "object.h"
#include <math.h>

//header of common variables for project

float light_pos[4];
float amb[4];           //light variables

float pos[] = {0,1,0};

float camPos[] = {5, 5, 10};
float angle = 0.0f;         //camera variable

int windowHieght = 800;
int windowWidth = 800;      //window size

int sightLength = 50;       //length of view


object objects[100]; //objects array ie number of objects allowed in scene
int objectAmount = sizeof(objects) / sizeof( objects[0]);

int objectAddNumber = 0;        //starting add point

int currentObject = -1;         //first object selected





#endif
