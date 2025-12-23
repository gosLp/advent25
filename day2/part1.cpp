#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>


bool isDoubleSequence(long number) {
    std::string numStr = std::to_string(number);
    int len = numStr.length();
    if (len % 2 != 0) {
        return false;
    }
    std::string fHalf = numStr.substr(0, len / 2);
    std::string sHalf = numStr.substr(len / 2, len / 2);

    return fHalf == sHalf;
}

int main() {
    std::ifstream file("cypher.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open cypher file." << std::endl;
        return 1;
    }

    std::string range;
    long total = 0;
    
    while (std::getline(file, range, ',')) {
       std::istringstream ss(range);
       std::string token;
       std::vector<long> bounds;

       while(std::getline(ss, token, '-')) {
            std::cout << "Token: " << token << std::endl;
            bounds.push_back(std::stol(token));
       }

       if (bounds.size()==2) {
            long start = bounds[0];
            long end = bounds[1];

            for (long i= start; i <= end; i++) {
                if (isDoubleSequence(i)) {
                    total += i;
                }

            }
       }
    }
    
    std::cout << "Total times dial was at 0: " << total << std::endl;
    return 0;
}