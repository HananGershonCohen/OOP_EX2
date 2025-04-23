#include "BookingForm.h"
#include "DialogueManager.h"
#include <iostream>
#include <ctime>  // For getting current date
#include "Butten.h"

BookingForm::BookingForm(sf::RenderWindow& win, DialogueManager* manager) :window(win), formManager(manager) 
{
    fieldLabels = { "Name:", "ID:", "Address:", "Email:" };  // ✅ Add common fields
    userInput.resize(fieldLabels.size(), "");  // Initialize input fields
}

void BookingForm::openConfirmationWindow() {
    const std::string& formTitle = getFormType();
    sf::RenderWindow confirmWindow(sf::VideoMode(500, 600), "Confirm " + formTitle);

    sf::Font font;
    font.loadFromFile("C:/Windows/Fonts/arialbd.ttf");

    sf::Text title("Confirm " + formTitle, font, 22);
    title.setFillColor(sf::Color::Black);
    title.setStyle(sf::Text::Bold);
    title.setPosition(130, 20);

    std::string bookingInfo;
    for (size_t i = 0; i < fieldLabels.size(); ++i) {
        bookingInfo += fieldLabels[i] + " " + userInput[i] + "\n";
    }

    sf::Text details(bookingInfo, font, 18);
    details.setFillColor(sf::Color::Black);
    details.setPosition(50, 80); 

    Butten ApproveButton ("APPROVE", sf::Vector2f(120, 40), sf::Vector2f(100, 300), sf::Color(50, 150, 50), sf::Color::White);
    Butten CancelButton("CANCEL", sf::Vector2f(120, 40), sf::Vector2f(280, 300), sf::Color(180, 0, 0), sf::Color::White);


    bool approved = false;

    while (confirmWindow.isOpen()) {
        sf::Event event;
        while (confirmWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                confirmWindow.close();

            sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);

            if (event.type == sf::Event::MouseButtonPressed) 
            {
                sf::Vector2f mousePos = confirmWindow.mapPixelToCoords(sf::Mouse::getPosition(confirmWindow));

                if (CancelButton.isClicked(mousePos)) // press "CANCEL" 
                {
                    confirmWindow.close();
                }

                if (ApproveButton.isClicked(mousePos)) // press "APPROVE" 
                {
                    std::cout << formTitle << " Confirmed! Returning to main menu." << std::endl;
                    approved = true;
                    confirmWindow.close();
                }
            }
        }

        // If  do not click the APPROVE or CANCEL button
        confirmWindow.clear(sf::Color(240, 240, 240));

        confirmWindow.draw(title);
        confirmWindow.draw(details);    

        ApproveButton.draw(confirmWindow);
        CancelButton.draw(confirmWindow);

        confirmWindow.display();
    }

    if (approved) {
        formManager->closeForm();
    }
}
