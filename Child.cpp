#include "Child.h"

Child::Child()
{
}

Child::Child(string first_name_, string last_name_, int age)
{
	this->first_name_ = first_name_;
	this->last_name_ = last_name_;
	this->age = age;
}

Child::~Child()
{
}

bool Child::operator<(const Child& rhs)
{
	if (last_name_ < rhs.last_name_) 
	{
		return true;
	}
	else if (last_name_ == rhs.last_name_) 
	{
		if (first_name_ < rhs.first_name_) 
		{
			return true;
		}
		else if (first_name_ == rhs.first_name_)
		{
			if (age < rhs.age) {
				return true;
			}
		}
	}
	return false;
}

bool Child::operator<=(const Child& rhs)
{
	if (last_name_ < rhs.last_name_) 
	{
		return true;
	}
	else if (last_name_ == rhs.last_name_) 
	{
		if (first_name_ < rhs.first_name_) 
		{
			return true;
		}
		else if (first_name_ == rhs.first_name_) 
		{
			if (age <= rhs.age) 
			{
				return true;
			}
		}
	}
	return false;
}

bool Child::operator>(const Child& rhs)
{
	if (last_name_ > rhs.last_name_) 
	{
		return true;
	}
	else if (last_name_ == rhs.last_name_)
	{
		if (first_name_ > rhs.first_name_) 
		{
			return true;
		}
		else if (age > rhs.age) {
			return true;
		}
	}
	return false;
}

bool Child::operator>=(const Child& rhs)
{
	if (last_name_ > rhs.last_name_) 
	{
		return true;
	}
	else if (last_name_ == rhs.last_name_) 
	{
		if (first_name_ > rhs.first_name_) 
		{
			return true;
		}
		else if (first_name_ == rhs.first_name_) 
		{
			if (age >= rhs.age) 
			{
				return true;
			}
		}
		return false;
	}
}

bool Child::operator==(const Child& rhs)
{
	if (last_name_ == rhs.last_name_) 
	{
		if (first_name_ == rhs.first_name_) 
		{
			if (age == age) 
			{
				return true;
			}
		}
	}
	return false;
}

bool Child::operator!=(const Child& rhs)
{
	if (last_name_ == rhs.last_name_)
	{
		if (first_name_ == rhs.first_name_) 
		{
			if (age == age) 
			{
				return false;
			}
		}
	}
	return true;
}