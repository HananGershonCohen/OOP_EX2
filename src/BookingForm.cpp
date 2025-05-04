#include "BookingForm.h"
#include "DialogueManager.h"
#include <iostream>
#include <ctime>  // For getting current date

BookingForm::BookingForm(sf::RenderWindow& win, DialogueManager* manager) :window(win), formManager(manager) 
{
    fieldLabels = { "Name:", "ID:", "Address:", "Email:" };  // ✅ Add common fields
    userInput.resize(fieldLabels.size(), "");  // Initialize input fields
}


void BookingForm::checkValidate()
{
    for (int i = 0; i < m_fieldVec.size(); i++)
    {
        if (!m_fieldVec[i]->isValid() && !m_fieldVec.empty())
        {
            std::cout << "the value m_fieldVec[" << i << "] is Not valid" << std::endl;
        }
    }
}

int BookingForm::stringToInt(const std::string& str)
{

    if (str.empty()) return 0;

    int result = 0;
    for (char c : str) {
        if (c < '0' || c > '9') return 0; // תו לא מספרי
        result = result * 10 + (c - '0');
    }

    return result;

}


void BookingForm::openConfirmationWindow()
{
    const std::string& formTitle = getFormType();
    sf::RenderWindow confirmWindow(sf::VideoMode(500, 600), "Confirm " + formTitle);

    sf::Font font;
    font.loadFromFile("C:/Windows/Fonts/arialbd.ttf");

    sf::Text title("Confirm " + formTitle, font, 22);
    title.setFillColor(sf::Color::Black);
    title.setStyle(sf::Text::Bold);
    title.setPosition(130, 20);

    std::vector<sf::Text> fieldTexts;
    float y = 80.0f;

    // הצגת כל השדות הרגילים
    for (size_t i = 0; i < fieldLabels.size(); ++i) {
        sf::Text fieldText(fieldLabels[i] + " " + userInput[i], font, 18);
        fieldText.setPosition(50, y);
        fieldText.setFillColor(sf::Color::Black);
        fieldTexts.push_back(fieldText);
        y += 25;

        // הודעת שגיאה אם לא תקין
        if (m_fieldVec.size()>0 && !m_fieldVec[i]->isValid()) {
            sf::Text invalidText("    Invalid input", font, 18);
            invalidText.setPosition(50, y);
            invalidText.setFillColor(sf::Color::Red);
            fieldTexts.push_back(invalidText);
            y += 25;
        }
    }

    // הודעת שגיאה כללית אם שדה בטופס לא תקין
    for (size_t i = fieldLabels.size(); i < m_fieldVec.size(); ++i) {
        if (!m_fieldVec[i]->isValid()) {
            sf::Text invalidForm("  Invalid Form", font, 18);
            invalidForm.setPosition(50, y);
            invalidForm.setFillColor(sf::Color::Red);
            fieldTexts.push_back(invalidForm);
            y += 25;
        }
    }

    float buttonY = y + 30;

    // יצירת הכפתורים עם Butten
    Butten ApproveButton("APPROVE", sf::Vector2f(120, 40), sf::Vector2f(100, buttonY), sf::Color(50, 150, 50));
    Butten CancelButton("CANCEL", sf::Vector2f(120, 40), sf::Vector2f(280, buttonY), sf::Color(180, 0, 0));

    bool approved = false;

    while (confirmWindow.isOpen()) {
        sf::Event event;
        while (confirmWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                confirmWindow.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2f mousePos = confirmWindow.mapPixelToCoords(sf::Mouse::getPosition(confirmWindow));

                if (CancelButton.isClicked(mousePos)) {
                    confirmWindow.close();
                }

                if (ApproveButton.isClicked(mousePos)) {
                    std::cout << formTitle << " Confirmed! Returning to main menu." << std::endl;
                    approved = true;
                    confirmWindow.close();
                }
            }
        }

        confirmWindow.clear(sf::Color(240, 240, 240));
        confirmWindow.draw(title);

        for (auto& txt : fieldTexts)
            confirmWindow.draw(txt);

        ApproveButton.draw(confirmWindow);
        CancelButton.draw(confirmWindow);

        confirmWindow.display();
    }

    if (approved) {
        formManager->closeForm();
    }
}
