#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <time.h>
#include "record.h"


int num_of_lines(std::ifstream &file){
    int num_of_lines = 0;
    std::string line;
    while(std::getline(file,line)){
        num_of_lines++;
    }
    return num_of_lines;
}

void read_file(std::ifstream &file, std::vector<user> &users){
    int size = num_of_lines(file);
    user new_user;
    std::string line;
    file.clear();
    file.seekg(0, std::ios::beg);
    for(int i = 0; i < size; i++){
        std::getline(file,line);
        int pos = line.find(",");
        new_user.id = std::stoi(line.substr(0,pos));
        line.erase(0,pos+1);
        pos = line.find(",");
        new_user.name = line.substr(0,pos);
        line.erase(0,pos+1);
        pos = line.find(",");
        new_user.username = line.substr(0,pos);
        line.erase(0,pos+1);
        pos = line.find(",");
        new_user.age = std::stoi(line.substr(0,pos));
        line.erase(0,pos+1);
        new_user.score = std::stoi(line);
        users.push_back(new_user);
    }
    return;
}
    


void save_file(std::vector<user> &users){
    std::fstream file;
    file.open("records.csv",std::ios::trunc | std::ios::out);
    for(int i = 0; i < users.size(); i++){
        file << users[i].id << "," << users[i].name << "," << users[i].username << "," << users[i].age << "," << users[i].score << std::endl;
    }
    file.close();
}

void output_stat_file(std::vector<user> &users){
    return;
}