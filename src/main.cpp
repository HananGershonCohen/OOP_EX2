// main.cpp - Entry Point
#include "Engine.h"
#include <SFML/Graphics.hpp>

#include "Date.h"
int main() {

  /*  Date myDate;
    if (myDate.isValid())
    {
        std::cout << myDate.getValue() << "GOOD" ;
    }*/


    Engine engine;  //  Create the Engine instance
    engine.run();   //  Start the loop inside Engine
    return 0;
}

