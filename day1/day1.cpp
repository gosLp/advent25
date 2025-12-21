#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
int main() {
    std::vector<int> dial;
    for( int i=0; i< 100; i++) {
        dial.push_back(i);
    }
    int start = 50;
    std::ifstream file("cypher.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open cypher file." << std::endl;
        return 1;
    }

    std::string line;
    int total = 0;
    int curr = start;
    while(std::getline(file, line)) {
        int direction = (line[0] == 'R') ? 1 : -1;
        int amount = std::stoi(line.substr(1));
        curr = (curr + direction * amount) % 100;
        if( curr == 0) total += 1;

    }
    std::cout << "Total times dial was at 0 :" << total << std::endl;
    return 0;
}