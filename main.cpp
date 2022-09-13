#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main(int argc, char** argv) {

    std::ifstream fin(argv[1]);
    std::ofstream fout(argv[2]);

    std::vector<int> nums;
    int num;

    while (fin >> num) {
        nums.push_back(num);
    }

    auto unique_nums = std::unique(nums.begin(), nums.end());
    nums.erase(unique_nums, nums.end());

    auto one_count = std::count(nums.begin(), nums.end(), 1);
    auto zero_count = std::count(nums.begin(), nums.end(), 0);
    fout << one_count << " "  << zero_count;

    fin.close();
    fout.close();
    return 0;
}