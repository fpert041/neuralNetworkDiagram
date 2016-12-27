//
//  Connection.cpp
//  networkDiagram
//
//  Created by Francesco Perticarari on 24/12/2016.
//
//

#include "Connection.hpp"

Connection::Connection() : NeuralTissue(0, 0){
    a=nullptr;
    b=nullptr;
    
    sending = false;
}

Connection::Connection(NeuralTissue& from, NeuralTissue& to, float w) : NeuralTissue(from, to, w){
    weight = w;
    
    a = (NeuralTissue*)&from;
    b = (NeuralTissue*)&to;
    sending = false;
}

Connection::~Connection(){
    //I don't want to delete the neurons these pointers point to (if the connections went out of scope)
    //because those neurons are independent of the connections and whilst connections may be deleted, Neurons may not and their memory addresses should not being freed when a connection is removed
    a=nullptr;
    b=nullptr;
}

void Connection::display() { //overwrite
    animating();
    
    ofSetColor(0);
    ofSetLineWidth(weight * 3 + 0.5);
    ofDrawLine(a->location.x, a->location.y, b->location.x, b->location.y);
    //cout << this->a->location.x << "/"<< this->a->location.y << " " << sending << endl;
    
    if(sending){
        ofSetColor(0);
        ofSetLineWidth(1);
        ofDrawEllipse(sender.x, sender.y, 6, 6);
    }
}

void Connection::feedForward(float input){
    this->sending = true;
    sender = a->location; //start animation from neuron a
    output = input*weight; //store output for the end of the animation
            //--this process would be irrelevant in a real decision taking NN, being replaced simply by:
            //  b->feedForward(output);
}

void Connection::animating(){
    if(sending){
        sender.x = ofLerp(sender.x, b->location.x, 0.1); // as long as we are "sending", do a linear interpolation a->b
        sender.y = ofLerp(sender.y, b->location.y, 0.1);
        
        float d = sender.distance(b->location);
        if(d<2){
            b->feedForward(output);
            sending = false;
        }
    }
}

