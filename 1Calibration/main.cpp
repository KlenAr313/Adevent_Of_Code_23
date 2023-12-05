#include <fstream>
#include <string>
#include <iterator>
#include <iostream>

int main(){
    std::ifstream input("input.txt");
    std::string line;

    bool first;
    bool found;
    int foundone;
    int ten;
    int one;
    int sum = 0;

    while(std::getline(input, line)){
        first = false;

        for(std::string::iterator it = line.begin(); it != line.end(); ++it){
            found = false;
            if (*it == 'o' && *(it + 1) == 'n' && *(it + 2) == 'e')
            {
                found = true;
                foundone = 1;
            }
            else if (*it == 't' && *(it + 1) == 'w' && *(it + 2) == 'o')
            {
                found = true;
                foundone = 2;
            }
            else if (*it == 't' && *(it + 1) == 'h' && *(it + 2) == 'r' && *(it + 3) == 'e' && *(it + 4) == 'e')
            {
                found = true;
                foundone = 3;
            }
            else if (*it == 'f' && *(it + 1) == 'o' && *(it + 2) == 'u' && *(it + 3) == 'r')
            {
                found = true;
                foundone = 4;
            }
            else if (*it == 'f' && *(it + 1) == 'i' && *(it + 2) == 'v' && *(it + 3) == 'e')
            {
                found = true;
                foundone = 5;
            }
            else if (*it == 's' && *(it + 1) == 'i' && *(it + 2) == 'x')
            {
                found = true;
                foundone = 6;
            }
            else if (*it == 's' && *(it + 1) == 'e' && *(it + 2) == 'v' && *(it + 3) == 'e' && *(it + 4) == 'n')
            {
                found = true;
                foundone = 7;
            }
            else if (*it == 'e' && *(it + 1) == 'i' && *(it + 2) == 'g' && *(it + 3) == 'h' && *(it + 4) == 't')
            {
                found = true;
                foundone = 8;
            }
            else if (*it == 'n' && *(it + 1) == 'i' && *(it + 2) == 'n' && *(it + 3) == 'e')
            {
                found = true;
                foundone = 9;
            }
            
            if(found){
                if(first){
                    one = foundone;
                }
                else{
                    first = true;
                    ten = foundone * 10;
                    one = foundone;
                }
            }
            else{
                if(first && *it >= '0' && *it <= '9'){
                    one = *it - '0';
                }

                if(!first && *it >= '0' && *it <= '9'){
                    first = true;
                    ten = (*it - '0') * 10;
                    one = *it - '0';
                }
            }
        }

        if(first){
            sum += ten;
            sum += one;
            std::cout << ten << one << std::endl;
        }
    }

    std::cout << sum << std::endl;
}