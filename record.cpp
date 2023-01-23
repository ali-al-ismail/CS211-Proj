#include <iostream>
#include <string>
#include <vector>
#include "record.h"



void add_record(std::vector<user> &users, user new_user){
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
    if(id < 0){
        for(int i = 0; i < users.size(); i++){
            std::cout << "ID: " << users[i].id << "\tName: " << users[i].name << "\tUsername: " << users[i].username << "\tAge: "
            << users[i].age << "\tScore: " << users[i].score << std::endl;
        }
    }
    else{
        return;
    }
    return;
}   