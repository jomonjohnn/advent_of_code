/*
 * --- Day 2: Report Repair ---
 * Build with : g++ --std=c++17 -Wall -o day2 day2.cpp -lfmt
 */

#include <algorithm>
#include <fstream>
#include <regex>
#include <string>
#include <vector>

#include <fmt/core.h>

auto check_valid(const std::string &line) -> std::pair<bool, bool> {

  /*Pattern and Grouping */
  /* 4-15 b: fctbwzqnwbnvqbqlb */
  /* (4)-(15) (b): (fctbwzqnwbnvqbqlb) */
  std::regex regex("^([0-9]+)-([0-9]+)\\s([a-z]):\\s([a-z]+)$");
  std::smatch match;
  bool ret1{false}, ret2{false};

  if (std::regex_search(line, match, regex)) {

    std::string word(match.str(4));
    auto count = std::count(word.begin(), word.end(), match.str(3)[0]);

    /* part 1 */
    if (count >= std::stoi(match[1]) && count <= std::stoi(match[2])) {
      ret1 = true;
    }

    /* part 2 */
    int pos1 = std::stoi(match[1]) - 1;
    int pos2 = std::stoi(match[2]) - 1;

    char first = word[pos1];
    char second = word[pos2];
    char needed = match.str(3)[0];

    if ((first == needed && second != needed) ||
        (first != needed && second == needed)) {

      /*
      fmt::print(" char : {}  -- [{}({}) , {}({})] -- {}\n", needed, pos1,
                 first, pos2, second, word);
      */
      ret2 = true;
    }
  }

  return {ret1, ret2};
}

/* Read from file and process */
auto ProcessInput(const std::string &inptfile) -> std::pair<int, int> {

  int p1_count{0}, p2_count{0};

  std::ifstream infstream(inptfile, std::ios::in);

  while (infstream) {
    std::string line;
    std::getline(infstream, line);

    auto res = check_valid(line);

    /* Part 1 is valid */
    if (res.first) {
      p1_count++;
    }

    /* Part 2 is valid */
    if (res.second) {
      p2_count++;
    }
  }

  return {p1_count, p2_count};
}

int main(int argc, char const *argv[]) {

  auto count = ProcessInput("day2_input.txt");
  fmt::print(" Part 1 count : {}\n Part 2 Count : {}\n", count.first,
             count.second);

  return 0;
}
