#pragma once
#include <string>
#include "Validator.h"
#include "FieldBase.h"
#include "Date.h"

template <typename T>
class Field
{
public:
    Field(T& value) : m_value(value) {};
	bool isValid();
  
private:
	T m_value;
};

//SPECIALIZATION

template<> // Date
bool Field <Date>::isValid()
{
	return m_value.isValid();
}
