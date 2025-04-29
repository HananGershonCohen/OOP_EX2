// main.cpp - Entry Point
#include "Engine.h"
#include <SFML/Graphics.hpp>
#include "Field.h"
#include "Id.h"
#include "Email.h"
#include "Name.h"
#include "Date.h"
#include "Address.h"

int main() 
{
    //int num = 213669229;
    //Id id(num);
    //Field<Id> Fid(id);

    //if (Fid.isValid())
    //{
    //    std::cout << "ID is valid!" << std::endl;
    //}
    //else
    //{
    //    std::cout << "ID is invalid!" << std::endl;
    //}

    
    Date date;


    Engine engine;  //  Create the Engine instance
    engine.run();   //  Start the loop inside Engine
    return 0;
}

