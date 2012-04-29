/*
 *  controladorContenido.h
 *  musicalALPHAGUI
 *
 *  Created by ignacio garcia on 27/04/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 
 extiende a controleEscena que controla las escenas y el timeline
 aqui se le agrega las escenas dinamicas
 */

#ifndef _CONTROLADOR_CONTENIDO
#define _CONTROLADOR_CONTENIDO
#include "ofMain.h"
#include "controlEscena.h"
#include "grabberGraffity.h"

class controladorContenido : public controlEscena {
public:
	void inicia();
	void actualiza();
	void timelineTriggerReceived(ofxTLTriggerEventArgs& trigger);
	
	void drawContenido();
	
	bool dentroPainter;
	grabberGraffity graffity;
	string nombreEscena;
};


#endif