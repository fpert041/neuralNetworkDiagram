//
//  Neuron.hpp
//  networkDiagram
//
//  Created by Francesco Perticarari on 24/12/2016.
//
//

#ifndef Neuron_hpp
#define Neuron_hpp

#include <stdio.h>
#include "ofMain.h"
#include "NeuralTissue.hpp"
#include "Connection.hpp"

//** An incredibly simple Neuron class stores and displays the location of a single neuron. **//

class Neuron : public NeuralTissue {
public:
    
    ofVec2f location; //location relative to network display
    vector<Connection> fwdConnections; //list of forward connections (this->other)
    vector<Connection> bwdConnections; //list of backward connections (other -> this)
    
    Neuron(); //default constructor
    Neuron(float x, float y);
    void display();
    void addForwardConnection(Connection& c);
    void addBackwardConnection(Connection& c);
    
    float sum;
    float y_max;
    float r;
    
    void feedForward(float input);
    void activate(float& sum);
    void fire();
};


#endif /* Neuron_hpp */
