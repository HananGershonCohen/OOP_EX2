#pragma once
#include "BaseField.h"

template <typename T>
class Field :public BaseField 
{
public:
	Field(const T& val) :m_value(val) {};

	bool isValid() const
	{
		return m_value.isValid();
	}

private:
	T m_value;
};