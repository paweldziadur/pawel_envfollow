# pawel_envfollow

Pawel Dziadur, pawel_envfollow~ Max/MSP object, the source code of C++ build

Pawel Dziadur, pawel_envfollow~ Max/MSP object, the source code of C++ build

The Max/MSP object presented here is a basic but effective envelope follower ported by myself to C++ from a Java example.

I used to like the qualities of the discussed Java envelope follower and decided to create a more efficient C++ incarnation of the utilised DSP.

This project is a part of research on building Max/MSP external objects in C++ (with a minimum headache).

Short intro to the research area:

As we know we can build Max externals in C, but why do this if C++ is better, and we can make use of our beloved resources:

the vast array of available C++ libraries!

I want to thank  Francesco Perticarari, a London-based artist, programmer and entrepreneur: http://francescoperticarari.com/

for introducing me to his version of the maxcpp toolkit - which he improved 
over the initial version available at https://github.com/grrrwaaa/maxcpp

by making it more compatible and making beautiful use of the Max 6 or 7 API.

To build my envelope follower you need to download Max SDK:

https://github.com/Cycling74/max-sdk

and maxcpp toolkit from Francesco's git below:

https://github.com/fpert041/maxcpp

To simplify the process of the set up I have included a PDF tutorial with pictures on how to create the build environment on your Mac (since our dependency - maxcpp is tested on Mac only).

