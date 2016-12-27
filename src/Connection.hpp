//
//  Connection.hpp
//  networkDiagram
//
//  Created by Francesco Perticarari on 24/12/2016.
//
//

#ifndef Connection_hpp
#define Connection_hpp

#include <stdio.h>
#include "ofMain.h"
#include "NeuralTissue.hpp"

class Neuron; //fwd declararion

class Connection : public NeuralTissue {
public:
    
    NeuralTissue* a = nullptr;
    NeuralTissue* b = nullptr;
    float weight;
    
    bool sending;
    ofVec2f sender;
    float output;
    
    Connection();
    Connection(NeuralTissue& from, NeuralTissue& to, float w);
    ~Connection();
    
    void display();
    void feedForward(float input);
    void animating();
};


#endif /* Connection_hpp */
