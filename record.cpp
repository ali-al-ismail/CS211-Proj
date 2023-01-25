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
void add_record(std::vector<user> &users, user new_user){ 
    while(true){
        std::cout << "Enter ID: ";
        std::cin >> new_user.id;
        if(std::cin.fail() || new_user.id < 0 || find_idx(users,new_user.id) >= 0){ // ADDED SAFEGUARD FOR ID TO BE A NUMBER / further testing needed
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "ID must be positive and unique." << std::endl;
        }
        else{
            break;
        }
    }
    users.push_back(new_user);
    return;
}
void find_record(std::vector<user> &users, int id){
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
void display_records(std::vector<user> &users, int id = -1){
    if(id >= 0){
        int i = find_idx(users,id);
        if(i >= 0){
        std::cout << "ID: " << users[i].id << "\tName: " << users[i].name << "\tUsername: " << users[i].username << "\tAge: "
            << users[i].age << "\tScore: " << users[i].score << std::endl;
            }
        else{
            std::cout << "Record not found" << std::endl;
        }
    }
    // if id is -1, display all records
    else{
        for(int i = 0; i < users.size(); i++){
            std::cout << "ID: " << users[i].id << "\tName: " << users[i].name << "\tUsername: " << users[i].username << "\tAge: "
            << users[i].age << "\tScore: " << users[i].score << std::endl;
        }
    } 
    return;
}   