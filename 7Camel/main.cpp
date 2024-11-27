#include <set>
#include <map>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iterator>

class Hand{
    std::map<char, int> cardCount;
public:
    std::string cards;
    int rank;
    int bid;
    Hand(std::string line){
        std::stringstream l(line);
        std::getline(l, cards, ' ');
        std::string num;
        std::getline(l, num, ' ');
        bid = stoi(num);

        int jokercount = 0;

        for(int i = 0; i < 5; i++){
            if(cards[i] == 'J'){
                cards[i] = '1';
                jokercount++;
            }
            else{
                cardCount[cards[i]]++;
            }
        }
        
        if(cardCount.size() != 1 && cardCount.size() != 0){
            std::map<char, int>::iterator max = cardCount.begin(); 
            for(std::map<char, int>::iterator it = cardCount.begin(); it != cardCount.end(); ++it){
                if(max->second < it->second){
                    max = it;
                }
            }
            max->second += jokercount;
        }


        if(cardCount.size() == 1 || jokercount == 5){
            rank = 7;
        }
        else if(cardCount.size() == 2 && (cardCount.begin()->second == 4 || cardCount.begin()->second == 1)){
            rank = 6;
        }
        else if(cardCount.size() == 2 && (cardCount.begin()->second == 3 || cardCount.begin()->second == 2)){
            rank = 5;
        }
        else if(cardCount.size() == 3 && (cardCount.begin()->second == 3 || cardCount.begin()->second == 1) 
            && ((++cardCount.begin())->second == 3 || (++cardCount.begin())->second == 1)){
            rank = 4;
        }
        else if(cardCount.size() == 3){
            rank = 3;
        }
        else if(cardCount.size() == 4){
            rank = 2;
        }
        else{
            rank = 1;
        }
        //std::cout << bid << "  " << cards << "," << rank << std::endl; 
    }

    bool operator<(const Hand& other) const
    {
        if(this->rank < other.rank){
            return true;
        }
        else if(this->rank > other.rank){
            return false;
        }
        else{
            for(int i = 0; i < 5; i++){
                if(this->cards[i] >= '1'  && this->cards[i] <= '9' && other.cards[i] >= '1'  && other.cards[i] <= '9' ){
                    if(this->cards[i] < other.cards[i]){
                        return true;
                    }
                    else if(this->cards[i] > other.cards[i]){
                        return false;
                    }
                }
                else if(this->cards[i] >= 'A' && other.cards[i] >= '1'  && other.cards[i] <= '9'  ){
                    return false;
                }
                else if(this->cards[i] >= '1'  && this->cards[i] <= '9' && other.cards[i] >= 'A'){
                    return true;
                }
                else{
                    if(this->cards[i] > other.cards[i]){
                        return true;
                    }
                    else if(this->cards[i] < other.cards[i]){
                        return false;
                    }
                }
            }
        }
        return false;
    } 
};

int main(){
    std::fstream input("input.txt");
    std::string line;
    std::set<Hand> hands;
    while(std::getline(input, line)){
        Hand h(line);
        hands.insert(h);
    }

    int sum = 0;
    int i = 1;
    for(std::set<Hand>::iterator it = hands.begin(); it != hands.end(); it++ ){
        //std::cout << it->bid << "*" << i << "  " << it->cards << "," << it->rank << std::endl; 
        sum += (it->bid * i);
        i++;
    }

    std::cout << sum << std::endl;
}