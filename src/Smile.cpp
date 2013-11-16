//
//  Smile.cpp
//  smiler
//
//  Created by Cameron Browning on 11/16/13.
//
//

#include "Smile.h"

#define MAX_SCALE 25.0f
#define MIN_SCALE 0.25f
/*
 private:
 ofPoint pos;
 float scale;
 float dScale;
 public:
 Smile();
 ~Smile();
 update();
 draw();
*/
Smile::Smile(float _x, float _y){
    pos = ofPoint(_x,_y);
    scale = 0;
    dScale = 0;
    color = ofColor::fromHex(0xffffff);
    dR = r = ofRandom(360.0f)-180.0f;

}
Smile::~Smile(){
    
}
void Smile::setColor(int _color){
    color = ofColor::fromHex(_color);
}
void Smile::registerImage(ofImage * _img_ptr){
    img_ptr = _img_ptr;
}
void Smile::update(){
    wait--;
    if(wait==0){
        scale = MAX_SCALE;
        dScale = MIN_SCALE;
        dR = ofRandom(360.0f)-180.0f;
    }
    scale += (dScale-scale)/16.0f;
    r += (dR-r)/4.0f;
}
void Smile::draw(){
    
    ofEnableAlphaBlending();
    if(wait<=0){
        
        // scale goes 10-1
        // alpha should go 0-1
        // (10-scale)/10
        // 10 - 10 0/10
        // (10 - 1)10
        // 9/10
        
        ofColor newColor = ofColor(color.r,color.g,color.b,255.0f*(MAX_SCALE-scale)/MAX_SCALE);
        ofSetColor(newColor);
        ofPushMatrix();
        ofTranslate(pos);
        ofRotate(r);
        img_ptr->draw(-1*img_ptr->width/2*scale,-1*img_ptr->height/2*scale,img_ptr->width*scale,img_ptr->width*scale);
        //ofCircle(0,0,3.0f*scale);
        ofPopMatrix();
    }
    
}
void Smile::setWait(float _wait){
    wait = _wait;
}