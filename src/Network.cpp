//
//  Network.cpp
//  networkDiagram
//
//  Created by Francesco Perticarari on 24/12/2016.
//
//

#include "Network.hpp"

Network::Network(float x, float y, int minHidden, int maxHidden, int ins, int outs){ //setup netwrok of neurons by choosing its centre
    location = ofVec2f(x, y);
    layerPosStep = 150 ;
    
    int lNum = floor(ofRandom(minHidden, maxHidden + 1)); //number of hidden layers
    
    this->addLayer(ins, ins); //add input layer
    for(int i=0; i<(lNum); i++){ //add hidden layers
        this->addLayer(ins, ins+3);
    }
    this->addLayer(outs, outs); //add output layer
    
    connectAll();
}

Network::Network(float x, float y, int minHidden, int maxHidden, int insOuts){ //setup netwrok of neurons by choosing its centre
    location = ofVec2f(x, y);
    layerPosStep = 150 ;
    
    int lNum = floor(ofRandom(minHidden, maxHidden + 1)); //number of hidden layers
    
    this->addLayer(insOuts, insOuts); //add input layer
    for(int i=0; i<(lNum); i++){ //add hidden layers
        this->addLayer(insOuts, insOuts+3);
    }
    this->addLayer(insOuts, insOuts); //add output layer
    
    connectAll();
}

Network::Network(float x, float y, int minHidden, int maxHidden){ //setup netwrok of neurons by choosing its centre
    location = ofVec2f(x, y);
    layerPosStep = 150 ;
    
    int lNum = floor(ofRandom(minHidden, maxHidden + 1)); //number of hidden layers
    
    this->addLayer(1, 3); //add input layer
    for(int i=0; i<(lNum); i++){ //add hidden layers
        this->addLayer(2, 5);
    }
    this->addLayer(1, 3); //add output layer
    
    connectAll();
}

Network::Network(float x, float y, int numLayers){ //setup netwrok of neurons by choosing its centre
    location = ofVec2f(x, y);
    layerPosStep = 150 ;
    
    for(int i=0; i<numLayers; i++){
        addLayer(2, 5);
    }
    connectAll();
}

Network::Network(float x, float y){ //setup empty netwrok of neurons by choosing its centre
    location = ofVec2f(x, y);
    int numLayers = ofRandom(2, 5);
    layerPosStep = 150;
}



//----------------------------------------------------

void Network::feedForward(vector<float> inputs){
    for(int i=0; i<inputs.size(); ++i){
        neurons[i].feedForward(inputs[i]);
    }
}

//----------------------------------------------------

void Network::display(){ //draw the network
    ofPushMatrix();
    
    ofTranslate(location.x, location.y);
    for(Neuron& n : neurons){
        n.display();
    }
    
    ofPopMatrix();
}

//----------------------------------------------------

void Network::addLayer(int minNeurons, int maxNeurons){ //create layer of neurons
    
    int adjust = floor(layerPosStep / 2);
    if(layers.size()%2 !=0 && layers.size()>1){ //centre layers horizontally (part 1)
        location.x -= adjust;
    }
    location.x += layers.size() * layerPosStep/2;
    
    
    //DEFINE LAYER:
    defineLayer(minNeurons, maxNeurons, layers.size() * layerPosStep);
    
    
    location.x -= layers.size() * layerPosStep/2; //centre layers horizontally (part 2)
    if(layers.size()%2==0){
        location.x += adjust;
    }
    
    //cout<< layerPosition << " " << layerPosStep << " " << adjust <<endl; //debug
}

//----------------------------------------------------

void Network::defineLayer(int minNeurons, int maxNeurons, int layerPos){
    //generate input layer of neurons
    int inNumber = floor(ofRandom(minNeurons, maxNeurons + 1));
    layers.push_back(inNumber); //record layer and its number of neurons
    int separation = 100; //y-axis separation between layers
    
    for(int i = 0; i<inNumber; ++i){ //define neurons & add them to the network
        int adjust = 0;
        if(inNumber%2==0) adjust += floor(separation / 2); //centre layer vertically
        Neuron inputNeuron = Neuron(layerPos, pow(-1, i) * floor((i+1)/2) * separation + adjust); //create neurons
        
        this->addNeuron(inputNeuron); //add neurons to the network
    }
}

void Network::addNeuron(Neuron& n){ //add neuron to the network
    neurons.push_back(n);
}

//----------------------------------------------------

void Network::connectAll(){
    int index1 = 0; //index of the first neuron in the first layer
    int index2 = index1 + layers[0];//index of the first neuron in the second layer
    
    for(int i = 0; i<layers.size()-1; ++i){ //loop from layer indexed 0 to layer indexed "size()-2"
        for(int j =0; j<layers[i]; ++j){     //at each step loop "j" times with j = number of neurons in that layer
            for(int k=0; k<layers[i+1]; ++k){ //at each step loop "k" times with  k = number of neurons in the layer after
                connect(neurons[index1+j], neurons[index2+k]);
                //cout << "neurons[" << index1+j << "] to " << "neurons[" << index2+k << "] " << endl; //debug
            }
        }
    index1+=layers[i];
    index2+=layers[i+1];
    }
}

void Network::connect(Neuron& from, Neuron& to){ //mark neurons so that they know which other n they are connected to
    
    Connection c(from, to, ofRandom(1));
    connections.push_back(c);
    
    from.addForwardConnection(connections[connections.size()-1]);
    to.addBackwardConnection(connections[connections.size()-1]);
}



