#include "RoomGuestMatcher.h"

RoomGuestMatcher::RoomGuestMatcher(std::pair<ChoiceHotel, NumGuests> pair)
	:Validator(pair) {
}



bool RoomGuestMatcher::isValid() const
{
	if (!(m_validator.first.isValid()) || !(m_validator.second.isValid()))
		return false;

	std::string roomType = m_validator.first.getRoomType();
	int numOfGuests = m_validator.second.getNumOfGuests();

	return match(roomType, numOfGuests);
}

bool RoomGuestMatcher::match(std::string roomType, int numOfGuests) const
{
	//Single Room","Double Room","Family Room","Presidential Suite
	if (roomType == "Single Room")
		return (numOfGuests == 1);
	if (roomType == "Double Room")
		return (numOfGuests == 2);
	if (roomType == "Family Room")
		return true;// famly room good for all number of guests
	if (roomType == "Presidential Suite")
		return (numOfGuests <= 6);

	return false;// didnt fund the room type
}