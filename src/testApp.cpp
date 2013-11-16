#include "testApp.h"

string convertInt(int number);

//    http://www.degraeve.com/color-palette/index.php?q=http://graphics8.nytimes.com/images/2013/06/28/arts/28ALTBUTTON_SPAN/28ALTBUTTON_SPAN-articleLarge.jpg,595878E9846D5089D2EAE5E4D9C5AB,4A4888FF5C2F0F80FFEDE3E1F1C794
//int colors[5] = {0x444488,0xff5533, 0x1188ff, 0xeedddd, 0xeecc99};

// http://www.cssdrive.com/imagepalette/index.php
int colors[50] = {0xe8eae7, 0xdce1dd, 0xf6ecf4, 0xfbf1f2, 0x041773, 0xfc4942, 0x8864aa, 0x070b64, 0x8f0799, 0xfbdc00, 0xf4a0ad, 0xf6a395, 0xf3b4c5, 0xeaece9, 0x008fe4, 0x51aff7, 0x4e6555, 0xbc6669, 0x673d17, 0xa10e1e, 0xee1b44, 0x016bc3, 0x020564, 0xf9de47, 0x21a900, 0x22ac23, 0x30b3eb, 0x83a6e0, 0xe0ecd6, 0xdde3d5, 0xede38e, 0x22b00e, 0x070534, 0x003a66, 0xcf0103, 0xe6e6e4, 0xf4c6d0, 0x996f01, 0x00043c, 0x7be25f, 0xe30a03, 0xf79cad, 0xe4e3e1, 0x0653c9, 0x0242ac, 0xeba00f, 0x000546, 0xf190a3, 0xeaeae8};

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
    
    // parse!
    for(int i=0; i<result.size(); i++)
	{
        // the id
		//std::string id_str = convertInt(result[i]["id"].asInt());
        
        // num faces
        int howManyFaces = result[i]["tags"]["faces"].size();
        
        float x,y;
        
        for(int j=0;j<howManyFaces;j++){
            //this face;
            x =result[i]["tags"]["faces"][j]["center_pos"]["value"][0].asFloat();
            y =result[i]["tags"]["faces"][j]["center_pos"]["value"][1].asFloat();
            float screenX = x*ofGetWidth();
            float screenY = y*ofGetHeight();
            //ofCircle(screenX,screenY, 5);
            Smile * aSmile = new Smile(screenX,screenY);
            aSmile->setWait(i);
            aSmile->setColor(colors[i%50]);
            smiles.push_back(aSmile);
            
        }
    }
    
}

//--------------------------------------------------------------
void testApp::update(){
    for(int i=0;i<smiles.size();i++){
        Smile * thisSmile = smiles.at(i);
        thisSmile->update();

    }
}

//--------------------------------------------------------------
void testApp::draw(){

    ofBackground(0);
    ofSetColor(255);
    
    for(int i=0;i<smiles.size();i++){
        Smile * thisSmile = smiles.at(i);

        thisSmile->draw();
    }
        // each face
        //std::string
        //std::string numFaces_string = convertInt(howManyFaces);
		//ofDrawBitmapString(numFaces_string, 20, i*24+40);

	
    
    
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

    reset();
    
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

void testApp::reset(){
    for(int i=0;i<smiles.size();i++){
        smiles.at(i)->setWait(i);
    }
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
