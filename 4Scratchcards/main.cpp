#include <fstream>
#include <iostream>
#include <string>
#include <iterator>
#include <sstream>
#include <set>
#include <vector>

class Card{
    public:
    int wined;
    int winCount;

    Card(int winCount): wined(1){
        this->winCount = winCount;
    }

    Card(const Card &other){
        this-> wined = other.wined;
        this-> winCount = other.winCount;
    }
};

int main(){
    std::fstream input("input.txt");
    std::string line;
    int sum = 0;
    std::vector<Card> cards;

    while(std::getline(input, line)){
        std::stringstream stline(line);
        std::string part;
        std::set<int> win;

        std::getline(stline, part, '|');
        std::stringstream strPart(part);

        std::string piece;
        while(std::getline(strPart, piece, ' ')){
            win.insert(std::stoi(piece));
        }

        std::getline(stline, part, '|');
        std::stringstream strPart2(part);
        int count = 0;
        while (std::getline(strPart2, piece, ' '))
        {
            if(win.find(stoi(piece)) != win.end()){
                count++;  
            }
        }
        Card one(count);
        cards.push_back(one);
    }

    //std::cout<< cards.size() << std::endl;

    for(std::vector<Card>::iterator it = cards.begin(); it != cards.end(); ++it){
        for(std::vector<Card>::iterator jt = it+1; jt != it + (it->winCount) +1; ++jt){
            jt->wined += it->wined;
        }
        //std::cout << it->wined  << std::endl;
    }

    for(std::vector<Card>::iterator it = cards.begin(); it != cards.end(); ++it){
        sum += it->wined;
    }

    std::cout << sum << std::endl;
}