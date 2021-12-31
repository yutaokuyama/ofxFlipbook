#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    flipbook.setup("images");
    ofSetFrameRate(30);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    flipbook.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    flipbook.draw(0.0,0.0,ofGetWidth(),ofGetHeight());
    
}
