#pragma once

class BaseField
{
public:
	BaseField() = default;
	virtual ~BaseField() = default;
	virtual	bool isValid() const = 0;
private:

};

