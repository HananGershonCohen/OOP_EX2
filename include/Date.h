#pragma once
#include "Validator.h"
#include <string>

class Date : public Validator<std::string>
{
public:
	Date(std::string = getTodayDate());
	virtual ~Date() = default;
	virtual bool isValid() const override ;

private:
	static std::string getTodayDate();
};

