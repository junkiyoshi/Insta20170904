#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(30);
	ofBackground(255);
	ofSetWindowTitle("Insta");

	// ofNoFill();

	this->noise_source = ofRandom(10);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	this->cam.begin();
	
	float radius = 300;
	int deg_span = 8;
	
	float tmp_noise_source = this->noise_source;
	float noise_step = 0.05;

	float x, y, x_1, x_2, y_1, y_2;
	float tmp_radius;

	ofColor body_color;

	for (int i = 0; i < 360; i += deg_span) {

		x = radius * cos(i * DEG_TO_RAD);
		y = radius * sin(i * DEG_TO_RAD);

		tmp_radius = radius * ofNoise(x * 0.0025, y * 0.0025, ofGetFrameNum() * noise_step);

		x_1 = tmp_radius * cos((i - deg_span / 2) * DEG_TO_RAD);
		y_1 = tmp_radius * sin((i - deg_span / 2) * DEG_TO_RAD);
		
		x_2 = tmp_radius * cos((i + deg_span / 2) * DEG_TO_RAD);
		y_2 = tmp_radius * sin((i + deg_span / 2) * DEG_TO_RAD);

		body_color.setHsb(i / 360.f * 255.f, 255, 255);
		ofSetColor(body_color);

		ofBeginShape();

		ofVertex(0, 0);
		ofVertex(x_1, y_1);
		ofVertex(x_2, y_2);

		ofEndShape(true);

		tmp_noise_source += noise_step;
	}

	this->noise_source += noise_step;

	this->cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}


//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
