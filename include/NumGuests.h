#pragma once
#include <string>
#include <cctype>
#include "Validator.h"

class NumGuests : public Validator<int>
{
public:
	NumGuests(int&);
	virtual bool isValid() const;
};
