/*
 *  escena.cpp
 *  musicalBetaAlpha
 *
 *  Created by ignacio garcia on 25/04/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "escena.h"

escena::escena(){
	nombreEscena = "";
	urlVideo = "";
	urlTriggers = "";
	urlMiniaturas = "";
	numFram = 0;
	numEscena = 0;
	tiempo = 0.0;
}
void escena::ponTriggers(ofxTimeline * _linea){
	_linea->setDurationInFrames(numFram);
	//_linea->addTriggers(nombreEscena, urlTriggers);
}
void escena::quitaTriggers(ofxTimeline * _linea){
	//_linea->removeElement(nombreEscena);
}