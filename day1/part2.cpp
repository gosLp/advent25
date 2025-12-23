#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("cypher.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open cypher file." << std::endl;
        return 1;
    }

    std::string line;
    int total = 0;
    int position = 50;
    
    while (std::getline(file, line)) {
        char dir = line[0];
        int val = std::stoi(line.substr(1));
        
        int full = val / 100;
        int partial = val % 100;
        total += full;
        
        int delta = (dir == 'L') ? -partial : partial;
        int next_position = position + delta;
        
        if (position != 0) {
            if (dir == 'L' && next_position <= 0) {
                total += 1;
            } else if (dir == 'R' && next_position >= 100) {
                total += 1;
            }
        }
        
        position = ((next_position % 100) + 100) % 100;
    }
    
    std::cout << "Total times dial was at 0: " << total << std::endl;
    return 0;
}