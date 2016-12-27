//
//  Neuron.cpp
//  networkDiagram
//
//  Created by Francesco Perticarari on 24/12/2016.
//
//

#include "Neuron.hpp"

Neuron::Neuron() : NeuralTissue(0, 0) { //default constructor // : Parent(--pass veriables up une level--)
    r=16;
    location = ofVec2f(0, 0);
    sum = 0;
    y_max = 1.3;
}

Neuron::Neuron(float x, float y) : NeuralTissue(x, y) { //pass veriables up une level
    r=16;
    location = ofVec2f(x, y);
    sum = 0;
    y_max = 1.3;
}

void Neuron::addForwardConnection(Connection& c){
    Connection & conn  = c;
    fwdConnections.push_back(conn);
}

void Neuron::addBackwardConnection(Connection& c){
    Connection & conn  = c;
    bwdConnections.push_back(conn);
}

void Neuron::display() {
    if(r>16) r-=1; //enable animation when firing
    
    ofSetLineWidth(3); //draw neuron
    ofSetColor(0+(sum*200));
    ofFill();
    ofDrawEllipse(location.x, location.y, r, r);
    ofNoFill();
    ofSetColor(0);
    ofDrawEllipse(location.x, location.y, r-1, r-1);
    ofFill();
    
    //draw connections of going out from this neurons
    for(Connection &c : fwdConnections){
        c.display();
    }
    
    sum*=0.999; //slightly discharge over time
}

void Neuron::feedForward(float input){
    //sum = 0; //----------
    
    sum += input; //accumulate the sum;
    activate(sum);
}

void Neuron::activate(float& sum){ //activation function based on running sum of input
    sum = y_max / (1+exp(-1*(sum-0))); // f(x) = y-Max / (1+exp(-steepness*(x - x_0))) // logistic function
    //cout << sum << endl; //debug
    
    if(sum>1){
        //cout << this->location.x << "/"<< this->location.y << " " << sum << endl;
        fire();
        sum=0; //if we fired, we reset
    }
}

void Neuron::fire(){
    r = 30;
    
    for(Connection& c : fwdConnections){
        c.feedForward(sum); //the neuron sends sum through all of its connection
    }
}
