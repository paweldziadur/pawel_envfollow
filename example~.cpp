#include "example~.hpp"

	// methods:
void MyPawel::bang(long inlet) {
    
		post("[pawel_envfollow~ here] bang in inlet %i! samplerate=%f", inlet, sys_getsr());
    
        // bang out 1nd non signal
        outlet_anything(m_outlets[0], gensym("[pawel_envfollow~ here]"), 0, NULL);
	}

void MyPawel::threshold(long inlet, double v) {
    _threshold = v;
    
   // post("inlet %ld threshold %f", inlet, v);
}

void MyPawel::attack(long inlet, double v) {
    _attack = v;
    attack_coef = exp(log(0.01)/( _attack * sys_getsr() * 0.001));
    
   //  post("inlet %ld attack %f", inlet, v);
    
}

void MyPawel::release(long inlet, double v) {
    _release = v;
    release_coef = exp(log(0.01)/( _release * sys_getsr() * 0.001));
    
    // post("inlet %ld release %f", inlet, v);
}

	// default signal processing method is called 'perform'
void MyPawel::perform(double **ins, long numins, double **outs, long numouts, long sampleframes) {
    
    double tmp;
    
    for (long channel = 0; channel < numouts; channel++) {
        double * in = ins[channel];
        double * out = outs[channel];
        for (long i=0; i < sampleframes; i++) {
            
            tmp = in[i];
            if(tmp < 0)
                tmp = -tmp;
            if(tmp >= _threshold)
            {
                if(tmp > envelope)
                    envelope = attack_coef * (envelope - tmp) + tmp;
                else
                    envelope = release_coef * (envelope - tmp) + tmp;
                out[i] = envelope;
            }
            else
            {
                out[i] = 0;
            }
        }
    }
	}
	
