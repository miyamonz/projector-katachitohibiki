#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "ofxQuadWarp.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    void draw0(vector<ofPoint> points);
    void draw1(vector<ofPoint> points);
    void draw2(vector<ofPoint> points);
    void draw3(vector<ofPoint> points);
    void draw4(vector<ofPoint> points);
    void draw5(vector<ofPoint> points);
    

    int w = 640;
    int h = 480;

    ofxQuadWarp warper;
    ofFbo fbo;
    
    ofxOscReceiver receiver;
    vector<int> labels;
    
    bool bang = false;
    int currentScene;
    int currentNum;
};
