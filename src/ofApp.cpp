#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    defineLayer(-200, 4, network); //define input layer
//    defineLayer(0, 8, network); //define hidden layer
//    defineLayer(+200, 2, network); //define output layer
    
//    network.addLayer(1, 1); define layers
//    network.addLayer(2, 2);
    
    //redefine network so that its hidden layers are between 1 and 4
    //network = Network(ofGetWidth()/2, ofGetHeight()/2, 1, 4);
    
    ofSetCircleResolution(100); //set openGL ellipse resolution (drawing points)
    
    int dataDimensions = floor(ofRandom(1, 4)); //define input neurons number
    int answerDimensions = dataDimensions - floor(ofRandom(dataDimensions)); // " output neurons
    
    network = Network(ofGetWidth()/2, ofGetHeight()/2, 1, 4, dataDimensions, answerDimensions); //define netwrok so that its hidden layers are between 1 and 4, whilst its input and output neurons can vary between 1 and 3
    
    for(int i = 0; i<dataDimensions; i++){ //setup and fill in a vector equal to the number of inputs (dimensions considered in solving the problem)
        inputs.push_back(ofRandom(1));
    }
    
    network.feedForward(inputs); //initial feedforward function for the network
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    network.display();
    
    
    for(int i=0; i<inputs.size(); ++i){ //new set of inputs
        inputs[i] = ofRandom(1);
    }
    if (ofGetFrameNum() % 60 == 0) {
        network.feedForward(inputs); //feedforward
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

}

//--------------------------------------------------------------
//--------------------------------------------------------------
//HELPER FUNCTIONS:


void ofApp::defineLayer(int layerPos, int maxNeurons, Network& network){
    //generate input layer of neurons
    int inNumber = floor(ofRandom(1, maxNeurons));
    vector<Neuron> inputNeurons = vector<Neuron>(inNumber);
    int separation = 50;
    
    for(int i = 0; i<inNumber; ++i){ //define neurons & add them to the network
        int adjust = 0;
        if(inNumber%2==0) adjust += floor(separation / 2); //centre layer vertically
        inputNeurons[i] = Neuron(layerPos, pow(-1, i) * floor((i+1)/2) * separation + adjust); //reset neurons in vector with right coordinates
        network.addNeuron(inputNeurons[i]); //add neurons to the network we are referring to
    }
}

//--------------------------------------------------------------
std::vector<std::string> ofApp::callNeurons(string ID, int number){ //take in a string to identify the tipe of neuron
    //take in also the number of neurons to generate
    
    //C-style array filled with string elements (pointer to a chunk of memory!)
    string myLetters[] = {ID+"A", ID+"B", ID+"C", ID+"D", ID+"E", ID+"F", ID+"G", ID+"H", ID+"I"};
    
    //saftety check based on array length
    if(number > (sizeof(myLetters) / sizeof(*myLetters)))
        throw std::invalid_argument( "received too big of a number!" );
    
    //use the iterator constructor of a vector to construct from a C-style array
    //std::vector<std::string> lettersSet( myLetters, myLetters + sizeof(myLetters) / sizeof(string)); //take in all the elements in myLetters[]
    std::vector<std::string> lettersSet( myLetters, myLetters + number); //take in "number" elements of myLetters[]
    
    
    //    //debug to test if the vector was initialised correctly
    //    std::cout << number << " : " ;
    //    for (std::vector<string>::iterator it = lettersSet.begin(); it != lettersSet.end(); ++it)
    //        std::cout << ' ' << *it;
    //    std::cout << '\n';
    
    return lettersSet;
}
