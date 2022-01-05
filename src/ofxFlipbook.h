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
    
    void draw(const glm::vec2 position=glm::vec2(0.0)) const {
        
        currentImage.draw(position);
    }
    
    void draw(const float x,const float y,const float w,const float h) const {
        
        currentImage.draw(x,y,w,h);
    }
    
    
    const ofTexture &getTexure() const {
        currentImage.getTexture();
    }
    ofTexture &getTexure() {
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
    
    void setFrame(const size_t frame){
        currentFrame = frame;
        checkloop();
        loadCurrentImage();
    }
    
    size_t getTotalFrame(){
        return dir.size();
    }
    
private:
    ofDirectory dir;
    ofImage currentImage;
    size_t currentFrame = 0;
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
