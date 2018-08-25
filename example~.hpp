//
//  example.hpp
//  pawel_envfollow~
//
//  Created by Pawel Dziadur on 01/10/2017.
//
//

#ifndef example_h
#define example_h

#include "maxcpp6.h"

class MyPawel : public MspCpp6<MyPawel> {
    
    double _threshold;
    double _attack;
    double _release;
    double attack_coef;
    double release_coef;
    double envelope;
    
public:

    void ** m_outlets = NULL;
    int nonAudioOutletNum = 1;
    
  MyPawel(t_symbol * sym, long ac, t_atom * av) {
        
        post("pawel_envfollow~ v1.0.0 created on 1/10/2017 by Pawel Dziadur");
        
        // create non-audio outlets (outkets are buffer-pointers by the way!)   // <<<< this is to add non audio outlets
        m_outlets = (void**)sysmem_newptr(sizeof(void*) * nonAudioOutletNum);
        for(unsigned int i=0; i<nonAudioOutletNum; ++i){
            m_outlets[nonAudioOutletNum - 1 - i] = outlet_new(this, NULL); //add them to this object
        }
        
        // setup adudio ins/outs
        setupIO(1, 1);
      
        // default values 
        _threshold = 0.0;
        _attack = 150.0;
        _release = 500.0;
    }
    
   ~MyPawel() {
        post("pawel_envfollow~ object freed");
    }
    // methods:
    void bang(long inlet);
    void threshold(long inlet, double v); // Max float method (but of course in reality Max called float is double
    void attack(long inlet, double v); // Max float method (but of course in reality Max called float is double
    void release(long inlet, double v); // Max float method (but of course in reality Max called float is double
    
    // default signal processing method is called 'perform'
    void perform(double **ins, long numins, double **outs, long numouts, long sampleframes);
    
};


#endif /* example_h */



    
