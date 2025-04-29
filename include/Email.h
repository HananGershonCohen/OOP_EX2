#pragma once
#include <string>
#include <cctype>
#include "Validator.h"

class Email : public Validator<std::string>
{
public:
	Email(std::string& email);
	bool isValid() const ;
private:
};