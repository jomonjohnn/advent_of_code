/*
 * --- Day 1: Password Philosophy ---
 * Build with : g++ --std=c++17 -Wall -o day1 day1.cpp -lfmt
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>

#include <fmt/core.h>

/* Read from file and fill the vector */
auto ReadInput(const std::string inptfile) -> std::vector<int> {

  std::vector<int> nums;
  std::ifstream infstream(inptfile, std::ios::in);
  int input;

  while (infstream >> input) {
    nums.push_back(input);
  }

  return nums;
}

int main(int argc, char const *argv[]) {
  auto nums = ReadInput("01_input.txt");
  const int magicnum = 2020;

  /* Part 1 */
  /* find the two entries that sum to 2020 and then multiply those two numbers
   * together. */
  std::set<int> numsmap;

  for (auto num : nums) {
    if (numsmap.count((magicnum - num))) {
      fmt::print("Part I - [ {} , {}] - Product : {}\n", num, (magicnum - num),
                 (num * (magicnum - num)));
      break;
    } else {
      numsmap.insert(num);
    }
  }

  /* Part 2 */
  /* the three entries that sum to 2020 and find fproduct  */
  std::sort(nums.begin(), nums.end());
  std::set<int> threesumset(nums.cbegin(), nums.cend());
  bool found = false;

  for (auto i = nums.cbegin(); i != nums.cend(); i++) {
    for (auto j = ++i; j != nums.cend(); j++) {
      if (threesumset.count((magicnum - (*i + *j)))) {
        fmt::print("Part I - [ {} , {}, {}] - Product : {}\n", *i, *j,
                   (magicnum - (*i + *j)), (*i * *j * (magicnum - (*i + *j))));
        break;
      }
      if (found)
        break;
    }
  }

  return 0;
}
