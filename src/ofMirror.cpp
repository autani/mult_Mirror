//
//  ofMirror.cpp
//  multiWindowExample
//
//  Created by 諸星智也 on 2016/11/15.
//
//

#include "ofMirror.hpp"

//--------------------------------------------------------------
void ofMirror::setup(){
    ofBackground(255);
    ofSetCircleResolution(200);
    
    
    
}

//--------------------------------------------------------------
void ofMirror::update(){
    
}

//--------------------------------------------------------------
void ofMirror::draw(){
    
    
    
    if(gui->DrawFlg[gui->R]){
        if(counter < gui->fbo[gui->R].size()){
            gui->fbo[gui->R][counter]->draw(0, 0,1125,ofGetHeight());
            cout << "デバッグ " << counter <<endl;
        }else{
            counter = 0;
        }
    }
    counter ++ ;
    
}
