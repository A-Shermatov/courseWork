#pragma once
#include "Institute.h"
bool institute_exists = false;
Institute* institute;

void parse_faculty(std::string faculty)
{
    faculty = faculty.substr(faculty.find(':') + 1, faculty.find("\n"));
    if (faculty.size() == 0)
    {
        std::cout << "Invalid name for faculty\n";
        return;
    }
    Faculty* added_faculty = institute->add_faculty_from_file(faculty);
    faculty = faculty.substr(faculty.find(':') + 1, faculty.find("\n"));
    if (faculty.size() > 0)
    {
        faculty = faculty.substr(1, faculty.find('\n'));
    }




    while (faculty.size() > 0)
    {
        if (added_faculty->is_full())
        {
            std::cout << "Can not add teacher to full faculty\n";
            return;
        }
        std::string teacher_name = faculty.substr(0, faculty.find('('));
        if (teacher_name.size() == 0)
        {
            std::cout << "Teacher name can not be empty\n";
            return;
        }
        faculty = faculty.substr(faculty.find('(') + 1, faculty.find("\n"));
        std::string teacher_position = faculty.substr(0, faculty.find(')'));
        if (teacher_position.size() == 0)
        {
            std::cout << "Position of teacher can not be empty\n";
            return;
        }
        faculty = faculty.substr(faculty.find('|') + 1, faculty.find("\n"));
        added_faculty->add_teacher(teacher_name, teacher_position);
    }

}



class Interface
{
public:
    static void create_institute()
    {
        std::cout << "Type the name of the institute\n";
        std::string institute_name;
        std::cin >> institute_name;
        institute = new Institute(institute_name);
        institute_exists = true;
    }

    static void add_faculty_to_institute()
    {
        std::cout << "Type the name of the faculty you want to add\n";
        std::string faculty_name;
        std::cin >> faculty_name;
        if (faculty_name.size() == 0) {
            std::cout << "Invalid name!\n";
            return;
        }
        institute->enqueue_faculty(faculty_name);
    }

    static void add_teacher_to_faculty()
    {
        std::cout << "Type the name of the faculty you want to add an element to\n";
        std::string faculty_name;
        std::cin >> faculty_name;
        if (faculty_name.size() == 0)
        {
            std::cout << "Invalid name!\n";
            return;
        }
        Faculty* faculty_to_add_teacher = institute->find_faculty(faculty_name);
        if (faculty_to_add_teacher == nullptr)
        {
            std::cout << "Faculty not found\n";
            return;
        }
        if (faculty_to_add_teacher->is_full())
        {
            std::cout << "Can not add teacher to this faculty. It is already full\n";
            return;
        }
        std::cout << "Type the name of the teacher you want to add to the faculty\n";
        std::string teacher_name;
        std::cin >> teacher_name;
        if (teacher_name.size() == 0)
        {
            std::cout << "Invalid name for teacher\n";
            return;
        }
        std::cout << "Type the position of this teacher\n";
        std::string teacher_postion;
        std::cin >> teacher_postion;
        if (teacher_postion.size() == 0)
        {
            std::cout << "Invalid position of teacher" << std::endl;
            return;
        }
        faculty_to_add_teacher->add_teacher(teacher_name, teacher_postion);
        
    }

    



    static void delete_institute()
    {
        institute_exists = false;
        delete institute;
        institute = nullptr;
    }

    static void delete_faculty_from_institute()
    {
        
        Faculty* deleted_faculty = institute->dequeue_faculty();
        if (deleted_faculty != nullptr)
            std::cout << "Deleted faculty: " << deleted_faculty->get_faculty_name();
    }

    static void delete_teacher_from_faculty()
    {
        if (!institute->is_empty())
        {
            std::cout << "Type the name of faculty from which you want to delete the teacher\n";
            std::string faculty_name;
            std::cin >> faculty_name;
            if (faculty_name.size() == 0)
            {
                std::cout << "Invalid name!\n";
                return;
            }
            Faculty* faculty_to_delete_teacher = institute->find_faculty(faculty_name);
            if (faculty_to_delete_teacher == nullptr)
            {
                std::cout << "There is no such faculty in the institute\n";
                return;
            }
            if (faculty_to_delete_teacher->is_empty())
            {
                std::cout << "There is no teacher in this faculty\n";
                return;
            }
            
            std::cout << "Type the name of teacher you want to delete\n";
            std::string teacher_name;
            std::cin >> teacher_name;
            if (teacher_name.size() == 0) {
                std::cout << "Invalid name!\n";
                return;
            }
            faculty_to_delete_teacher->delete_teacher(teacher_name);
        }
        else
        {
            std::cout << "There are no teachers in the faculty\n";
        }
    }


    static void load_institute_from_file()
    {
        std::fstream in;
        in.open("output.txt", std::ios::in);
        if (!in.good()) {
            std::cout << "Can not open file!\n";
            return;
        }
        char line[1024];
        in.getline(line, 1024);
        std::string institute_name = line;
        institute_name = institute_name.substr(institute_name.find(':') + 1, institute_name.find('\n'));
        institute = new Institute(institute_name);
        institute_exists = true;
        int prev_number = 0;
        while (in.getline(line, 1024))
        {
            parse_faculty(line);
        }
        in.close();
    }

    static void find_faculty()
    {
        if (!institute->is_empty())
        {
            std::cout << "Type the name of the faculty you want to find in the institute\n";
            std::string faculty_name;
            std::cin >> faculty_name;
            if (faculty_name.size() == 0)
            {
                std::cout << "Invalid name!\n";
                return;
            }
            Faculty* faculty_to_find = institute->find_faculty(faculty_name);
            if (faculty_to_find == nullptr)
            {
                std::cout << "Faculty with this name was not found in the institute\n";
            }
            else
            {
                std::cout << "Faculty was found in the institute\n";
            }
        }
        else
        {
            std::cout << "There are no faculties in the institute.\n";
        }
    }



    static void print_institute_to_console()
    {
        institute->show_in_console();
    }

    static void print_institute_to_file()
    {
        std::ofstream out;
        if (!out.good()) {
            std::cout << "Can not open file!\n";
            return;
        }
        out.open("output.txt", std::ios::out);
        institute->show_in_file(out);
        out.close();
    }
};
