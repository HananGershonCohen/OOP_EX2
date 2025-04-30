#include "ChoiceHotel.h"

ChoiceHotel::ChoiceHotel(std::pair<std::string, std::vector<std::string>> pair) :Validator(pair) {}

bool ChoiceHotel::isValid() const
{
    std::pair<std::string, std::vector<std::string>> pair = m_validator;
    std::string choice = pair.first;
    std::vector<std::string> choiceVec = pair.second;

    for (const auto& option : choiceVec)
    {
        if (choice == option)
            return true;
    }

    return false;
}