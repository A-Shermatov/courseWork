#pragma once
#include <iostream>
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
	{}

	void set_name(std::string _name) { name = _name; }

	void set_position(std::string _position) { position = _position; }

	std::string get_name() { return name; }

	std::string get_position() { return position; }

};
