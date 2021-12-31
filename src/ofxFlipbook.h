#pragma once

#include "ofMain.h"


class ofxFlipbook{
public:
    ofxFlipbook(){}
    ofxFlipbook(const std::string& dirName){
        setup(dirName);
        
    }
    void setup(const std::string& dirName){
        dir.open(dirName);
        dir.sort();
        assert(dir.size()>0);
    }
    
    void update(){
        currentFrame++;
        checkloop();
        loadCurrentImage();
    }
    
    void  checkloop() {
        if(currentFrame >= dir.size()){
            loopVideo();
        }
    }
    
    void draw(const glm::vec2 position=glm::vec2(0.0)){
        
        currentImage.draw(position);
    }
    
    void draw(const int x,const int y,const int w,const int h) {
        
        currentImage.draw(x,y,w,h);
    }
    
    
    ofTexture getTexure() {
        currentImage.getTexture();
    }
    
    float getPosition() const{
        return float(currentFrame)/dir.size();
    }
    int getCurrentFrame() const{
        return currentFrame;
    }
    
    void setLoopType(const ofLoopType type){
        loopType = type;
    }
    
    void setPosition(const float position){
        int frame = position * dir.size();
        currentFrame = frame;
        checkloop();
    }
    
    void setFrame(const int frame){
        currentFrame = frame;
        checkloop();
        loadCurrentImage();
    }
    
    int getTotalFrame(){
        return dir.size();
    }
    
private:
    ofDirectory dir;
    ofImage currentImage;
    int currentFrame = 0;
    ofLoopType loopType = OF_LOOP_NORMAL;
    
    void loopVideo(){
        switch(loopType){
            case OF_LOOP_NORMAL:
                currentFrame = 0;
                return currentFrame;
            case OF_LOOP_NONE:
                return;
            case OF_LOOP_PALINDROME:
                ofLogError("Not Implemented Error.");
                return;
        }
    }
    
    ofImage loadCurrentImage(){
        if(OF_LOOP_NONE && currentFrame >= dir.size()){
            currentImage.load(dir.getFile(dir.size()-1).getAbsolutePath());
            return currentImage;
        }
        currentImage.load(dir.getFile(currentFrame).getAbsolutePath());
        return currentImage;
    }
};
