#pragma once
/************************************************************************/
/* У�����������
/* author:hui
/* version1.0
/* version2.0:��������CPU��Ϣ��ȡʧ�ܵ�BUG����2.0�����汾    ͬʱ�����ļ���ק����
/************************************************************************/
#include "ofMain.h"
#include "ofxImGui.h"

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

		ofxImGui::Gui gui;
		int channelNums;

		vector<ofFile> files;
};
