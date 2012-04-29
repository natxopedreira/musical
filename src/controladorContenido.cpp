/*
 *  controladorContenido.cpp
 *  musicalALPHAGUI
 *
 *  Created by ignacio garcia on 27/04/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 
 extiende a la que controla las escenas y el timeline
 aqui se le agrega las escenas dinamicas
 */

#include "controladorContenido.h"

void controladorContenido::inicia(){
	setup();
	graffity.setup();
	
	ofAddListener(ofxTLEvents.trigger, this, &controladorContenido::timelineTriggerReceived);
	
	dentroPainter = false;
	nombreEscena = "";
}

void controladorContenido::actualiza(){
	update();
	graffity.update();
}

void controladorContenido::drawContenido(){
	if(dentroPainter && nombreEscena == escenas.at(escenaActual)->nombreEscena){
		ofSetColor(255);
		graffity.draw();
		ofDrawBitmapString("AQUI UN VIDEOGRABBER\nDEL ORDENADOR DEL GRAFFITY\nDALE A PLAY\nHACE UN LOOP Y VUELVE EL VIDEO", ofPoint(400,220));
	}else {
		draw();
	}
	
	linea.draw();
}

void controladorContenido::timelineTriggerReceived(ofxTLTriggerEventArgs& trigger){
	if(escenas.at(escenaActual)->nombreEscena == trigger.triggerGroupName){
		
		cout << "controladorContenido::timelineTriggerReceived  :: " << trigger.nombre << " :: " << trigger.triggerGroupName << " :: " << endl;
		
		if(trigger.nombre == "dentroPainter"){
			nombreEscena = trigger.triggerGroupName;
			if(dentroPainter){
				iniciaEscena();
				dentroPainter = false;
			}else{
				pausaEscena();
				dentroPainter = true;
			}
		}
	}
}