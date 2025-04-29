#pragma once

class BaseField
{
public:
	BaseField() = default;
	virtual ~BaseField() = default;
	virtual	bool isValid() = 0;
private:

};

