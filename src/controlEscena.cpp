/*
 *  controlEscena.cpp
 *  musicalBetaAlpha
 *
 *  Created by ignacio garcia on 25/04/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "controlEscena.h"

controlEscena::controlEscena(){}

void controlEscena::setup(){
	escenaActual = 0;
	escenaAnterior = 0;
	
	cargaInfo();
	
	linea.setup();
	linea.setWidth(960);
	linea.setOffset(ofVec2f(0,540));
	linea.setLoopType(OF_LOOP_NORMAL);
	linea.setMovePlayheadOnDrag(false);
	linea.setMovePlayheadOnPaste(false);

	for(int c = 0; c<escenas.size(); c++){
		if(c==0){
			/// la primera
			linea.setPageName(escenas.at(c)->nombreEscena);
			linea.addTriggers(escenas.at(c)->nombreEscena, escenas.at(c)->urlTriggers);
		}else{
			linea.addPage(escenas.at(c)->nombreEscena,true);
			linea.addTriggers(escenas.at(c)->nombreEscena, escenas.at(c)->urlTriggers);
		}
	}
	
	linea.setCurrentPage(escenaActual);
	iniciaEscena();
	
	ofAddListener(ofxTLEvents.pageChanged, this, &controlEscena::cambiaPagina);
	
	pausada = true;
}

void controlEscena::update(){
	
/*	if(!pausada){
		//videos.at(escenaActual)->update();
		float tiempoVideo = ((float)videos.at(escenaActual)->getCurrentFrame() / (float)escenas.at(escenaActual)->numFram)*escenas.at(escenaActual)->tiempo;
		linea.setCurrentTime(tiempoVideo);
	}*/
	float tiempoVideo = ((float)videos.at(escenaActual)->getCurrentFrame() / (float)escenas.at(escenaActual)->numFram)*escenas.at(escenaActual)->tiempo;
	linea.setPosicionVideo(tiempoVideo);
//	linea.setCurrentTime(tiempoVideo);
	videos.at(escenaActual)->update();
	
}

void controlEscena::draw(){

	if(videos.at(escenaActual)->isLoaded() && videos.at(escenaActual)->getCurrentFrame()>0){
		videos.at(escenaActual)->draw(ofRectangle(0,0,960,540));
	}else{
		ofRectangle(0,0,960,540);
	}
	ofSetColor(255);
	ofRectangle(0,540,960,200);
	linea.draw();
}
void controlEscena::iniciaEscena(){
	linea.setDurationInSeconds(videos.at(escenaActual)->getDuration());
	
	float tiempoVideo = ((float)videos.at(escenaActual)->getCurrentFrame() / (float)escenas.at(escenaActual)->numFram)*escenas.at(escenaActual)->tiempo;
	linea.setCurrentTime(tiempoVideo);
	
	//linea.setDurationInSeconds(escenas.at(escenaActual)->tiempo);
}
///////////////////
//// eventos //////
///////////////////


void controlEscena::cambiaPagina(ofxTLPageEventArgs & trigger){
	//// siempre se para el videoplayer
	linea.cambiaPagina(trigger.currentPageName, trigger.oldPageName);
	
	escenaActual = trigger.numCurrent;
	escenaAnterior= trigger.numOld;
	
	if(trigger.numCurrent != trigger.numOld){
		if(videos.at(escenaAnterior)->isPlaying()){
			videos.at(escenaAnterior)->stop();
			linea.para();
			pausada = true;
		}
		iniciaEscena();
	}
}


///////
void controlEscena::pausaEscena(){
	if(videos.at(escenaActual)->isPlaying()){
		videos.at(escenaActual)->stop();
	}
	linea.para();
	pausada = true;
}
void controlEscena::reanudaEscena(){
	if(!videos.at(escenaActual)->isPlaying()){
		videos.at(escenaActual)->play();
	}
	linea.corre();
	pausada = false;
}





///////////////////
//// infoXml //////
///////////////////
void controlEscena::cargaInfo(){
	ofxXmlSettings cargaXml;
	
	if(cargaXml.loadFile("escenasXml/escenas.xml")){
		cargaXml.pushTag("escenas");
		int numEscenas = cargaXml.getNumTags("escena");
		for(int i = 0; i < numEscenas; i++){
			cargaXml.pushTag("escena", i);
			
			ofVideoPlayer * v = new ofVideoPlayer();
			videos.push_back(v);
			videos.at(i)->loadMovie(cargaXml.getValue("urlVideo", ""));
			videos.at(i)->setLoopState(OF_LOOP_NORMAL);
			
			escena * s = new escena();
			escenas.push_back(s);
			escenas.at(i)->nombreEscena = cargaXml.getValue("nombreEscena", "");
			escenas.at(i)->urlVideo = cargaXml.getValue("urlVideo", "");
			escenas.at(i)->urlTriggers = cargaXml.getValue("urlTriggers", "");
			escenas.at(i)->numEscena = cargaXml.getValue("numEscena", 0);
			escenas.at(i)->tiempo = cargaXml.getValue("tiempo", .0);
			escenas.at(i)->numFram = cargaXml.getValue("numFrames", 0);
			
			cargaXml.popTag();
		}
		cargaXml.popTag();
	}
	else{
		ofLogError("controlEscenas::cargaEscenas no se puede cargar el xml !!");
	}
}