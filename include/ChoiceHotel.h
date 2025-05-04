#pragma once
#include <string>
#include <cctype>
#include "Validator.h"
#include "vector"
#include <utility>

class ChoiceHotel : public Validator< std::pair<std::string, std::vector<std::string>> >
{
public:
	ChoiceHotel(std::pair<std::string, std::vector<std::string>>);
	virtual bool isValid() const;
	std::string getRoomType() const;
};