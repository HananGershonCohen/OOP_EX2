#include "NumGuests.h"


NumGuests::NumGuests(int& umGuests):Validator(umGuests) {}

bool NumGuests::isValid() const
{
    return (m_validator >= 1 && m_validator <= 15);
}
