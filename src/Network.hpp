//
//  Network.hpp
//  networkDiagram
//
//  Created by Francesco Perticarari on 24/12/2016.
//
//

#ifndef Network_hpp
#define Network_hpp

#include <stdio.h>
#include "Connection.hpp"
#include "Neuron.hpp"
#include "ofMain.h"

/**********************
 The Network class can then manage a C++ Vector of neurons, as well as have its own location (so that each neuron is drawn relative to the network’s center).
 This is particle systems 101. We have a single element (a neuron) and a network (a “system” of many neurons).
 **********************/

class Network {
    
public:
    std::vector<Neuron>neurons; //a list of neurons in the network
    std::vector<Connection>connections; //a list of connections in the network
    vector<int> layers; //a list of layers with their
    
    
    ofVec2f location;
    int layerPosStep;
    //int inputNeurons;
    
    Network(float x, float y);
    Network(float x, float y, int numLayers);
    Network(float x, float y, int minLayers, int maxLayers);
    Network(float x, float y, int minHidden, int maxHidden, int insOuts);
    Network(float x, float y, int minHidden, int maxHidden, int ins, int outs);
    
    void setup();
    void addLayer(int minNeurons, int maxNeurons);
    void addNeuron(Neuron& n);
    void connectAll();
    void connect(Neuron& from, Neuron& to);
    
    void display();
    void feedForward(vector<float> inputs);
    
    void defineLayer(int minNeurons, int maxNeurons, int layerPos);
    
};


#endif /* Network_hpp */
