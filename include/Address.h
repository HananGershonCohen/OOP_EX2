#pragma once
#include <string>
#include <cctype>
#include "Validator.h"

class Address : public Validator<std::string>
{
public:
	Address(std::string& address);
	bool isValid() const ;

private:
};