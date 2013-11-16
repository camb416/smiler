#include "testApp.h"

string convertInt(int number);

//--------------------------------------------------------------
void testApp::setup(){

    
    std::string file = "/Users/cam/Documents/Development/openFrameworks/objectcrowdsourcer/taggedMin.json";
	
	// Now parse the JSON
	bool parsingSuccessful = result.open(file);
	
    if (parsingSuccessful) {
		cout << result.getRawString() << endl;
        
        // now write pretty print
        if(!result.save("example_output_pretty.json",true)) {
            cout << "example_output_pretty.json written unsuccessfully." << endl;
        } else {
            cout << "example_output_pretty.json written successfully." << endl;
        }
        
        // now write without pretty print
        if(!result.save("example_output_fast.json",false)) {
            cout << "example_output_pretty.json written unsuccessfully." << endl;
        } else {
            cout << "example_output_pretty.json written successfully." << endl;
        }
		
	} else {
		cout  << "Failed to parse JSON" << endl;
	}
    
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

    for(int i=0; i<result.size(); i++)
	{
		std::string title  = convertInt(result[i]["id"].asInt());
		ofDrawBitmapString(title, 20, i*24+40);
	}
    
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}

// from http://www.cplusplus.com/forum/beginner/7777/
string convertInt(int number)
{
    if (number == 0)
        return "0";
    string temp="";
    string returnvalue="";
    while (number>0)
    {
        temp+=number%10+48;
        number/=10;
    }
    for (int i=0;i<temp.length();i++)
        returnvalue+=temp[temp.length()-i-1];
    return returnvalue;
}
