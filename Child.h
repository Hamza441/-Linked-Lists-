#ifndef CHILD_H_
#define CHILD_H_

#include <string>
#include <iostream>

using namespace std;
class Child
{
public:
	Child();
	Child(string first_name_, string last_name_, int age);
	~Child();
	friend ostream& operator<<(ostream& outStream, const Child& rhs)
	{	
		outStream << rhs.first_name_ << rhs.last_name_ << rhs.age;
		return outStream;
	}
	bool operator < (const Child& rhs);
	bool operator <= (const Child& rhs);
	bool operator > (const Child& rhs);
	bool operator >= (const Child& rhs);
	bool operator == (const Child& rhs);
	bool operator != (const Child& rhs);


private:
	string first_name_;
	string last_name_;
	int age;
};
 #endif 