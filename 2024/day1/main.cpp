#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

void ParseInput(std::vector<int>& list1, std::vector<int>& list2) {
    std::ifstream inputFile("input.txt");
    while (inputFile) {
        int a = 0;
        int b = 0;
        inputFile >> a >> b;
        list1.push_back(a);
        list2.push_back(b);
    }
}

int main() {
    std::vector<int> list1;
    std::vector<int> list2;
    ParseInput(list1, list2);

    std::sort(list1.begin(), list1.end());
    std::sort(list2.begin(), list2.end());

    int result = 0;
    for (int i = 0; i < list1.size(); i++) {
        result += abs(list1[i] - list2[i]);
    }
    
    std::cout << result << std::endl;
    return 0;
}