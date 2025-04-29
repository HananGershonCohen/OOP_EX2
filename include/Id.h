#pragma once
#include <string>
#include <cctype>
#include "Validator.h"

class Id : public Validator<int>
{
public:

	Id(int& id);
	bool isValid() const;

private:

};
