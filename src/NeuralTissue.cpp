//
//  NeuralTissue.cpp
//  networkDiagram
//
//  Created by Francesco Perticarari on 26/12/2016.
//
//

#include "NeuralTissue.hpp"

// A basic template for neural units (polymorph from this)


NeuralTissue::NeuralTissue(float x, float y){
    location = ofVec2f(x,y);
}

NeuralTissue::NeuralTissue(NeuralTissue& x, NeuralTissue& y, float w){
    a=&x;
    b=&y;
    weight = w;
}

void NeuralTissue::feedForward(){
    
}

void NeuralTissue::feedForward(NeuralTissue&){
    
}

void NeuralTissue::feedForward(float input){
    
}

void NeuralTissue::display(){
    
}
