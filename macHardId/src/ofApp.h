#pragma once
/************************************************************************/
/* 校验码生成软件
/* author:hui
/* version1.0
/* version2.0:针对主板和CPU信息获取失败的BUG发布2.0补丁版本    同时增加文件拖拽功能
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
