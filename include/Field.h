#pragma once

template <typename T>
class Field
{
public:
	Field(T& val) :m_value(val) {};

	bool isValid() const
	{
		return m_value.isValid();
	}

private:
	T m_value;
};