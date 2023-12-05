#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

class SetMin{
private:
    int red;
    int blue;
    int green;
public:
    SetMin(): red(0), blue(0), green(0){}

    int minPow(){
        return red * blue * green;
    }

    void newStone(int num, char color){
        if(color == 'r'){
            if(num > red)
                red = num;
        }
        else if(color == 'g'){
            if(num > green)
                green = num;
        }
        else if(color == 'b'){
            if(num > blue)
                blue = num;
        }
    }
};

int main(){
    std::fstream input("input.txt");
    std::string line;
    int sum = 0;

    for (int i = 1; i <= 100; i++)
    {
        std::getline(input, line);

        std::stringstream ssin(line);
        std::string piece;
        SetMin set;
        while(std::getline(ssin, piece, ' ')){
            int num = std::stoi(piece);
            std::getline(ssin, piece, ' ');

            set.newStone(num, piece[0]);
        }
        sum += set.minPow();
    }

    std::cout << sum << std::endl;
    
}