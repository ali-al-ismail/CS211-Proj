#include <fstream>
#include <vector>
#include "record.h"



int num_of_lines(std::fstream &file); // get number of lines in file (for vector population)
void read_file(std::fstream &file, std::vector<user> &users);
void save_file(std::vector<user> &users);
void output_stat_file(std::vector<user> &users);