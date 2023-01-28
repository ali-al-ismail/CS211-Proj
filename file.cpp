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
    // will output number of records, average age, average score, and the highest score / oldest person.
    // will also output the time of the last update
    std::fstream file;
    file.open("stats.txt",std::ios::trunc | std::ios::out); // open file in trunc mode to clear the file before writing
    file << "Number of records: " << users.size() << std::endl;
    
    int sum_age = 0;
    int sum_score = 0;
    for(int i = 0; i < users.size(); i++){
        sum_age += users[i].age;
        sum_score += users[i].score;
    }
    file << "Average age: " << sum_age / users.size() << std::endl;
    file << "Average score: " << sum_score / users.size() << std::endl;

    int max_age = 0;
    int max_score = 0;
    for(int i = 0; i < users.size(); i++){
        if(users[i].age > max_age){
            max_age = users[i].age;
        }
        if(users[i].score > max_score){
            max_score = users[i].score;
        }
    }
    file << "Oldest person: " << max_age << std::endl;
    file << "Highest score: " << max_score << std::endl;

    time_t loctime = time(0); // get the current time, its in UNIX timestamp
    char readabletime[26]; 
    strftime(readabletime, 26, "%Y-%m-%d %I:%M:%S %p", localtime(&loctime)); // format the time to our format, %I is for 12 hour clock, %p is for AM/PM
    file << "Last update: " << readabletime << std::endl;
    file.close();
}