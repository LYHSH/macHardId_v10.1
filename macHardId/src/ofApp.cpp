#include "ofApp.h"
#include "ofxIdentificationMgr.h"
//--------------------------------------------------------------
void ofApp::setup(){
	channelNums = 0;
	gui.setup();

	ofSetFrameRate(60);
	ofSetWindowTitle("hui_Registered_V1.2");
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
	gui.begin();
	ImGui::Text("Project blend: nums of channel");
	if (ImGui::SliderInt("channelNums", &channelNums, 0, 30))
	{
		if (0 != channelNums)
		{
			string extraInfoStr = ofToString(channelNums);
			ofxIdentificationMgr::setExtraInfo(extraInfoStr);
		}
	}
	ImGui::NewLine();
	ImGui::Separator();
	if (ImGui::Button("load", ofVec2f(200, 100)))
	{
		
		ofFileDialogResult res = ofSystemLoadDialog();
		cout << res.getPath() << endl;

		ofFile file(res.getPath());
		if (file.getExtension() == "xml")
		{
			files.clear();
			files.push_back(file);
		}

	}
	ImGui::Separator();
	if (ImGui::Button("generate",ofVec2f(200,100)))
	{
		if (files.size())
		{
			for (int i = 0;i < files.size(); i++)
			{
				auto & file = files[i];
				string dir = file.getEnclosingDirectory();
				string filename = file.getFileName();
				ofxIdentificationMgr::generateCheckStr(filename,dir);
			}
		}
		else
		{
			ofxIdentificationMgr::generateCheckStr();
		}
		
	}
	ImGui::Separator();
	if (ImGui::Button("clear", ofVec2f(200, 100)))
	{
		files.clear();
	}
	gui.end();


	{
		stringstream sss;
		for (int i = 0; i < files.size(); i++)
		{
			auto & file = files[i];
			sss << file.getAbsolutePath() << endl;
		}
		ofPushMatrix();
		ofTranslate(512, 0);
		ofPushStyle();
		ofSetColor(0);
		ofDrawRectangle(0, 0, ofGetWidth()-512, ofGetHeight());

		ofSetColor(255);
		ofDrawBitmapString(sss.str(), 20, 20);
		ofPopStyle();
		ofPopMatrix();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
	
	auto & strs = dragInfo.files;
	for (int i = 0; i < strs.size(); i++)
	{
		cout << strs[i] << endl;
		ofFile file(strs[i]);
		if (file.getExtension() == "xml")
		{
			files.clear();
			files.push_back(file);
		}
	}

// 	if (files.size())
// 	{
// 		ofFile file(files[0]);
// 		cout << file.getExtension() << endl;
// 		cout << file.getAbsolutePath() << endl;
// 		cout << file.getBaseName() << endl;
// 		cout << file.getEnclosingDirectory() << endl;
// 		cout << ofToDataPath(file.getEnclosingDirectory()) << endl;
// 		cout << file.getFileName() << endl;
// 		if (file.getExtension() == "xml")
// 		{
// 			filename = file.getAbsolutePath();
// 			cout << filename << endl;
// 		}
// 	}
}
