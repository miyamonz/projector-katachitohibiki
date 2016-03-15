#include "ofApp.h"

class Hamon {
public:
    ofPoint p;
    radius = 0;
    Hamon(){
        
    }
    draw(){
        ofNoFill();
        ofSetLineWidth(5);
        ofSetResolution(40);
        ofDrawCircle(p,radius);
        radius += 10;
    }
};

void ofApp::draw0(vector<ofPoint> points){
}
void ofApp::draw1(vector<ofPoint> points){
    if(bang) {
        bang = false;
    }
    
}
void ofApp::draw2(vector<ofPoint> points){
}
void ofApp::draw3(vector<ofPoint> points){
}
void ofApp::draw4(vector<ofPoint> points){
}
void ofApp::draw5(vector<ofPoint> points){
}


