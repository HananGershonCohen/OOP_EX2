#include "HotelBookingForm.h"
#include "DialogueManager.h"
#include <iostream>
#include <ctime>  // For getting current date

HotelBookingForm::HotelBookingForm(sf::RenderWindow& win, DialogueManager* manager)
    : BookingForm(win, manager) {  // ✅ Calls base constructor
    fieldLabels.insert(fieldLabels.end(), {
        "Hotel Name:", "Check-in Date:", "Check-out Date:",
        "Number of Guests:", "Room Type:"
        });

    userInput.resize(fieldLabels.size(), "");  // ✅ Resize input fields
    setDefaultValues();
}

void HotelBookingForm::setDefaultValues() {
    time_t now = time(0);
    tm ltm;
    localtime_s(&ltm, &now);  // ✅ Safe alternative to localtime()

    userInput[5] = userInput[6] = std::to_string(1900 + ltm.tm_year) + "-" +
        std::to_string(1 + ltm.tm_mon) + "-" +
        std::to_string(ltm.tm_mday);
    userInput[8]="Single Room";
}

void HotelBookingForm::initFieldVec()
{
    m_fieldVec.resize(9);
    m_fieldVec[0] = std::make_unique<Field<Name>>(Name(userInput[0]));
    int num = 0;
    if (!userInput[1].empty()) num = std::stoi(userInput[1]); else num = -1; 
    m_fieldVec[1] = std::make_unique<Field<Id>>(Id(num));
    m_fieldVec[2] = std::make_unique<Field<Name>>(Name(userInput[2]));
    m_fieldVec[3] = std::make_unique<Field<Name>>(Name(userInput[3]));
    m_fieldVec[4] = std::make_unique<Field<Name>>(Name(userInput[4]));
    m_fieldVec[5] = std::make_unique<Field<Date>>(Date(userInput[5]));
    m_fieldVec[6] = std::make_unique<Field<Date>>(Date(userInput[6]));
  
    if (!userInput[7].empty()) num = std::stoi(userInput[7]); else num = -1;
     m_fieldVec[7] = std::make_unique<Field<NumGuests>>(NumGuests(num));
     
     std::vector<std::string >Vecstr = getArrayChoice();
     std::pair<std::string, std::vector<std::string>> pair(userInput[8], Vecstr);
     m_fieldVec[8] = std::make_unique<Field<ChoiceHotel>>(ChoiceHotel(pair));
}


std::string HotelBookingForm::getFormType() const {
    return "Hotel Booking";
}

void HotelBookingForm::render(sf::RenderWindow& window) {
    sf::Font font;
    font.loadFromFile("C:/Windows/Fonts/arialbd.ttf");

    window.clear(sf::Color(235, 235, 235));

    // ✅ Title
    sf::Text title("Hotel Booking Form", font, 26);
    title.setFillColor(sf::Color(20, 20, 20));
    title.setStyle(sf::Text::Bold);
    title.setPosition(20, 10);
    window.draw(title);

    bool cursorVisible = (cursorTimer.getElapsedTime().asMilliseconds() % 1000 < 500);

    // ✅ Render input fields dynamically
    int yOffset = 60;
    for (std::size_t i = 0; i < fieldLabels.size(); ++i) {
        sf::Text label(fieldLabels[i], font, 18);
        label.setFillColor(sf::Color(60, 60, 60));
        label.setPosition(20, yOffset);
        window.draw(label);

        sf::RectangleShape inputBox(sf::Vector2f(250, 35));
        inputBox.setPosition(240, yOffset - 5);
        inputBox.setFillColor(sf::Color::White);
        inputBox.setOutlineThickness(2);
        inputBox.setOutlineColor(i == activeField ? sf::Color(0, 120, 255) : sf::Color(160, 160, 160));
        window.draw(inputBox);

        std::string displayText = userInput[i];
        if (i == activeField && cursorVisible) {
            displayText += "|";
        }

        sf::Text inputText(displayText, font, 16);
        inputText.setFillColor(sf::Color::Black);
        inputText.setPosition(245, yOffset);
        window.draw(inputText);

        yOffset += 50;
    }
    float roomTypeButtonX = 10;
    for (int i = 0; i < roomTypeSelection.size(); ++i) {
        sf::RectangleShape roomButton(sf::Vector2f(150, 30));
        roomButton.setPosition(roomTypeButtonX, yOffset);
        roomButton.setFillColor(selectedRoomType==i ? sf::Color(0, 120, 255) : sf::Color::White);  // ✅ Highlight selected
        roomButton.setOutlineThickness(2);
        roomButton.setOutlineColor(sf::Color(160, 160, 160));
        window.draw(roomButton);

        sf::Text roomText(roomTypeSelection[i], font, 16);
        roomText.setFillColor(selectedRoomType == i ? sf::Color::White : sf::Color::Black);
        roomText.setPosition(roomTypeButtonX + 10, yOffset + 5);
        window.draw(roomText);

        roomTypeButtonX += 160;  // ✅ Increased spacing
    }
    // ✅ "Done" Button
    sf::RectangleShape submitButton(sf::Vector2f(140, 40));
    submitButton.setPosition(20, 570);
    submitButton.setFillColor(sf::Color(50, 150, 50));  // ✅ Green color
    window.draw(submitButton);

    sf::Text submitText("DONE", font, 20);
    submitText.setFillColor(sf::Color::White);
    submitText.setPosition(50, 580);
    window.draw(submitText);

    // ✅ "Cancel" Button
    sf::RectangleShape cancelButton(sf::Vector2f(140, 40));
    cancelButton.setPosition(200, 570);
    cancelButton.setFillColor(sf::Color(180, 0, 0));  // ✅ Red color
    window.draw(cancelButton);

    sf::Text cancelText("CANCEL", font, 20);
    cancelText.setFillColor(sf::Color::White);
    cancelText.setPosition(230, 580);
    window.draw(cancelText);

}

void HotelBookingForm::handleInput(sf::Event event) {
    if (event.type == sf::Event::TextEntered) {
        if (event.text.unicode == '\b' && !userInput[activeField].empty()) {
            userInput[activeField].pop_back();
        }
        else if (event.text.unicode >= 32 && event.text.unicode < 128) {
            userInput[activeField] += static_cast<char>(event.text.unicode);
        }
    }
    else if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Tab) {
            activeField = (activeField + 1) % userInput.size();
        }
        if (event.key.code == sf::Keyboard::Return) {
            std::cout << "Entered Data: ";
            for (const auto& field : userInput) std::cout << field << " ";
            std::cout << std::endl;
        }
    }
    else if (event.type == sf::Event::MouseButtonPressed) {
        sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);

        int yOffset = 60;  // ✅ Start from the top

        for (std::size_t i = 0; i < fieldLabels.size(); ++i) {
            sf::FloatRect inputBoxBounds(260, yOffset - 5, 250, 35);  // ✅ Uses dynamic positioning
            if (inputBoxBounds.contains(mousePos)) {
                activeField = i;
                return;
            }
            yOffset += 50;  // ✅ Move down dynamically (same logic as `render()`)
        }


        // ✅ Handle Room Type Button Click          
        float roomButtonX = 10;
        for (int i = 0; i < roomTypeSelection.size(); ++i)
        {
            std::cout << __LINE__ << std::endl;
            sf::FloatRect timeButtonBounds(roomButtonX, yOffset, 150, 30);
            if (timeButtonBounds.contains(mousePos))
            {
                selectedRoomType = i;
                //Update the "Room Type" input box
                userInput[8] = roomTypeSelection[i];

                return;
            }
            roomButtonX += 160;  // Move to next button
        }


        // ✅ Handle "Done" Button Click
        if (mousePos.x >= 20 && mousePos.x <= 160 && mousePos.y >= 570 && mousePos.y <= 610) {
            std::cout << "Flight Booking Confirmed!\n";
            initFieldVec();
            openConfirmationWindow();  // ✅ Open confirmation
            return;
        }

        // ✅ Handle "Cancel" Button Click
        if (mousePos.x >= 200 && mousePos.x <= 340 && mousePos.y >= 570 && mousePos.y <= 610) {
            std::cout << "Cancelled Flight Booking\n";
            formManager->closeForm();
            return;
        }
    }
}

std::vector<std::string> HotelBookingForm::getArrayChoice()
{
    return roomTypeSelection;
}

