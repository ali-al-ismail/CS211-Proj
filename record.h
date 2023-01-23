#ifndef RECORD_H
#define RECORD_H

#include <vector>
#include <string>

struct user{
    int id;
    std::string name;
    std::string username;
    int age;
    int score;
};


void add_record(std::vector<user> &users, user new_user);
void find_record(std::vector<user> &users, int id);
void edit_record(std::vector<user> &users, int id);
void delete_record(std::vector<user> &users, int id);
void sort_records(std::vector<user> &users, short mode);
void display_records(std::vector<user> &users, int id);

#endif