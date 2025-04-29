#pragma once

class FieldBase
{
public:
	FieldBase() = default;
	virtual ~FieldBase() = default;
	virtual	bool isValid() = 0;
private:

};

