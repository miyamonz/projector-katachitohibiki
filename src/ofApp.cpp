#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    warper.setSourceRect(ofRectangle(0,0,w,h));
    warper.setCorner(ofPoint(0,0),0);
    warper.setCorner(ofPoint(w,0),1);
    warper.setCorner(ofPoint(w,h),2);
    warper.setCorner(ofPoint(0,h),3);
    warper.setup();
    
    receiver.setup(3015);
    fbo.allocate(w,h);
}

//--------------------------------------------------------------
void ofApp::update(){

    while(receiver.hasWaitingMessages()){
        ofxOscMessage m;
        receiver.getNextMessage(m);
        //senderLocal.sendMessage(m);
        
        if(m.getAddress() == "/projector/scene"){
            currentScene = m.getArgAsInt(0);
        }
        if(m.getAddress() == "/projector/num"){
            currentNum = m.getArgAsInt(0);
        }
        if(m.getAddress() == "projector/bang"){
            bang = true;
        }
        if(m.getAddress() == "/labels" ){
            labels.resize(m.getArgAsInt(0));
            for(int i=0; i<labels.size(); i++){
                labels[i] = m.getArgAsInt(1+i);
                ofLog() << "labels: " << labels[i];
            }
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    
    //======================== draw image into fbo.
    fbo.begin();
    ofSetColor(0);
    ofDrawRectangle(0, 0, w, h);//fbo.clear();
    ofSetColor(255);
    fbo.end();
    
    //======================== get our quad warp matrix.
    ofMatrix4x4 mat = warper.getMatrix();
    
    //======================== use the matrix to transform our fbo.
    ofSetBackgroundColor(0);
    ofPushMatrix();
    ofMultMatrix(mat);
    fbo.draw(0, 0);
    ofPopMatrix();
    

    //======================== draw quad warp ui.
    ofSetColor(ofColor::magenta);
    warper.drawQuadOutline();
    ofSetColor(ofColor::yellow);
    warper.drawCorners();
    ofSetColor(ofColor::magenta);
    warper.drawHighlightedCorner();
    ofSetColor(ofColor::red);
    warper.drawSelectedCorner();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 's' || key == 'S') {
        warper.toggleShow();
    }
    
    if(key == 'l' || key == 'L') {
        warper.load();
    }
    
    if(key == 'h' || key == 'H') {
        warper.save();
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
