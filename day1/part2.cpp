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
        
        // Full rotations - each one crosses 0 exactly once
        int full = val / 100;
        int partial = val % 100;
        total += full;
        
        // Calculate next position (before modulo)
        int delta = (dir == 'L') ? -partial : partial;
        int next_position = position + delta;
        
        // Only count a crossing if we're not starting at 0
        if (position != 0) {
            if (dir == 'L' && next_position <= 0) {
                total += 1;
            } else if (dir == 'R' && next_position >= 100) {
                total += 1;
            }
        }
        
        // Wrap position to 0-99 range
        position = ((next_position % 100) + 100) % 100;
    }
    
    std::cout << "Total times dial was at 0: " << total << std::endl;
    return 0;
}