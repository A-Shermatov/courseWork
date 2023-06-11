#pragma once
#include "Teacher.h"
#include <iostream>
#include <string>
class Faculty
{
private:
	int MAX_NUM_TEACHERS = 3 + 1;
	std::string faculty_name;
	Teacher* teachers = new Teacher[MAX_NUM_TEACHERS];
	int count_teachers = 0;
public:
	Faculty(std::string _faculty_name)
	{
		faculty_name = _faculty_name;
	}

	~Faculty()
	{
		for (int i = 0; i < MAX_NUM_TEACHERS; ++i) {
			teachers[i].set_name("");
			teachers[i].set_position("");
		}
		teachers = nullptr;
	}


	bool is_empty()
	{
		return count_teachers == 0;
	}

	bool is_full()
	{
		return count_teachers == MAX_NUM_TEACHERS;
	}

	std::string get_faculty_name() {
		return faculty_name;
	}

	void set_faculty_name(std::string _name) {
		faculty_name = _name;
	}

	int get_empty_position(std::string _teacher_name)
	{
		if (is_empty()) return 0;
		if (_teacher_name < teachers[0].get_name()) {
			int index = -1;
			for (int i = 0; i <= MAX_NUM_TEACHERS; ++i) {
				if (teachers[i].get_name() == "" && teachers[i].get_position() == "") {
					index = i;
					break;
				}
			}
			if (index == -1) 
				return -1;
			else {
				for (int i = index; i > 0; --i) {
					teachers[i] = teachers[i - 1];
				}
				teachers[0].set_name("");
				teachers[0].set_position("");
				return 0;
			}
		}
		else if (_teacher_name >= teachers[MAX_NUM_TEACHERS - 1].get_name()) {
			int index = -1;
			for (int i = 0; i <= MAX_NUM_TEACHERS; ++i) {
				if (teachers[i].get_name() == "" && teachers[i].get_position() == "") {
					index = i;
					break;
				}
			}
			if (index == -1)
				return -1;
			else {
				for (int i = index; i < MAX_NUM_TEACHERS - 1; ++i) {
					teachers[i] = teachers[i + 1];
				}
				teachers[MAX_NUM_TEACHERS - 1].set_name("");
				teachers[MAX_NUM_TEACHERS - 1].set_position("");
				return MAX_NUM_TEACHERS - 1;
			}
		}
		else {
			int empty = -1;
			int index = -1;
			for (int i = 0; i < MAX_NUM_TEACHERS; ++i) {
				if (teachers[i].get_name() == "") {
					empty = i;
					continue;
				}
				if (teachers[i].get_name() <= _teacher_name) {
					if (i - empty == 1) 
						return empty;
					for (int j = empty; j < i - 1; ++j) {
						teachers[j] = teachers[j + 1];
					}
					teachers[i].set_name("");
					teachers[i].set_position("");
					return i;
				}
			}
		}
	}

	int find_position(std::string _teacher_name)
	{
		for (int i = 0; i < MAX_NUM_TEACHERS; ++i) {
			if (teachers[i].get_name() == _teacher_name) return i;
		}
		return -1;
	}

	Teacher find_teacher(std::string _teacher_name)
	{
		Teacher current = teachers[0];
		for (int i = 0; i < MAX_NUM_TEACHERS; ++i) {
			if (current.get_name() == _teacher_name) {
				return current;
			}
		}
		return Teacher();
	}
	void add_teacher(std::string _teacher_name, std::string _teacher_position) {
		int index = get_empty_position(_teacher_name);
		teachers[index].set_name(_teacher_name);
		teachers[index].set_position(_teacher_position);
		count_teachers++;
	}


	void delete_teacher(std::string _teacher_name)
	{
		int index = find_position(_teacher_name);
		if (index != -1) {
			teachers[index].set_name("");
			teachers[index].set_position("");
		}
		count_teachers--;
	}

	void show_in_console()
	{
		std::cout << "    Faculty name: " << faculty_name << '\n';
		if (is_empty()) {
			std::cout << "        <Empty>\n";
			return;
		}
		for (int i = 0; i < MAX_NUM_TEACHERS; ++i) {
			if (teachers[i].get_name() != "")
				std::cout << "        Teacher name: " << teachers[i].get_name() << "; teacher position: " << teachers[i].get_position() << '\n';
		}
	}
	void show_in_file(std::ofstream& out)
	{
		if (is_empty())
		{
			out << "Faculty_name:" << faculty_name << ".Teacher:" << "\n";
		}
		else
		{
			out << "Faculty_name:" << faculty_name << ".Teacher:";
			for (int i = 0; i < MAX_NUM_TEACHERS; ++i) {
				if (teachers[i].get_name() != "") {
					out << "|" << teachers[i].get_name() << "(" << teachers[i].get_position() << ")";
				}
			}
			if (count_teachers != 0) {
				out << "|" << "\n";
			}
		}
	}


};

