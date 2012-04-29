/*
 *  controlEscena.h
 *  musicalBetaAlpha
 *
 *  Created by ignacio garcia on 25/04/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _CONTROL_ESCENA
#define _CONTROL_ESCENA
#include "ofMain.h"
#include "ofxTimeline.h"
#include "ofxXmlSettings.h"
#include "escena.h";

class controlEscena {
public:
	controlEscena();
	
	void cargaInfo();
	
	void setup();
	void update();
	void draw();
	
	void keyPressed  (int key);

	void iniciaEscena();
	
	void pausaEscena();
	void reanudaEscena();
	
	
	void cambiaPagina(ofxTLPageEventArgs & trigger);
	
	bool pausada;
	
	ofxTimeline linea;
	vector<ofVideoPlayer*> videos;
	vector<escena*> escenas;
	
	int escenaActual,escenaAnterior;
	
};

#endif