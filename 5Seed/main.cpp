#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <iostream>
#include <list>

class Location{
public:
    long long Min;
    long long Range;

    Location(long long min, long long range){
        this->Min = min;
        this->Range = range;
    }

    Location(const Location& other){
        this->Min = other.Min;
        this->Range = other.Range;
    }

    Location* cut(long long range1){
        long long nMin = Min + range1;
        long long nRange = Range - range1 ;
        this->Range = range1;

        Location *next = new Location(nMin, nRange);
        return next;
    }

};

class Converter{
    long long min;
    long long max;
    long long dif;

public:
    Converter(long long destination, long long source, long long range){
        min = source;
        max = source + range - 1;
        dif = destination - source;
    }

    bool in(std::list<Location>::iterator l){
        //std::cout << l->Min << l->Range << std::endl;
        if(min <= l->Min && l->Min <= max){
            //std::cout << "in" << std::endl;
            return true;
        }
        return false;
    }

    bool needCut(Location& l){
        //std::cout << l.Min + l.Range << std::endl;
        return (l.Min+l.Range -1) > max;
    }

    void convert(Location& l){
        //std::cout << "Before Change: " << l.Min << std::endl;
        l.Min += dif;
        std::cout << "after Change simp: " << l.Min << std::endl;
    }

    const Location* convertWcut(Location& l){
        long long r = max - l.Min + 1;
        //std::cout << "Before Cut: " << l.Min << std::endl;
        Location *next = l.cut(r);
        l.Min += dif;
        std::cout << "after Cut: " << l.Min << std::endl;
        return next;
    }
};

int main(){
    std::fstream input("examp.txt");

    std::string line;
    std::getline(input, line);
    std::stringstream seedStream(line);

    std::list<Location> locations;
    std::string seed;
    std::string range;
    while(std::getline(seedStream, seed, ' ')){
        std::getline(seedStream, range, ' ');
        Location *l = new Location(stoll(seed), stoll(range));
        locations.push_back(*l);
    }

    std::vector<std::vector<Converter>*> Almanac;
    std::getline(input, line);
    std::string num;
    while(std::getline(input, line)){
        std::vector<Converter> *convertes = new std::vector<Converter>;
        while(line != "#"){
            std::stringstream stream(line);
            std::getline(stream, num, ' ');
            long long dest = stoll(num);
            std::getline(stream, num, ' ');
            long long source = stoll(num);
            std::getline(stream, num, ' ');
            long long r = stoll(num);
            Converter c(dest, source, r);
            convertes->push_back(c);
            std::getline(input, line);
        }
        Almanac.push_back(convertes);
    }

    for(std::vector<std::vector<Converter>*>::iterator ait = Almanac.begin(); ait != Almanac.end(); ++ait)
    {
        for(std::list<Location>::iterator lit = locations.begin(); lit != locations.end(); ++lit)
        {
            for(std::vector<Converter>::iterator cit = (*ait)->begin(); cit != (*ait)->end(); ++cit)
            {
                std::cout << "Check: " << lit->Min << std::endl;
                if(cit->in(lit)){
                    std::cout << "In Range: " << lit->Min << std::endl;
                    if(cit->needCut(*lit)){
                        locations.push_back(*(cit->convertWcut(*lit))); 
                        std::cout << (--locations.end())->Min << "  " << (--locations.end())->Range << std::endl;
                    }
                    else{
                        cit->convert(*lit);
                    }
                    break;                
                }
            }
        }
        std::cout << "#" << std::endl;
    }

    std::list<Location>::iterator minimum = locations.begin();
    for(std::list<Location>::iterator it = (++locations.begin()); it != locations.end(); ++it){
        if(minimum->Min > it->Min)
            minimum = it;
    }

    std::cout << minimum->Min << std::endl;
}