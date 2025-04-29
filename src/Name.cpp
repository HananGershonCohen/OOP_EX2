#include "Name.h"


Name::Name(std::string& name)
	:Validator(name)
{
}
//------------------------------
bool Name::isValid() const
{
	if (m_validator.empty())
		return false;
	for (char c : m_validator)
	{
		if (std::isdigit(c) )
			return false;
	}
	return true;
}