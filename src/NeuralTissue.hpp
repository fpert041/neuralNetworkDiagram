//
//  NeuralTissue.hpp
//  networkDiagram
//
//  Created by Francesco Perticarari on 26/12/2016.
//
//

#ifndef NeuralTissue_hpp
#define NeuralTissue_hpp

#include <stdio.h>
#include "ofMain.h"

class NeuralTissue {
    
public:
    ofVec2f location;
    NeuralTissue * a;
    NeuralTissue * b;
    float weight;
    
    //NeuralTissue();
    NeuralTissue(float x, float y);
    NeuralTissue(NeuralTissue& x, NeuralTissue& y, float w);
    virtual void feedForward();
    virtual void feedForward(NeuralTissue&);
    virtual void display();
    virtual void feedForward(float input);
};

#endif /* NeuralTissue_hpp */
