/*
 *  grabberGraffity.cpp
 *  musicalALPHAGUI
 *
 *  Created by ignacio garcia on 27/04/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "grabberGraffity.h"

void grabberGraffity::setup(){
	grabber.initGrabber(960, 540,25);
}

void grabberGraffity::update(){
	grabber.update();
}

void grabberGraffity::draw(){
	grabber.draw(0,0);
}