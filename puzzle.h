//
// Created by Vlad Isan on 05/12/2023.
//

#ifndef PUZZLE_H
#define PUZZLE_H

#include <algorithm>
#include <cctype>
#include "fmt/core.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <ranges>
#include <string>
#include <vector>

constexpr uint64_t ACCELERATION = 1;

struct Race {
    double time;
    double distance;

    uint64_t get_ways_to_win() const;
};

int puzzle_sample_1(const std::string &base_file_path);

int puzzle_sample_2(const std::string &base_file_path);

int puzzle_1(const std::string &base_file_path);

int puzzle_2(const std::string &base_file_path);

int do_puzzle_1(std::ifstream &file);

int do_puzzle_2(std::ifstream &file);

#endif //PUZZLE_H
