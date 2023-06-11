#pragma once
#include "Faculty.h"



class Institute
{
private:
	class Node {
		private:
			Faculty* faculty;
			Node* next;
		public:
			Node() {
				next = nullptr;
				faculty = nullptr;
			}
			~Node() {
				delete faculty;
				faculty = nullptr;
				next = nullptr;
			}

			Node* get_next() {
				return next;
			}

			void set_next(Node* _next) {
				next = _next;
			}



			Faculty* get_faculty() {
				return faculty;
			}

			void set_faculty(std::string _faculty_name) {
				faculty = new Faculty(_faculty_name);
			}
	};

	std::string institute_name;
	Node* first = nullptr;
	Node* last = nullptr;
public:

	Institute(std::string _institute_name)
	{
		institute_name = _institute_name;
	}

	~Institute()
	{
		Node* curr = first;
		Node* temp;
		while (curr != nullptr) {
			temp = curr;
			curr = curr->get_next();
			delete temp;
		}
		first = nullptr;
		last = nullptr;
	}


	std::string get_institute_name() {
		return institute_name;
	}

	void set_institute_name(std::string _name) {
		institute_name = _name;
	}


	void clear()
	{
		Node* curr = first;
		Node* temp;
		while (curr != nullptr) {
			temp = curr;
			curr = curr->get_next();
			delete temp;
		}
	}

	bool is_empty()
	{
		return first == nullptr;
	}

	Faculty* find_faculty(std::string _faculty_name) {
		Node* curr = first;
		while (curr != nullptr) {
			if (curr->get_faculty() != nullptr && curr->get_faculty()->get_faculty_name() == _faculty_name) return curr->get_faculty();
			curr = curr->get_next();
		}
		return nullptr;
	}


	void enqueue_faculty(std::string _faculty_name)
	{
		if (is_empty())
		{
			first = new Node();
			last = first;
			first->set_faculty(_faculty_name);
		}
		else
		{
			Node* temp = new Node();
			last->set_next(temp);
			last = last->get_next();
			last->set_faculty(_faculty_name);
		}
	}

	Faculty* dequeue_faculty()
	{
		if (!is_empty())
		{
			Node* temp = first;
			first = first->get_next();
			Faculty* faculty = new Faculty(temp->get_faculty()->get_faculty_name());
			delete temp;
			return faculty;
		}
		return nullptr;
	}

	void show_in_console()
	{
		
		std::cout << "The institute name: " << institute_name << ".Faculty in this institute:\n";
		if (is_empty()) {
			std::cout << "    <Empty>\n";
			return;
		}
		Node* curr = first;
		while (last != nullptr && curr != last->get_next()) {
			if (curr->get_faculty() != nullptr)
				curr->get_faculty()->show_in_console();
			curr = curr->get_next();
		}
	}

	void show_in_file(std::ofstream& out)
	{
		out << "The institute name: " << institute_name << ". Faculty in this institute:\n";
		if (is_empty()) {
			out << "    <Empty>\n";
			return;
		}
		Node* curr = first;
		while (last != nullptr && curr != last->get_next()) {
			curr->get_faculty()->show_in_file(out);
			curr = curr->get_next();
		}
	}

	Faculty* add_faculty_from_file(std::string _faculty_name)
	{
		enqueue_faculty(_faculty_name);
		return last->get_faculty();

	}
};
