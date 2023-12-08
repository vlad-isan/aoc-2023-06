//
// Created by Vlad Isan on 05/12/2023.
//

#include "puzzle.h"

int puzzle_sample_1(const std::string &base_file_path) {
    std::string file_path = fmt::format("{}/{}", base_file_path, "puzzle-input-sample-1.txt");

    std::ifstream file(file_path);

    if (!file.is_open()) {
        fmt::println("{}", file_path);
        fmt::println("Something happened while opening the file. EAT DEEZNUTS!!!");
        fmt::println("Error {}", strerror(errno));

        return 0;
    }

    return do_puzzle_1(file);
}

int puzzle_sample_2(const std::string &base_file_path) {
    std::string file_path = fmt::format("{}/{}", base_file_path, "puzzle-input-sample-2.txt");

    std::ifstream file(file_path);

    if (!file.is_open()) {
        fmt::println("{}", file_path);
        fmt::println("Something happened while opening the file. EAT DEEZNUTS!!!");
        fmt::println("Error {}", strerror(errno));

        return 0;
    }

    return do_puzzle_2(file);
}

int puzzle_1(const std::string &base_file_path) {
    std::string file_path = fmt::format("{}/{}", base_file_path, "puzzle-input-1.txt");

    std::ifstream file(file_path);

    if (!file.is_open()) {
        fmt::println("{}", file_path);
        fmt::println("Something happened while opening the file. EAT DEEZNUTS!!!");
        fmt::println("Error {}", strerror(errno));

        return 0;
    }

    return do_puzzle_1(file);
}

int puzzle_2(const std::string &base_file_path) {
    std::string file_path = fmt::format("{}/{}", base_file_path, "puzzle-input-2.txt");

    std::ifstream file(file_path);

    if (!file.is_open()) {
        fmt::println("{}", file_path);
        fmt::println("Something happened while opening the file. EAT DEEZNUTS!!!");
        fmt::println("Error {}", strerror(errno));

        return 0;
    }

    return do_puzzle_2(file);
}

int do_puzzle_1(std::ifstream &file) {
    std::string line;
    std::vector<Race> races;

    std::getline(file, line);

    std::istringstream iss(line);
    std::string ignore;
    double time;

    iss >> ignore;

    while (iss >> time) {
        races.emplace_back(Race{.time = time, .distance = 0});
    }

    std::getline(file, line);
    iss.str(line);
    iss.clear();

    iss >> ignore;

    double distance;
    size_t index = 0;

    while (iss >> distance) {
        races[index].distance = distance;
        index++;
    }

    uint64_t margin_of_error = 1;

    for (const auto &race: races) {
        margin_of_error *= race.get_ways_to_win();
    }

    return margin_of_error;
}

int do_puzzle_2(std::ifstream &file) {
    std::string line;
    std::vector<Race> races;

    std::getline(file, line);

    std::istringstream iss(line);
    std::string ignore;
    std::string current;
    std::string time;

    iss >> ignore;

    Race race{};

    while (iss >> current) {
        time += current;
    }

    race.time = std::stod(time);

    std::getline(file, line);
    iss.str(line);
    iss.clear();

    iss >> ignore;

    std::string distance;

    while (iss >> current) {
        distance += current;
    }

    race.distance = std::stod(distance);

    return race.get_ways_to_win();
}

uint64_t Race::get_ways_to_win() const {
    // calculate quadratic equation
    double a = -1;
    double b = this->time;
    double c = -this->distance;


    double discriminant = b * b - 4 * a * c;

    double sqrt_discriminant = sqrt(discriminant);

    double x1 = (-b + sqrt_discriminant) / (2 * a);
    double x2 = (-b - sqrt_discriminant) / (2 * a);
//    fmt::println("x1: {}, x2: {}", x1, x2);

    double margin = std::abs(std::ceil(x2 - 1) - std::floor(x1));
//    fmt::println("{}", margin);

    return margin;
}