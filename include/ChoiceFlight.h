#pragma once
#include <string>
#include <cctype>
#include "Validator.h"
#include "vector"
#include <utility>
#include <iostream>

class ChoiceFlight : public Validator< std::pair<std::string, std::vector< std::pair<std::string , bool> > > >
{
public:
	using ValidatorType = std::pair<std::string, std::vector<std::pair<std::string, bool>>>;

	ChoiceFlight(ValidatorType pair); 
	virtual bool isValid() const;
};