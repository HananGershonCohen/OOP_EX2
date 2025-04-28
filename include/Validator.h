#pragma once

template <typename T>
class Validator
{
public:
	Validator(T& val) : m_validator(val) {};
	virtual ~Validator() = default;
	virtual bool isValid() = 0;
	virtual T getValue() = 0;

protected:
	T m_validator;
};

