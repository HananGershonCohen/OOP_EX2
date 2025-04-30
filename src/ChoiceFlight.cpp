#include "ChoiceFlight.h"

ChoiceFlight::ChoiceFlight(ValidatorType pair) : Validator(pair) {}

bool ChoiceFlight::isValid() const
{
    ValidatorType pair = m_validator;
    std::string choice = pair.first;
    std::vector<std::pair <std::string,bool>> pairsVec = pair.second;
    std::vector <std::string>  choiceVec;
    for (int i = 0; i < pairsVec.size(); i++)
    {
        choiceVec.push_back(pairsVec.at(i).first);
    }

    std::string word;
    std::vector<std::string> wordsVec;
    for (int i = 0; i < choice.size(); i++)
    {
        char c = choice[i];
        if (c != ' ' && c != '|')
            word += c;
        else
        {
            wordsVec.push_back(word);
            word = "";
        }
    }

    if (choice == "Don't Care")
        return true;

    
    for (const std::string& word : wordsVec)
    {
        if (std::find(choiceVec.begin(), choiceVec.end(), word) == choiceVec.end())
        {
            return false;
        }
    }


    return true;
}