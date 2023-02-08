#include <iostream>
#include <string>
#include <vector>
#include "record.h"
#include <algorithm>
#include <cmath>

#define ID 0
#define SCORE 1
#define AGE 2

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

    // getting name and username, using getline to account for spaces
    std::cout << "Enter name: ";
    std::cin.ignore(1000, '\n');
    std::getline(std::cin, new_user.name);
    if(new_user.name.empty()){
        new_user.name = "NoName_" + std::to_string(new_user.id);
    }
    std::cout << "Enter username: ";
    std::getline(std::cin, new_user.username);
    if(new_user.username.empty()){
        new_user.username = "Guest_" + std::to_string(new_user.id);
    }
    // getting age and score, using while loop to check for invalid inputs
    while(true){
        std::cout << "Enter age: ";
        std::cin >> new_user.age;
        if(std::cin.fail() || new_user.age <= 0){
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
            if(std::cin.fail() || new_user.score <= 0){
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Invalid input." << std::endl;
            }
            else{
                break;
            }
        }
        std::cout << "Enter game: ";
        std::cin.ignore(1000, '\n');
        std::getline(std::cin, new_user.game);
        if(new_user.game.empty()){
            new_user.game = "Temple Run";
        }
           

    users.push_back(new_user);
}


void find_record(std::vector<user> &users, int id){
    if(id >= 0){
        int i = find_idx(users,id);
        if(i >= 0){
        std::cout << "\nID: " << users[i].id << "\tName: " << users[i].name << "\tUsername: " << users[i].username << "\tAge: "
            << users[i].age << "\tScore: " << users[i].score << "\tGame: " << users[i].game << std::endl;
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
    if(id >= 0){
        int i = find_idx(users,id);
        if(i >= 0){
        std::cout << "Enter new name: ";
        std::cin.ignore(1000, '\n');
        std::getline(std::cin,users.at(i).name);
        if(users.at(i).name.empty())
            users.at(i).name = "NoName_" + std::to_string(users.at(i).id);
        std::cout << "Enter new username: ";
        std::getline(std::cin,users.at(i).username);
        if(users.at(i).username.empty())
            users.at(i).username = "Guest_" + std::to_string(users.at(i).id);

        while(true){
            std::cout << "Enter new age: ";
            std::cin >> users.at(i).age;
            if(std::cin.fail() || users.at(i).age <= 0){
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Invalid input." << std::endl;
            }
            else{
                break;
            }
        }

        while(true){
            std::cout << "Enter new score: ";
            std::cin >> users.at(i).score;
            if(std::cin.fail() || users.at(i).score <= 0){
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Invalid input." << std::endl;
            }
            else{
                break;
            }
            }

            std::cout << "Enter game: ";
            std::cin.ignore(1000, '\n');
            std::getline(std::cin, users.at(i).game);
            if(users.at(i).game.empty()){
                users.at(i).game = "Temple Run";
            }
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
    std::cin.get();
    return;
}


void delete_record(std::vector<user> &users, int id){
    if(id >= 0){
        int i = find_idx(users,id);
        if(i >= 0){
            users.erase(users.begin() + i);
            std::cout << "\nRecord deleted" << std::endl;
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


void sort_records(std::vector<user> &users,  short mode, bool order){
    // mode 1 = id, mode 2 = score, mode 3 = age. order = 0 for ascending, order = 1 for descending.
    if(mode == 1){
        if(order == 0){
            std::sort(users.begin(), users.end(), [](user a, user b){return a.id < b.id;});
        }
        else{
            std::sort(users.begin(), users.end(), [](user a, user b){return a.id > b.id;});
        }
    }
    else if(mode == 2){
        if(order == 0){
            std::sort(users.begin(), users.end(), [](user a, user b){return a.score < b.score;});
        }
        else{
            std::sort(users.begin(), users.end(), [](user a, user b){return a.score > b.score;});
        }
    }
    else if(mode == 3){
        if(order == 0){
            std::sort(users.begin(), users.end(), [](user a, user b){return a.age < b.age;});
        }
        else{
            std::sort(users.begin(), users.end(), [](user a, user b){return a.age > b.age;});
        }
    }
    else{
        std::cout << "Invalid mode" << std::endl;
    }
    return;
}


void display_records(std::vector<user> &users){
    if(users.size() > 0){
        for(int i = 0; i < users.size(); i++){
            std::cout << "ID: " << users[i].id << "\tName: " << users[i].name << "\tUsername: " << users[i].username << "\tAge: "
            << users[i].age << "\tScore: " << users[i].score << "\tGame: " << users[i].game << std::endl;
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