// main.cpp - Entry Point
#include "Engine.h"
#include <SFML/Graphics.hpp>
#include "Field.h"
#include "Id.h"
#include "Email.h"
#include "Name.h"
#include "Address.h"

int main() {



    Engine engine;  //  Create the Engine instance
    engine.run();   //  Start the loop inside Engine
    return 0;
}

