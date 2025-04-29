#include "Email.h"

Email::Email(std::string& email)
    : Validator(email)
{
}
bool Email::isValid() const
{
    const std::string& email = m_validator;

    size_t atPos = email.find('@');
    if (atPos == std::string::npos || atPos == 0 || atPos == email.length() - 1)
        return false;
    if (email.find('@', atPos + 1) != std::string::npos)
        return false; 

    std::string user = email.substr(0, atPos);
    std::string domain = email.substr(atPos + 1);

    if (email.find(' ') != std::string::npos)
        return false;

    for (char c : user)
    {
        if (!std::isalnum(c) && c != '.' && c != '-' && c != '_')
            return false;
    }

    for (char c : domain)
    {
        if (!std::isalnum(c) && c != '.' && c != '-' && c != '_')
            return false;
    }

    size_t lastDot = domain.rfind('.');
    if (lastDot == std::string::npos || lastDot >= domain.length() - 2)
        return false;

    std::string suffix = domain.substr(lastDot + 1);
    for (char c : suffix)
    {
        if (!std::isalpha(c))
            return false;
    }

    return true;
}
