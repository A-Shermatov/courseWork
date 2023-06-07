#pragma once
#include <iostream>
#include <fstream>
#include <string>



class Teacher
{
private:
	std::string name = "";
	std::string position = "";
public:
	Teacher()
	{}

	~Teacher()
	{
		name = "";
		position = "";
	}

	void set_name(std::string _name) { name = _name; }

	void set_position(std::string _postion) { position = _postion; }

	std::string get_name() { return name; }

	std::string get_position() { return position; }

};
