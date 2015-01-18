/*
 Created by Tom Woudenberg and Eduardo Soto
 Monday December 2, 2013
 Assignment 3
 based off of R.Teather lighting code
 
 */

//References: http://mathworld.wolfram.com/Point-LineDistance3-Dimensional.html, http://geomalgorithms.com/a02-_lines.html, http://www.vuforia.com

#include <GLUT/glut.h>
#include <stdio.h>
#include "figure.h"
#include "common.h"
#include "ray.h"
#include <math.h>
//#include "saving.h"

//saving game and loading game functions
        #include <string.h>
        #include <iostream>
        #include <fstream>
        #include <sstream>

        using namespace std;

        string save;


        void loadGame(void) //function to load a save game file
        {
        ifstream myReadFile;
        string stringInput;
        
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
        string rot1;
        string rot2;
        string rot3;
        string collision;
        string light;
        string intensity;
        string current;
        string add;
        string exists;
            
        
        cout << "Please enter file name: ";
        cin >> stringInput;

        myReadFile.open(stringInput);
        if (myReadFile.is_open()) {
            for (int i = 0; i<objectAmount; i++)
            {
                
                getline(myReadFile,pos1,',');
                objects[i].pos[0] = atof(pos1.c_str());
                getline(myReadFile,pos2,',');
                objects[i].pos[1] = atof(pos2.c_str());
                getline(myReadFile,pos3,',');
                objects[i].pos[2] = atof(pos3.c_str());
                getline(myReadFile,color1,',');
                objects[i].color[0] = atof(color1.c_str());
                getline(myReadFile,color2,',');
                objects[i].color[1] = atof(color2.c_str());
                getline(myReadFile,color3,',');
                objects[i].color[2] = atof(color3.c_str());
                getline(myReadFile,scale1,',');
                objects[i].scale[0] = atof(scale1.c_str());
                getline(myReadFile,scale2,',');
                objects[i].scale[1] = atof(scale2.c_str());
                getline(myReadFile,scale3,',');
                objects[i].scale[2] = atof(scale3.c_str());
                getline(myReadFile,shape,',');
                objects[i].shape = atoi(shape.c_str());
                getline(myReadFile,rot1,',');
                objects[i].rotate[0] = atof(rot1.c_str());
                getline(myReadFile,rot2,',');
                objects[i].rotate[1] = atof(rot2.c_str());
                getline(myReadFile,rot3,',');
                objects[i].rotate[2] = atof(rot3.c_str());
                getline(myReadFile,collision,',');
                objects[i].collisionSize = atof(collision.c_str());
                getline(myReadFile,light,',');
                objects[i].light = atof(light.c_str());
                getline(myReadFile,intensity,',');
                objects[i].intensity = atof(intensity.c_str());
                getline(myReadFile,current,',');
                currentObject = atoi(current.c_str());
                getline(myReadFile,exists,',');
                objects[i].existance = atoi(exists.c_str());
                getline(myReadFile,add,'\n');
                objectAddNumber = atoi(add.c_str());
                
       
            }
            myReadFile.close();
            printf("success");
            glutPostRedisplay();
            
        }
        else{
            printf("no file");
        }
        
    }

        void saveObjects(void) //creates string for save game file
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
            string rot1;
            string rot2;
            string rot3;
            string collision;
            string light;
            string intensity;
            string current;
            string add;
            string exists;
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
                rot1 = std::to_string(objects[i].rotate[0]);
                rot2 = std::to_string(objects[i].rotate[1]);
                rot3 = std::to_string(objects[i].rotate[2]);
                collision = std::to_string(objects[i].collisionSize);
                light = std::to_string(objects[i].light);
                intensity = std::to_string(objects[i].intensity);
                current = std::to_string(currentObject);
                exists = std::to_string(objects[i].existance);
                add = std::to_string(objectAddNumber);
                
                
                
                final += pos1+c+pos2+c+pos3+c+color1+c+color2+c+color3+c+scale1+c+scale2+c+scale3+c+shape+c+rot1+c+rot2+c+rot3+c+collision+c+light+c+intensity+c+current+c+exists+c+add+"\n";
                
            }
            save = final;
            
        }

        void saveGame(void) //creates file and fills with save game string
        {
            string stringInput;
            cout << "Please enter file name: ";
            cin >> stringInput;
            
            
            std::ofstream outfile (stringInput.c_str());
            
            saveObjects();
            
            outfile << save << std::endl;
            
            outfile.close();
            
            printf("success");
            
        }

void reset(void) //clears all object values
{
    for (int i = 0; i<objectAmount; i++) {
        objects[i].pos[0] = NULL;
        objects[i].pos[1] =NULL;
        objects[i].pos[2] = NULL;
        objects[i].scale[0] = NULL;
        objects[i].scale[1] = NULL;
        objects[i].scale[2] = NULL;
        objects[i].color[0] = NULL;
        objects[i].color[1] = NULL;
        objects[i].color[2] = NULL;
        objects[i].rotate[0] = NULL;
        objects[i].rotate[1] = NULL;
        objects[i].rotate[2] = NULL;
        objects[i].light = false;
        objects[i].intensity = NULL;
        objects[i].existance = false;
        objects[i].collisionSize = NULL;
        
        
    }
    objectAddNumber = 0; //resets add point to the beginning
    currentObject = -1; //no object selected
    
}


void sphereConstruct(void) //creates a object of sphere
{
    int i = objectAddNumber;
    
    objects[i].pos[0] = 0;
    objects[i].pos[1] = 0;
    objects[i].pos[2] = 0;
    objects[i].scale[0] = 1;
    objects[i].scale[1] = 1;
    objects[i].scale[2] = 1;
    objects[i].shape = 2;
    objects[i].color[0] = 1;
    objects[i].color[1] = 0;
    objects[i].color[2] = 0;
    objects[i].existance = true;
    objects[i].rotate[0] = 0;
    objects[i].rotate[1] = 0;
    objects[i].rotate[2] = 0;
    
    objects[i].light = false;
    
    
    objectAddNumber += 1;
    if (objectAddNumber>=objectAmount) {
        objectAddNumber = 0;
    }
    
    currentObject = i;
    
}
void figureConstruct(void)  //construct for figure, size is larger due to blender export parameters
{
    int i = objectAddNumber;
    
    objects[i].pos[0] = 0;
    objects[i].pos[1] = 0;
    objects[i].pos[2] = 0;
    objects[i].scale[0] = 1;
    objects[i].scale[1] = 1;
    objects[i].scale[2] = 1;
    objects[i].shape = 5;
    objects[i].color[0] = 1;
    objects[i].color[1] = 0.5;
    objects[i].color[2] = 0;
    objects[i].existance = true;
    objects[i].rotate[0] = 0;
    objects[i].rotate[1] = 0;
    objects[i].rotate[2] = 0;
    
    objects[i].light = false;
    
    
    objectAddNumber += 1;
    if (objectAddNumber>=objectAmount) {
        objectAddNumber = 0;
    }
    
    currentObject = i;
    
}
void cubeConstruct(void) //creates a object of cube
{
   
    int i = objectAddNumber;
    
    objects[i].pos[0] = 0;
    objects[i].pos[1] = 0;
    objects[i].pos[2] = 0;
    objects[i].scale[0] = 1;
    objects[i].scale[1] = 1;
    objects[i].scale[2] = 1;
    objects[i].shape = 1;
    objects[i].color[0] = 0;
    objects[i].color[1] = 1;
    objects[i].color[2] = 0;
    objects[i].existance = true;
    objects[i].rotate[0] = 0;
    objects[i].rotate[1] = 0;
    objects[i].rotate[2] = 0;
    
    objects[i].light = false;
    
    objectAddNumber += 1;
    if (objectAddNumber>=objectAmount) {
        objectAddNumber = 0;
    }
    
    currentObject = i;
    
    
}

void teapotConstruct(void) //creates a object of teapot
{

    int i = objectAddNumber;
    
    objects[i].pos[0] = 0;
    objects[i].pos[1] = 0;
    objects[i].pos[2] = 0;
    objects[i].scale[0] = 1;
    objects[i].scale[1] = 1;
    objects[i].scale[2] = 1;
    objects[i].shape = 3;
    objects[i].color[0] = 0;
    objects[i].color[1] = 1;
    objects[i].color[2] = 0;
    objects[i].existance = true;
    objects[i].rotate[0] = 0;
    objects[i].rotate[1] = 0;
    objects[i].rotate[2] = 0;
    
    objects[i].light = false;
    
    objectAddNumber += 1;
    if (objectAddNumber>=objectAmount) {
        objectAddNumber = 0;
    }
    
    currentObject = i;
    }

void coneConstruct(void) //creates a object of cone
{
   
    int i = objectAddNumber;
    
    objects[i].pos[0] = 0;
    objects[i].pos[1] = 0;
    objects[i].pos[2] = 0;
    objects[i].scale[0] = 1;
    objects[i].scale[1] = 1;
    objects[i].scale[2] = 1;
    objects[i].shape = 4;
    objects[i].color[0] = 0;
    objects[i].color[1] = 1;
    objects[i].color[2] = 0;
    objects[i].existance = true;
    objects[i].rotate[0] = 0;
    objects[i].rotate[1] = 0;
    objects[i].rotate[2] = 0;
    
    objects[i].light = false;
    
    objectAddNumber += 1;
    if (objectAddNumber>=objectAmount) {
        objectAddNumber = 0;
    }
    
    currentObject = i;
    
}

void moveObject(int x, int y,int z) //moves object by x,y,z
{
    int i = currentObject;
    
    objects[i].pos[0] = objects[i].pos[0] + x;
    objects[i].pos[1] = objects[i].pos[1] + y;
    objects[i].pos[2] = objects[i].pos[2] + z;
   
}

void rotateObject(int x, int y, int z) //rotate object by angle (x,y,z)
{
    int i = currentObject;
    
    objects[i].rotate[0] = objects[i].rotate[0] + x;
    objects[i].rotate[1] = objects[i].rotate[1] + y;
    objects[i].rotate[2] = objects[i].rotate[2] + z;
}

/* Get3DPos - takes a mouse x,y coordinate, and a "winz" corresponding to
 *  the depth through the viewing volume at which to determine the 3D point.
 *  returns (via point array) the 3D point corresponding to the distance along
 *  the mouse ray at depth winz
 */
void Get3DPos(int x, int y, float winz, GLdouble point[3])
{
	GLint viewport[4];
	GLdouble modelview[16];
	GLdouble projection[16];
	
	//get the matrices
	glGetDoublev( GL_MODELVIEW_MATRIX, modelview );
	glGetDoublev( GL_PROJECTION_MATRIX, projection );
	glGetIntegerv( GL_VIEWPORT, viewport );
    
	//"un-project" the 2D point giving the 3D position corresponding to the provided depth (winz)
	gluUnProject( (float)x, (float)(viewport[3]-y), winz, modelview, projection, viewport, &point[0], &point[1], &point[2]);
}

bool checkCollidion2(float p[3], ray newRay, float degree) //checks if ray hits bounding sphere of object
{
    float dist = sqrt(pow(p[0]-newRay.org[0],2)+pow(p[1]-newRay.org[1],2)+pow(p[2]-newRay.org[2],2));
    bool hello;
    
    hello = false;
    for(int i = 0; i<10000; i++){           //It will check for collisions at one point and advance to the next until it hits an object
        
        if(dist > degree){
            
            newRay.org[0] += newRay.dir[0];
            newRay.org[1] += newRay.dir[1];
            newRay.org[2] += newRay.dir[2];
            dist = sqrt(pow(p[0]-newRay.org[0],2)+pow(p[1]-newRay.org[1],2)+pow(p[2]-newRay.org[2],2));
            //printf("%f\n",dist);
        }
        else if(dist<=degree){ //If the dist between current ray position and object position is less than degree then its a hit
            hello = true;
        }
    }
    return hello;
}

/* rayCast - takes a mouse x,y, coordinate, and casts a ray through that point
 *   for subsequent intersection tests with objects.
 */
void rayCast(int x, int y) //casts a ray through the scene checking it with every object
{
	GLdouble pNear[3];
	GLdouble pFar[3]; //declare the two points
    
	//get 3D position of mouse cursor on near and far clipping planes
	Get3DPos(x, y, 0.0, pNear);
	Get3DPos(x, y,1 , pFar);
    
	//create a ray originating at the camera position, and using the vector between the two points for the direction
	ray newRay;
	newRay.org[0] = camPos[0];
	newRay.org[1] = camPos[1];
	newRay.org[2] = camPos[2];
	
	//ray direction is the vector (pFar - pNear)
	newRay.dir[0] = pFar[0] - pNear[0];
	newRay.dir[1] = pFar[1] - pNear[1];
	newRay.dir[2] = pFar[2] - pNear[2];
    
	//normalize the ray direction
	normalize(newRay.dir);
    

    
    for(int i=0; i<objectAmount; i++){
        //printf("WW %f\n,EE %f\n,RR %f\n",objects[i].pos[0],objects[i].pos[1],objects[i].pos[2]);
        if(checkCollidion2(objects[i].pos, newRay, objects[i].collisionSize+1)){
             currentObject = i;
            if (!objects[i].existance) {
                currentObject = -1;
            }
            break;
           
        }
        
        else{
            currentObject = -1;
        }
    }}

void scalelarger(void) //increase size of current object or increase intensity of current light
{
    
    int i = currentObject;

    if (objects[i].light) {
        objects[i].intensity += 2;
    }
    else{
        objects[i].scale[0] = objects[i].scale[0] + 0.1;
        objects[i].scale[1] = objects[i].scale[1] + 0.1;
        objects[i].scale[2] = objects[i].scale[2] + 0.1;
        objects[i].collisionSize += 0.1;
    }}

void scalesmaller(void) //decrease size of current object or decrease intensity of current light
{
    int i = currentObject;
    
    if (objects[i].light) {
        objects[i].intensity -= 2;
    }
    else{
        objects[i].scale[0] = objects[i].scale[0] - 0.1;
        objects[i].scale[1] = objects[i].scale[1] - 0.1;
        objects[i].scale[2] = objects[i].scale[2] - 0.1;
        objects[i].collisionSize -= 0.1;
    }}

void changeColor(void) //sets current object to random color
{
    int i = currentObject;
    if ((i>-1) & objects[i].existance)
    {
        objects[i].color[0] = (float)rand()/((float)RAND_MAX/(1));;;
        objects[i].color[1] = (float)rand()/((float)RAND_MAX/(1));;;
        objects[i].color[2] = (float)rand()/((float)RAND_MAX/(1));;;
    }
}

void deleteObject(void) //removes current object
{
    
    if ((currentObject>-1 )& objects[currentObject].existance) {

    for (int i = currentObject; i<objectAmount-1; i++) //shifts all objects down array removing current object
    {
        objects[i].existance = objects[i+1].existance;
        objects[i].collisionSize=objects[i+1].collisionSize;
        objects[i].color[0] = objects[i+1].color[0];
        objects[i].color[1] =  objects[i+1].color[1];
        objects[i].color[2] = objects[i+1].color[2];
        objects[i].pos[0] = objects[i+1].pos[0];
        objects[i].pos[1] = objects[i+1].pos[1];
        objects[i].pos[2] = objects[i+1].pos[2];
        objects[i].scale[0] = objects[i+1].scale[0];
        objects[i].scale[1] = objects[i+1].scale[1];
        objects[i].scale[2] = objects[i+1].scale[2];
        objects[i].rotate[0] = objects[i+1].rotate[0];
        objects[i].rotate[1] = objects[i+1].rotate[1];
        objects[i].rotate[2] = objects[i+1].rotate[2];
        objects[i].shape = objects[i+1].shape;
        objects[i].light = objects[i+1].light;
        objects[i].intensity = objects[i+1].intensity;
    }
        
        //sets last object to NULL
    objects[objectAmount-1].existance = false;
    objects[objectAmount-1].collisionSize= NULL;
    objects[objectAmount-1].color[0] = NULL;
    objects[objectAmount-1].color[1] = NULL;
    objects[objectAmount-1].color[2] = NULL;
    objects[objectAmount-1].pos[0] = NULL;
    objects[objectAmount-1].pos[1] = NULL;
    objects[objectAmount-1].pos[2] = NULL;
    objects[objectAmount-1].scale[0] = NULL;
    objects[objectAmount-1].scale[1] = NULL;
    objects[objectAmount-1].scale[2] = NULL;
    objects[objectAmount-1].rotate[0] = NULL;
    objects[objectAmount-1].rotate[1] = NULL;
    objects[objectAmount-1].rotate[2] = NULL;
    objects[objectAmount-1].shape = NULL;
        objects[objectAmount-1].light = false;
        objects[objectAmount-1].intensity = NULL;
    
        //finds first null object and sets add marker there
        for (int i = currentObject; i<objectAmount; i++) {
            if (!objects[i].existance) {
                objectAddNumber = i;
                break;
            }
        }
    currentObject = -1;  // no object selected after delete
    
    }
}

void createLight(void) //creates a light object
{
    int i = objectAddNumber;
    
    objects[i].pos[0] = 0;
    objects[i].pos[1] = 0;
    objects[i].pos[2] = 0;
    objects[i].scale[0] = 0.1;
    objects[i].scale[1] = 0.1;
    objects[i].scale[2] = 0.1;
    objects[i].shape = 2;
    objects[i].color[0] = 0;
    objects[i].color[1] = 1;
    objects[i].color[2] = 1;
    objects[i].existance = true;
    objects[i].rotate[0] = 0;
    objects[i].rotate[1] = 0;
    objects[i].rotate[2] = 0;
    
    objects[i].light = true;
    
    
    objectAddNumber += 1;
    if (objectAddNumber>=objectAmount) {
        objectAddNumber = 0;
    }
    
    currentObject = i;

    
    
}

void mouse(int btn, int state, int x, int y) //mouse function
{
    /* flip the 'y' coordinate, to match the OpenGL coordinate system */
	//y = windowHieght - y;
    
	if(btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) //changes selected object
	{
        rayCast(x,y);
	}
	if(btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) //changes selected object then deletes it imidiatly
	{
        rayCast(x,y);
        deleteObject();
	}
    glutPostRedisplay();
    
}

void keyboard(unsigned char key, int x, int y) //keyboard setup
{
    
	/* key presses move the cube, if it isn't at the extents (hard-coded here) */
	switch (key)
	{
            
		case 'a':
		case 'A':
            moveObject(-1,0,0);
			break;
            
		case 'w':
		case 'W':
            moveObject(0,1,0);
			break;
            
		case 'd':
		case 'D':
            moveObject(1,0,0);
			break;
            
		case 's':
		case 'S':
            moveObject(0,-1,0);
			break;
            
        case 'z':
        case 'Z':
            moveObject(0,0,1);
            break;
            
        case 'x':
        case 'X':
            moveObject(0,0,-1);
            break;
            
		case 'r':
        case 'R':
			reset();
			break;
        case '5':
            figureConstruct();
            break;
		case '1':
			sphereConstruct();
			break;
            
        case '2':
			cubeConstruct();
			break;
            
        case '3':
            teapotConstruct();
            break;
            
        case '4':
            coneConstruct();
            break;
            
        case '0':
            createLight();
            break;
            
        case 'k':
        case 'K':
            saveGame();
            break;
            
        case 'l':
        case 'L':
            loadGame();
            break;
            
        case 'q':
		case 'Q':
			scalesmaller();
			break;
            
        case 'e':
        case 'E':
            scalelarger();
            break;
            
        case 'c':
        case 'C':
            changeColor();
            break;
            
        case ',':
            rotateObject(0, 2, 0);
            break;
            
        case '.':
            rotateObject(0,-2,0);
            break;
            
        case '-':
            rotateObject(2,0,0);
            break;
            
        case '=':
            rotateObject(-2,0,0);
            break;
            
        case '[':
            rotateObject(0,0,2);
            break;
            
        case ']':
            rotateObject(0,0,-2);
            break;
          
	}
    
	glutPostRedisplay();
}

void special(int key, int x, int y) //special key setup
{
	/* arrow key presses move the camera */
	switch(key)
	{
		case GLUT_KEY_LEFT:
			camPos[0]-=0.1;
			break;
            
		case GLUT_KEY_RIGHT:
			camPos[0]+=0.1;
			break;
            
		case GLUT_KEY_UP:
			camPos[2] -= 0.1;
			break;
            
		case GLUT_KEY_DOWN:
			camPos[2] += 0.1;
			break;
            
		case GLUT_KEY_HOME:
			camPos[1] += 0.1;
			break;
            
		case GLUT_KEY_END:
			camPos[1] -= 0.1;
			break;
            
	}
	glutPostRedisplay();
}

void init(void) //initial setup commands
{
	glClearColor(0, 0, 0, 0);
	glColor3f(1, 1, 1);
    
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
    
	//float amb[4] = {1.0, 1, 1, 1};
	float diff[4] = {1,1,1, 1};
	float spec[4] = {1,1,1, 1};
    
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diff);
	glLightfv(GL_LIGHT1, GL_AMBIENT, amb);
	glLightfv(GL_LIGHT1, GL_SPECULAR, spec);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, diff);
	glLightfv(GL_LIGHT2, GL_AMBIENT, amb);
	glLightfv(GL_LIGHT2, GL_SPECULAR, spec);
    glLightfv(GL_LIGHT3, GL_DIFFUSE, diff);
	glLightfv(GL_LIGHT3, GL_AMBIENT, amb);
	glLightfv(GL_LIGHT3, GL_SPECULAR, spec);
    glLightfv(GL_LIGHT4, GL_DIFFUSE, diff);
	glLightfv(GL_LIGHT4, GL_AMBIENT, amb);
	glLightfv(GL_LIGHT4, GL_SPECULAR, spec);
    glLightfv(GL_LIGHT5, GL_DIFFUSE, diff);
	glLightfv(GL_LIGHT5, GL_AMBIENT, amb);
	glLightfv(GL_LIGHT5, GL_SPECULAR, spec);
    glLightfv(GL_LIGHT6, GL_DIFFUSE, diff);
	glLightfv(GL_LIGHT6, GL_AMBIENT, amb);
	glLightfv(GL_LIGHT6, GL_SPECULAR, spec);
    glLightfv(GL_LIGHT7, GL_DIFFUSE, diff);
	glLightfv(GL_LIGHT7, GL_AMBIENT, amb);
	glLightfv(GL_LIGHT7, GL_SPECULAR, spec);
    
 
    
    
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45, 1, 1, sightLength);
    
}

void drawObjects(void) //draws all objects to screen
{
    for (int i = 0; i<objectAmount; i++) {
        glPushMatrix(); //sets orgin as draw point
        
        float m_dif[] = {objects[i].color[0], objects[i].color[1],objects[i].color[2], 1.0}; //color
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, m_dif);
        
        glTranslatef(objects[i].pos[0],objects[i].pos[1],objects[i].pos[2]);//postion
        
        glScalef(objects[i].scale[0], objects[i].scale[1], objects[i].scale[2]); //size
        
        glRotatef(objects[i].rotate[0], 1, 0, 0);
        glRotatef(objects[i].rotate[1], 0, 1, 0);
        glRotatef(objects[i].rotate[2], 0, 0, 1);//rotation
        
        
        if (objects[i].shape == 1){  //cube
            glutSolidCube(1);
        }
        if (objects[i].shape == 2){  //sphere
            glutSolidSphere(1, 100, 100);
        }
        if (objects[i].shape ==3){ //teapot
            glutSolidTeapot(1);
        }
        if (objects[i].shape ==4){ //cone
            glutSolidCone(1, 1, 10, 10);
        }
        if (objects[i].shape==5){
            glRotatef(180, 0, 1, 0);
            
            glBegin(GL_TRIANGLES);                      //Draws each triangle face corresponding to each vertex in the file figure.h
            for(int i =0; i<=figureNumVerts; i +=3){
                
                glVertex3f(figureVerts[i], figureVerts[i+1],figureVerts[i+2]);
            }
            glEnd();
        }
        glPopMatrix(); //resets orgin for next object
    }
    
}

void drawSelected(void) // draw the selector orb
{
    int i = currentObject;
    
    if ((i>-1) & objects[i].existance) { //checks object is selected
    
    float selectorPosition = objects[i].pos[1];
    
    selectorPosition = selectorPosition+objects[i].scale[1];
    
    selectorPosition = selectorPosition + 1;  //selector position = above the object y+scale
    
    glPushMatrix(); //sets draw point to orgin
    
    float m_dif[] = {1, 0, 0, 1.0};
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, m_dif);
    
    glTranslated(objects[i].pos[0],selectorPosition,objects[i].pos[2]); //position
    glScaled(0.1, 0.1, 0.1);  //size
    
    glutSolidSphere(1, 10, 10);
    
    glPopMatrix(); //resets to origin for next object
    }
    
}

void drawLight(void) //draws lights to scene
{
    int lightcount = 0;  //lights in scene max = 7
    glDisable(GL_LIGHT1);
    glDisable(GL_LIGHT2);
    glDisable(GL_LIGHT3);
    glDisable(GL_LIGHT4);
    glDisable(GL_LIGHT5);
    glDisable(GL_LIGHT6);
    glDisable(GL_LIGHT7); //disables all lights
    for (int i = 0; i < objectAmount; i++)
    {
        if (objects[i].light) {  //checks all objects to see if light
           
            if (lightcount == 0) {
                light_pos[0] = objects[i].pos[0];
                light_pos[1] = objects[i].pos[1];
                light_pos[2] = objects[i].pos[2];
                light_pos[3] = 1;                   //sets position
                float j = objects[i].intensity;
                amb[0] = 1+objects[i].intensity;
                amb[0] = 1+objects[i].intensity;
                amb[0] = 1+objects[i].intensity;
                amb[0] = 1+objects[i].intensity;
                glLightfv(GL_LIGHT1, GL_AMBIENT, amb); //sets intensity
                glLightfv(GL_LIGHT1, GL_POSITION, light_pos);
               
                glEnable(GL_LIGHT1); //turns on light
            }
            if (lightcount == 1) {
                light_pos[0] = objects[i].pos[0];
                light_pos[1] = objects[i].pos[1];
                light_pos[2] = objects[i].pos[2];
                light_pos[3] = 1;
                float j = objects[i].intensity;
                amb[0] = 1+objects[i].intensity;
                amb[0] = 1+objects[i].intensity;
                amb[0] = 1+objects[i].intensity;
                amb[0] = 1+objects[i].intensity;
                glLightfv(GL_LIGHT2, GL_AMBIENT, amb);
                glLightfv(GL_LIGHT2, GL_POSITION, light_pos);
                glEnable(GL_LIGHT2);
            }
            if (lightcount == 2) {
                light_pos[0] = objects[i].pos[0];
                light_pos[1] = objects[i].pos[1];
                light_pos[2] = objects[i].pos[2];
                light_pos[3] =  1;
                float j = objects[i].intensity;
                amb[0] = 1+objects[i].intensity;
                amb[0] = 1+objects[i].intensity;
                amb[0] = 1+objects[i].intensity;
                amb[0] = 1+objects[i].intensity;
                glLightfv(GL_LIGHT3, GL_AMBIENT, amb);
                glLightfv(GL_LIGHT3, GL_POSITION, light_pos);
                glEnable(GL_LIGHT3);
            }
            if (lightcount == 3) {
                light_pos[0] = objects[i].pos[0];
                light_pos[1] = objects[i].pos[1];
                light_pos[2] = objects[i].pos[2];
                light_pos[3] = 1;
                float j = objects[i].intensity;
                amb[0] = 1+objects[i].intensity;
                amb[0] = 1+objects[i].intensity;
                amb[0] = 1+objects[i].intensity;
                amb[0] = 1+objects[i].intensity;
                glLightfv(GL_LIGHT4, GL_AMBIENT, amb);
                glLightfv(GL_LIGHT4, GL_POSITION, light_pos);
                glEnable(GL_LIGHT4);
            }
            if (lightcount == 4) {
                light_pos[0] = objects[i].pos[0];
                light_pos[1] = objects[i].pos[1];
                light_pos[2] = objects[i].pos[2];
                light_pos[3] = 1;
                float j = objects[i].intensity;
                amb[0] = 1+objects[i].intensity;
                amb[0] = 1+objects[i].intensity;
                amb[0] = 1+objects[i].intensity;
                amb[0] = 1+objects[i].intensity;
                glLightfv(GL_LIGHT5, GL_AMBIENT, amb);
                glLightfv(GL_LIGHT5, GL_POSITION, light_pos);
                glEnable(GL_LIGHT5);
            }
            if (lightcount == 5) {
                light_pos[0] = objects[i].pos[0];
                light_pos[1] = objects[i].pos[1];
                light_pos[2] = objects[i].pos[2];
                light_pos[3] = 1;
                float j = objects[i].intensity;
                amb[0] = 1+objects[i].intensity;
                amb[0] = 1+objects[i].intensity;
                amb[0] = 1+objects[i].intensity;
                amb[0] = 1+objects[i].intensity;
                glLightfv(GL_LIGHT6, GL_AMBIENT, amb);
                glLightfv(GL_LIGHT6, GL_POSITION, light_pos);
                glEnable(GL_LIGHT6);
                
            }
            if (lightcount == 6) {
                light_pos[0] = objects[i].pos[0];
                light_pos[1] = objects[i].pos[1];
                light_pos[2] = objects[i].pos[2];
                light_pos[3] = 1;
                float j = objects[i].intensity;
                amb[0] = 1+objects[i].intensity;
                amb[0] = 1+objects[i].intensity;
                amb[0] = 1+objects[i].intensity;
                amb[0] = 1+objects[i].intensity;
                glLightfv(GL_LIGHT7, GL_AMBIENT, amb);
                glLightfv(GL_LIGHT7, GL_POSITION, light_pos);
                glEnable(GL_LIGHT7);
            }
            if (lightcount > 6) {
                printf("too many lights in scene");
            }
            lightcount +=1;
            
        }
    }
}

/* display function - GLUT display callback function
 *		clears the screen, sets the camera position, draws the ground plane and movable box
 */
void display(void)
{
    glClearColor(0.5, 0.7, 0.1, 0.1);
	float origin[] = {0,0,0,1};
	float m_amb[] = {0.33, 0.22, 0.03, 1.0};
	float m_dif[] = {0.78, 0.57, 0.11, 1.0};
	float m_spec[] = {0.99, 0.91, 0.81, 1.0};
	float shiny = 27;
    
    
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
    
	gluLookAt(camPos[0], camPos[1], camPos[2], 0,0,0, 0,1,0);
	glColor3f(1,1,1);
    
    
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, m_amb);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, m_dif);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, m_spec);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shiny);
    
    drawLight();
    drawObjects();
    drawSelected();
    
    
	
	glutSwapBuffers();
}

/* main function - program entry point */
int main(int argc, char** argv)
{

    
	glutInit(&argc, argv);		//starts up GLUT
	
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	
	
	glutInitWindowSize(windowWidth  , windowHieght);
	glutInitWindowPosition(100, 100);
    
	glutCreateWindow("Assignment 3");	//creates the window
    

	glutDisplayFunc(display);	//registers "display" as the display callback function
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(special);
    glutMouseFunc(mouse);
    
	glEnable(GL_DEPTH_TEST);
	init();
    
	glutMainLoop();				//starts the event loop
    
	return(0);					//return may not be necessary on all compilers
}