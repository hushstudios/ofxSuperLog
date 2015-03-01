/**     ___           ___           ___                         ___           ___     
 *     /__/\         /  /\         /  /\         _____         /  /\         /__/|    
 *    |  |::\       /  /::\       /  /::|       /  /::\       /  /::\       |  |:|    
 *    |  |:|:\     /  /:/\:\     /  /:/:|      /  /:/\:\     /  /:/\:\      |  |:|    
 *  __|__|:|\:\   /  /:/~/::\   /  /:/|:|__   /  /:/~/::\   /  /:/  \:\   __|__|:|    
 * /__/::::| \:\ /__/:/ /:/\:\ /__/:/ |:| /\ /__/:/ /:/\:| /__/:/ \__\:\ /__/::::\____
 * \  \:\~~\__\/ \  \:\/:/__\/ \__\/  |:|/:/ \  \:\/:/~/:/ \  \:\ /  /:/    ~\~~\::::/
 *  \  \:\        \  \::/          |  |:/:/   \  \::/ /:/   \  \:\  /:/      |~~|:|~~ 
 *   \  \:\        \  \:\          |  |::/     \  \:\/:/     \  \:\/:/       |  |:|   
 *    \  \:\        \  \:\         |  |:/       \  \::/       \  \::/        |  |:|   
 *     \__\/         \__\/         |__|/         \__\/         \__\/         |__|/   
 *
 *  Description: 
 *				 
 *  ofxSuperLogDisplay.h, created by Marek Bereza on 02/09/2013.
 */

#pragma once
#include "ofMain.h"
#define DEFAULT_NUM_LOG_LINES 50

#ifdef USE_OFX_FONTSTASH
#include "ofxFontStash.h"
#endif

class ofxSuperLogDisplay: public ofBaseLoggerChannel {
public:
	
	ofxSuperLogDisplay();
	virtual ~ofxSuperLogDisplay();
	
	void setMaxNumLogLines(int maxNumLogLines);
	void setEnabled(bool enabled);
	bool isEnabled();
	
	void setMinimized(bool minimized);
	bool isMinimized();

	void setUseColors(bool useC){useColors = useC;};
	void setColorForLogLevel(ofLogLevel l, const ofColor &c){ logColors[l] = c;}
	
	#ifdef USE_OFX_FONTSTASH
	void setFont(ofxFontStash* f, float fontSize_ = 16.0f){font = f; fontSize = fontSize_;}
	#endif

	void draw(ofEventArgs &e);
	
	void mousePressed(ofMouseEventArgs &e);
	void mouseMoved(ofMouseEventArgs &e);
	void mouseDragged(ofMouseEventArgs &e);
	void mouseReleased(ofMouseEventArgs &e);
	

	void log(ofLogLevel level, const string & module, const string & message);
	void log(ofLogLevel logLevel, const string & module, const char* format, ...);
	void log(ofLogLevel logLevel, const string & module, const char* format, va_list args);

	
protected:

	struct LogLine{
		string line;
		ofLogLevel level;
		LogLine(string lin, ofLogLevel lev){ line = lin; level = lev; }
	};

	bool enabled;
	deque<LogLine> logLines;

	int MAX_NUM_LOG_LINES;
	bool minimized;
	
	float width;
	ofRectangle minimizedRect;
	bool draggingWidth;

	ofMutex mutex;

	bool useColors;
	ofColor logColors[6]; //6 being the # of ofLogLevels. This is not very future proof - TODO!

	#ifdef USE_OFX_FONTSTASH
	ofxFontStash * font;
	float fontSize;
	#endif
};
