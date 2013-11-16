//
//  Smile.h
//  smiler
//
//  Created by Cameron Browning on 11/16/13.
//
//

#ifndef __smiler__Smile__
#define __smiler__Smile__

#include <iostream>
#include "ofMain.h"

class Smile{

private:
    ofPoint pos;
    float scale;
    float dScale;
    float wait;
    int color;
public:
    
    Smile(float _x, float _y);
    ~Smile();
    void setWait(float _wait);
    void setColor(int _color);
    void update();
    void draw();
    
    
    
};

#endif /* defined(__smiler__Smile__) */
