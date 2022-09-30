#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main(int argc, char** argv) {
    if (argc == 3) {
        std::ifstream fin(argv[1]);
        std::ofstream fout(argv[2]);

        std::vector<int> nums;
        int num;

        while (fin >> num) {
            nums.push_back(num);
        }

        auto uniqueNums = std::unique(nums.begin(), nums.end());
        nums.erase(uniqueNums, nums.end());

        auto unityCount = std::count(nums.begin(), nums.end(), 1);
        auto zeroCount = std::count(nums.begin(), nums.end(), 0);
        fout << unityCount << " "  << zeroCount;

        fin.close();
        fout.close();
    }
    else {
        std::cout << "Must be 2 arguments: input and output files";
    }
    return 0;
}