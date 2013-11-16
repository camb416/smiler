//
//  Smile.cpp
//  smiler
//
//  Created by Cameron Browning on 11/16/13.
//
//

#include "Smile.h"
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
    color = 0xffffff;
}
Smile::~Smile(){
    
}
void Smile::setColor(int _color){
    color = _color;
}
void Smile::update(){
    wait--;
    if(wait==0){
        scale = 5.0f;
        dScale = 1.0f;
    }
    scale += (dScale-scale)/16.0f;
}
void Smile::draw(){
    if(wait<=0){
        ofSetHexColor(color);
        ofCircle(pos,3.0f*scale);
    }
    
}
void Smile::setWait(float _wait){
    wait = _wait;
}