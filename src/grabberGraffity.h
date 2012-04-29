/*
 *  grabberGraffity.h
 *  musicalALPHAGUI
 *
 *  Created by ignacio garcia on 27/04/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _GRABBER_GRAFFITY
#define _GRABBER_GRAFFITY
#include "ofMain.h"
class grabberGraffity{
public:
	
	ofVideoGrabber grabber;
	
	void setup();
	void update();
	void draw();
};
#endif