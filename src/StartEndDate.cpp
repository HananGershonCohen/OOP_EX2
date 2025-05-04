#include "StartEndDate.h"

StartEndDate::StartEndDate(std::vector<Date> DateVec)
	:Validator(DateVec)
{
}
//------------------------------------
bool StartEndDate::isValid() const
{
	//comparing only between two valid dates 
	if (m_validator.size() != 2)
		return false;

	if (!(m_validator.at(0).isValid()) || !(m_validator.at(1).isValid()))
		return false;


	return compareDates(m_validator.at(0).getDate(), m_validator.at(1).getDate());
}
//-------------------------------------
bool StartEndDate::compareDates(std::string d1, std::string d2) const
{
	auto parse = [](const std::string& date)
		{
			size_t pos1 = date.find('-');
			size_t pos2 = date.find('-', pos1 + 1);

			int day = std::stoi(date.substr(0, pos1));
			int month = std::stoi(date.substr(pos1 + 1, pos2 - pos1 - 1));
			int year = std::stoi(date.substr(pos2 + 1));

			return std::make_tuple(year, month, day);  // ??? ?????? ????
		};

	auto [y1, m1, d1_] = parse(d1);
	auto [y2, m2, d2_] = parse(d2);

	return std::tie(y1, m1, d1_) < std::tie(y2, m2, d2_);
}