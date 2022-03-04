#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofBackground(255,255,255);
	ofSetVerticalSync(true);
	frameByframe = false;

	// Uncomment this to show movies with alpha channels
	// fingerMovie.setPixelFormat(OF_PIXELS_RGBA);

    //SHADERS
    // blurH.load("HorizontalBlur");
    // keystone.load("Keystone");

    // WARPER
    warper.setup(0, 0, ofGetWidth(), ofGetHeight());
    warper.activate();
    warper.drawSettings.bDrawRectangle = true;
    ofBackground(20, 20, 20);

    //FBO
    framebuffer.allocate(ofGetWidth(), ofGetHeight());
    // frameblur.allocate(ofGetWidth(), ofGetHeight());

	// fingerMovie.load("movies/fingers.mov");
	fingerMovie.load("movies/gravity.mp4");
	// fingerMovie.load("movies/small.mp4");
	fingerMovie.setLoopState(OF_LOOP_NORMAL);
    fingerMovie.setSpeed(1.0);
	fingerMovie.play();
}

//--------------------------------------------------------------
void ofApp::update(){
    fingerMovie.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

    //BLUR HORIZONTAL
    // framebuffer.begin();
    //     // ofClear(0,0,0,0);
    //     blurH.begin();
    //         blurH.setUniform1f("blurAmnt", 100.0);
    //         fingerMovie.draw(0,0,1920,1080);
    //     blurH.end();
    // framebuffer.end();

    //KEYSTONE
    // framebuffer.begin();
    //     // ofClear(0,0,0,0);
    //     keystone.begin();
    //         // keystone.setUniform1f("blurAmnt", 100.0);
    //         fingerMovie.draw(0,0,1920,1080);
    //     keystone.end();
    // framebuffer.end();

    //DRAW TO SCREEN
	// framebuffer.draw(0, 0);

    // WARPER
    warper.begin();
    fingerMovie.draw(0, 0, ofGetWidth(), ofGetHeight());
    warper.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
    switch(key){
        case 'f':
            frameByframe=!frameByframe;
            fingerMovie.setPaused(frameByframe);
        break;
        case OF_KEY_LEFT:
            fingerMovie.previousFrame();
        break;
        case OF_KEY_RIGHT:
            fingerMovie.nextFrame();
        break;
        case '0':
            fingerMovie.firstFrame();
        break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	// if(!frameByframe){
    //     int width = ofGetWidth();
    //     float pct = (float)x / (float)width;
    //     float speed = (2 * pct - 1) * 5.0f;
    //     fingerMovie.setSpeed(speed);
	// }
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	// if(!frameByframe){
    //     int width = ofGetWidth();
    //     float pct = (float)x / (float)width;
    //     fingerMovie.setPosition(pct);
	// }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	// if(!frameByframe){
    //     fingerMovie.setPaused(true);
	// }
}


//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	// if(!frameByframe){
    //     fingerMovie.setPaused(false);
	// }
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
