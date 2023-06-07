#include "Interface.h"

int get_int() {
    int a;
    while (!(std::cin >> a) || (std::cin.peek() != '\n'))
    {
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << "\nInput error. Try again.\n";
    }
    //    cin.ignore(32767, '\n');
    return a;
}


int main()
{
    int choice;
    while (true)
    {
        std::cout << "---------------------------------------------------------------------------------------\n";
        std::cout << "Type 1 to create the institute\n";
        std::cout << "Type 2 to add faculty to the institute\n";
        std::cout << "Type 3 to add teacher to the faculty\n";
        std::cout << "Type 4 to find the faculty\n";
        std::cout << "Type 5 to delete teacher from the faculty\n";
        std::cout << "Type 6 to delete the faculty\n";
        std::cout << "Type 7 to delete the institute\n";
        std::cout << "Type 8 to print the institute in console\n";
        std::cout << "Type 9 to print the institute to file\n";
        std::cout << "Type 10 to load the institute from the file\n";
        std::cout << "Type 11 to end the program\n";
        choice = get_int();
        std::cout << "---------------------------------------------------------------------------------------\n";
        if (choice == 1) // create the company
        {
            if (!institute_exists)
            {
                Interface::create_institute();
            }
            else
            {
                std::cout << "Can not perform the operation. Institute already exists\n";
            }
        }
        else if (choice == 2) // add workshop to the company
        {
            if (institute_exists)
            {
                Interface::add_faculty_to_institute();
            }
            else
            {
                std::cout << "Can not perform the operation. Institute does not exist\n";
            }
        }
        else if (choice == 3) // add equipment to the worksho
        {
            if (institute_exists)
            {
                Interface::add_teacher_to_faculty();
            }
            else
            {
                std::cout << "Can not perform the operation. Institute does not exist\n";
            }

        }
        else if (choice == 4) //find the workshop
        {
            if (institute_exists)
            {
                Interface::find_faculty();
            }
            else
            {
                std::cout << "Can not perform the operation. Institute does not exist\n";
            }
        }
        else if (choice == 5) // delete equipment from the workshop
        {
            if (institute_exists)
            {
                Interface::delete_teacher_from_faculty();
            }
            else
            {
                std::cout << "Can not perform the operation. Institute does not exist\n";
            }
        }
        else if (choice == 6) // delete the workshop
        {
            if (institute_exists)
            {
                Interface::delete_faculty_from_institute();
            }
            else
            {
                std::cout << "Can not perform the operation. Institute does not exist\n";
            }
        }
        else if (choice == 7) // delete the company
        {
            if (institute_exists)
            {
                Interface::delete_institute();
            }
            else
            {
                std::cout << "Can not perform the operation. Institute does not exist\n";
            }
        }
        else if (choice == 8) //print company to console
        {
            if (institute_exists)
            {
                Interface::print_institute_to_console();
            }
            else
            {
                std::cout << "Can not perform the operation. Institute does not exist\n";
            }
        }
        else if (choice == 9) // print company to file
        {
            if (institute_exists)
            {
                Interface::print_institute_to_file();
            }
            else
            {
                std::cout << "Can not perform the operation. Institute does not exist\n";
            }
        }

        else if (choice == 10) //load company from file
        {
            if (!institute_exists)
            {
                Interface::load_institute_from_file();
            }
            else
            {
                std::cout << "Can not perform the operation. Institute does not exist\n";
            }
        }
        else if (choice == 11) // end the program
        {
            if (institute_exists)
            {
                Interface::delete_institute();
            }
            break;
        }

    }
}
