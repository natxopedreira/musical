/*
 *  escena.h
 *  musicalBetaAlpha
 *
 *  Created by ignacio garcia on 25/04/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _ESCENA
#define _ESCENA
#include "ofMain.h"
#include "ofxTimeline.h"

class escena {
public:
	escena();
	
	string nombreEscena;
	string urlVideo;
	string urlTriggers;
	string urlMiniaturas;
	int numFram;
	float tiempo;
	int numEscena;
	
	void ponTriggers(ofxTimeline * _linea);
	void quitaTriggers(ofxTimeline * _linea);
};

#endif