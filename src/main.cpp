#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){

	// ofSoundStream soundStream;
	// auto devices = soundStream.getDeviceList();
	// ofSoundStreamSettings soundSettings;
    // soundSettings.setOutDevice(devices[0]);
	// ofSoundStreamSetup(soundSettings);
	
	// nice aplay -c 2 -t raw -r 44 < /dev/zero

	ofGLFWWindowSettings settings;
    settings.setGLVersion(3,1); //we define the OpenGL version we want to use
    settings.setSize(1920,1080);
    ofCreateWindow(settings);

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp( new ofApp());

}
