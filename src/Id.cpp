#include "Id.h"


Id::Id(int& id)
	:Validator(id)
{
}
//------------------------------------------------------
bool Id::isValid() const
{
	if (m_validator <= 0 || m_validator > 999999999) return false; // Basic check: positive number with up to 9 digits)
	int sum = 0;
	int tempId = m_validator; ;
	for (int i = 0; i < 9; ++i) {
		int digit = tempId % 10;
		int incNum = digit * ((8 - i) % 2 + 1); // Alternate multiplication from right to left
		sum += (incNum > 9) ? incNum - 9 : incNum;
		tempId /= 10;
	}
	return (sum % 10 == 0);

}