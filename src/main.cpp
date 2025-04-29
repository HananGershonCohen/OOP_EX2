// main.cpp - Entry Point
#include "Engine.h"
#include <SFML/Graphics.hpp>
#include "Field.h"
#include "Date.h"
int main() {

  /*  Date myDate;
    if (myDate.isValid())
    {
        std::cout << myDate.getValue() << "GOOD" ;
    }*/
    Date myDate;
    Field<Date> myFDate(myDate);
    if (myFDate.isValid())
    {
        std::cout << "is Valid" << myDate.getValue();


    }

    Engine engine;  //  Create the Engine instance
    engine.run();   //  Start the loop inside Engine
    return 0;
}

