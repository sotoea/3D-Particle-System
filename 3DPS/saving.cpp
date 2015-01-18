/*
 Created by Tom Woudenberg and Eduardo Soto
 Monday December 2, 2013
 Assignment 3
 based off of R.Teather lighting code
 
 */
/*
#include "saving.h"
#include "object.h"
//#include "common.h"


#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

string save;


void saveObjects(void)
{
    string final;
    
    string pos1;
    string pos2;
    string pos3;
    string color1;
    string color2;
    string color3;
    string scale1;
    string scale2;
    string scale3;
    string shape;
    string c = ",";
    
    for (int i = 0; i<objectAmount; i++) {
        
        pos1 = std::to_string(objects[i].pos[0]);
        pos2 = std::to_string(objects[i].pos[1]);
        pos3 = std::to_string(objects[i].pos[2]);
        color1 = std::to_string(objects[i].color[0]);
        color2 = std::to_string(objects[i].color[1]);
        color3 = std::to_string(objects[i].color[2]);
        scale1 = std::to_string(objects[i].scale[0]);
        scale2 = std::to_string(objects[i].scale[1]);
        scale3 = std::to_string(objects[i].scale[2]);
        shape = std::to_string(objects[i].shape);
    
    
        final += pos1+c+pos2+c+pos3+c+color1+c+color2+c+color3+c+scale1+c+scale2+c+scale3+c+shape;
        
    }
    save = final;
    
}


void saveGame(void)
{
    string stringInput;
    cout << "Please enter file name: ";
	cin >> stringInput;
    
    
    std::ofstream outfile (stringInput.c_str());
    
    outfile << "test"<< std::endl;
    
    outfile.close();
    
    printf("success");
    
}

*/