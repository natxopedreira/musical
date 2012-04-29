#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	ofBackground(0);
	
	contenido.inicia();
	
	anchoRes = 1920;
	altoRes = 1080;
	
	salida.allocate(anchoRes, altoRes);
}

//--------------------------- -----------------------------------
void testApp::update(){
	contenido.actualiza();
	
}
//--------------------------------------------------------------
void testApp::draw(){
	salida.begin();
	ofClear(0);
	contenido.drawContenido();
	salida.end();
	
	ofSetColor(255);
	salida.draw(0, 0);
	
	
	ofDrawBitmapString(ofToString(ofGetFrameRate()), ofPoint(100,100));
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	if(key == ' '){
		if(contenido.pausada){
			contenido.reanudaEscena();
		}else{
			contenido.pausaEscena();
		}
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
