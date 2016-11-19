#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxPostGlitch.h"

//カメラの台数
#define camNUM 2
//30fps*30s=900
#define bufferSize 400
//映像レイヤーエフェクトの数
#define movNum 3

class GuiApp: public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
    void keyPressed(int key);
    void keyReleased(int key);
   

    //いらない。最終的に消す
	ofParameterGroup parameters;
	ofParameter<float> radius;
	ofParameter<ofColor> color;
	ofxPanel gui;
    
    //メモリ管理の関数
    void Memory(int camera);
    bool start = false;
    
    //格納の経過をカウンター。実際はこれをBufferSizeで割ったあまりを用いる。
    int buffer = 0;
    bool DrawFlg[camNUM];
    void DrawFBO(int LorR,int i);
    
    ofVideoGrabber vidGrabber[camNUM];
    ofVideoGrabber check;//カメラのIDの確認用
    int camWidth , camHeight;//動画の描画の縦横の長さ
    ofFbo* fbo[camNUM][bufferSize];//それぞれの動画のFBOを定義
    
    
    //グリッチのインスタンス
    ofxPostGlitch myGlitch[camNUM][bufferSize];
    bool convergence = false;
    bool shaker = false;
    bool cutslider = false;
    bool noise = false;
    bool slitscan = false;
    bool swell = false;
    bool blueraise = false;
    
    
    //カメラの左右の切り替え
    int L = 0;
    int R = 1;
    
    //画面エフェクト
    void Black();
    bool blackFlg = false;
    int center = 0;
    
   
};

