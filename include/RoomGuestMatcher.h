#pragma once
#include <string>
#include <cctype>
#include "Validator.h"
#include "vector"
#include <utility>
#include "ChoiceHotel.h"
#include "NumGuests.h"

class RoomGuestMatcher : public Validator<std::pair<ChoiceHotel, NumGuests>>
{
public:
	RoomGuestMatcher(std::pair<ChoiceHotel, NumGuests>);
	virtual bool isValid() const;
private:
	bool match(std::string, int) const;
};