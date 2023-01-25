#include <iostream>
#include <string>
#include <vector>
#include "record.h"



// sequential search, but it's fine for now
int find_idx(std::vector<user> &users, int id){
    for(int i = 0; i < users.size(); i++){
        if(users[i].id == id){
            return i;
        }
    }
    return -1;
}

void add_record(std::vector<user> &users){ 
    user new_user;
    while(true){
        std::cout << "Enter ID: ";
        std::cin >> new_user.id;
        if(std::cin.fail() || new_user.id < 0 || find_idx(users,new_user.id) >= 0){
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "ID must be positive and unique." << std::endl;
        }
        else{
            break;
        }
    }

    std::cout << "Enter name: ";
    std::cin >> new_user.name;
    std::cout << "Enter username: ";
    std::cin >> new_user.username;
    while(true){
        std::cout << "Enter age: ";
        std::cin >> new_user.age;
        if(std::cin.fail() || new_user.age < 0 || new_user.score < 0){
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid input." << std::endl;
        }
        else{
            break;
        }
    }

        while(true){
            std::cout << "Enter score: ";
            std::cin >> new_user.score;
            if(std::cin.fail() || new_user.age < 0 || new_user.score < 0){
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Invalid input." << std::endl;
            }
            else{
                break;
            }
        }   

    users.push_back(new_user);
}

void find_record(std::vector<user> &users, int id){
    if(id >= 0){
        int i = find_idx(users,id);
        if(i >= 0){
        std::cout << "\nID: " << users[i].id << "\tName: " << users[i].name << "\tUsername: " << users[i].username << "\tAge: "
            << users[i].age << "\tScore: " << users[i].score << std::endl;
            }
        else{
            std::cout << "\nRecord not found" << std::endl;
        }
    }
    else{
        std::cout << "Invalid ID" << std::endl;
    }
    // wait for user to press enter
    std::cout << "\nPress Enter to continue...\n";
    std::cin.ignore(1000, '\n');
    std::cin.get();
    return;
}
void edit_record(std::vector<user> &users, int id){
    return;
}
void delete_record(std::vector<user> &users, int id){
    return;
}
void sort_records(std::vector<user> &users, short mode){
    return;
}
void display_records(std::vector<user> &users){
    if(users.size() > 0){
        for(int i = 0; i < users.size(); i++){
            std::cout << "ID: " << users[i].id << "\tName: " << users[i].name << "\tUsername: " << users[i].username << "\tAge: "
            << users[i].age << "\tScore: " << users[i].score << std::endl;
        }
    }
    else{
        std::cout << "\nNo records to display" << std::endl;
    }
    // wait for user to press enter
    std::cout << "\nPress Enter to continue...\n";
    std::cin.ignore(1000, '\n');
    std::cin.get();
    return;
}   