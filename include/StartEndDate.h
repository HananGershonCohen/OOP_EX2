#pragma once
#include <string>
#include <vector>
#include <cctype>
#include "Validator.h"
#include "Date.h"

class StartEndDate : public Validator<std::vector<Date>>
{
public:

	StartEndDate(std::vector<Date>);
	bool isValid() const;

private:
	bool compareDates(std::string, std::string) const;

};