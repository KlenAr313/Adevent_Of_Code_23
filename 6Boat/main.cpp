#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <iostream>

int main(){
    std::fstream input("input.txt");
    std::string t;
    std::getline(input, t);
    std::stringstream times(t);
    std::string d;
    std::getline(input, d);
    std::stringstream disntances(d);
    std::string piece;

    long long pro = 1;
    long long ctime;
    long long cdist;
    while(std::getline(times, piece, ' ')){
        ctime = stoll(piece);
        std::getline(disntances, piece, ' ');
        cdist = stoll(piece);

        long long min = std::floor((ctime - std::sqrt(ctime * ctime - 4 * cdist)) / 2);
        long long max = std::ceil((ctime + std::sqrt(ctime * ctime - 4 * cdist)) / 2);
        std::cout << max - min -1  << std::endl;

        pro *= (max - min - 1);
    }

    std::cout << pro << std::endl;

}