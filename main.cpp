//
//  main.cpp
//  pawel_envfollow~
//
//  Created by Pawel Dziadur on 03/04/2017.
//
//

#include "main.hpp"

C74_EXPORT int main(void) {
    // create a class with the given name:
    MyPawel::makeMaxClass("pawel_envfollow~");
    REGISTER_METHOD(MyPawel, bang);
    REGISTER_METHOD_FLOAT(MyPawel, threshold);
    REGISTER_METHOD_FLOAT(MyPawel, attack);
    REGISTER_METHOD_FLOAT(MyPawel, release);
}
