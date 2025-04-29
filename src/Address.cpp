#include "Address.h"

Address::Address(std::string& address)
	:Validator(address)
{
}

bool Address::isValid() const
{
    const std::string& address = m_validator;

    int dashCount = std::count(address.begin(), address.end(), '-');
    if (dashCount != 2)
        return false;

    size_t firstDash = address.find('-');
    size_t secondDash = address.find('-', firstDash + 1);

    std::string street = address.substr(0, firstDash);
    std::string number = address.substr(firstDash + 1, secondDash - firstDash - 1);
    std::string city = address.substr(secondDash + 1);

    for (char c : street)
    {
        if (std::isdigit(c))
            return false;
    }

    if (number.empty())
        return false;
    for (char c : number)
    {
        if (!std::isdigit(c))
            return false;
    }

    for (char c : city)
    {
        if (std::isdigit(c))
            return false;
    }

    return true;
}
