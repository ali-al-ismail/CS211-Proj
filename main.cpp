/*
Ali Ibrahim Alismail 2220005098


Nezar Salah Altarouti 2220003994

...
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "record.h"
#include "file.h"


/* TO DO:

    1. the to-do list

*/


std::vector<user> users;

int main(){
    std::ifstream file;
    file.open("records.csv", std::ios::in);
    read_file(file,users);
    file.close();

    int choice;
    bool loop = true;
    int id;
    while(loop){
        std::cout << "---------------------------------------------------------------------------------------------------\n";
        std::cout << "1. Add record\n2. Edit record\n3. Delete record\n4. Sort records\n5. Find record\n6. Display records\n7. Output stat file\n\n0. Save & Quit\n";
        std::cout << "---------------------------------------------------------------------------------------------------\n";
        std::cin >> choice;
        switch(choice){
            case 1:
                add_record(users);
                break;
            case 2:
                std::cout << "Enter ID to edit: ";
                std::cin >> id;
                edit_record(users,id);
                break;
            case 3:
                std::cout << "Enter ID to delete: ";
                std::cin >> id;
                delete_record(users,id);
                break;
            case 4:
                short mode;
                std::cout << "1. Sort by ID\n2. Sort by score\n3. Sort by age: ";
                std::cin >> mode;
                sort_records(users,mode);
                break;
            case 5:
                std::cout << "Enter ID to find: ";
                std::cin >> id;
                find_record(users,id);
                break;
            case 6:
                display_records(users);
                break;
            case 7:
                output_stat_file(users);
                break;
            case 0:
                loop = false;
                save_file(users);
                break;
            default:
                std::cout << "Invalid choice\n";
                break;
        }
    }

    return 0;
}