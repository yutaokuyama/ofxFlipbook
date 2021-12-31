#pragma once

#include "ofMain.h"
#include "ofxFlipbook.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    ofxFlipbook flipbook;
    
    
    
};
