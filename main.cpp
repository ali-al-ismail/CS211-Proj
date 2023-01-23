/*
Ali Ibrahim Alismail 2220005098
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

user get_new_user(){
    user new_user;
    std::cout << "Enter ID: ";
    std::cin >> new_user.id;
    std::cout << "Enter name: ";
    std::cin >> new_user.name;
    std::cout << "Enter username: ";
    std::cin >> new_user.username;
    std::cout << "Enter age: ";
    std::cin >> new_user.age;
    std::cout << "Enter score: ";
    std::cin >> new_user.score;
    return new_user;
}

std::vector<user> users;

int main(){
    std::fstream file;
    file.open("records.csv", std::ios::in);
    //read_file(file,users);
    file.close();

    int choice;
    bool loop = true;
    while(loop){
        std::cout << "---------------------------------------------------------------------------------------------------\n";
        std::cout << "1. Add record\n2. Edit record\n3. Delete record\n4. Sort records\n5. Display records\n6. Output stat file\n\n0. Save & Quit\n";
        std::cout << "---------------------------------------------------------------------------------------------------\n";
        std::cin >> choice;
        switch(choice){
            case 1:
                add_record(users, get_new_user());
                break;
            case 2:
                int id;
                std::cout << "Enter ID to edit: ";
                std::cin >> id;
                edit_record(users,id);
                break;
            case 3:
                std::cout << "Enter ID to edit: ";
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
                display_records(users);
                break;
            case 6:
                //output_stat_file(users);
                break;
            case 0:
                loop = false;
                //save_file(users);
                break;
            default:
                std::cout << "Invalid choice\n";
                break;
        }
    }

    return 0;
}