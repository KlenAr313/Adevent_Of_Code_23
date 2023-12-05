#include <fstream>
#include <iostream>
#include <string>
#include <iterator>

bool spec(char c)
{
    if (c != '.' && (c > '9' || c < '0'))
        return true;
    return false;
}

bool isNum(char c){
    if (c >= '0' && c <= '9')
        return true;
    return false;
}

int gear(std::string &line0, std::string &line1, std::string &line2, int i){
    int found = 0;
    int ratio = 1;
    if(i == 0){
        int num = 1;
        if(isNum(line0[i])){
            num = std::stoi(&(line0[i]));
            found++;
            ratio *= num;
        }
        else if(isNum(line0[i+1])){
            num = std::stoi(&(line0[i+1]));
            found++;
            ratio *= num;
        }

        num = 1;
        if(isNum(line1[i+1])){
            num = std::stoi(&(line1[i]));
            found++;
            ratio *= num;
        }

        num = 1;
        if(isNum(line2[i])){
            num = std::stoi(&(line2[i]));
            found++;
            ratio *= num;
        }
        else if(isNum(line2[i+1])){
            num = std::stoi(&(line2[i+1]));
            found++;
            ratio *= num;
        }
        
    }
    else if(i == 139){
        int num = 1;
        if(isNum(line1[i-1])){
            int j = i-2;
            while(isNum(line1[j])){
                j--;
            }
            num = std::stoi(&(line1[j+1]));
            found++;
            ratio *= num;
        }

        num = 1;
        if(isNum(line0[i])){
            int j = i-1;
            while(isNum(line0[j])){
                j--;
            }
            num = std::stoi(&(line0[j+1]));
            found++;
            ratio *= num;
        }
        else if(isNum(line0[i-1])){
            int j = i-2;
            while(isNum(line0[j])){
                j--;
            }
            num = std::stoi(&(line0[j+1]));
            found++;
            ratio *= num;
        }

        num = 1;
        if(isNum(line2[i])){
            int j = i-1;
            while(isNum(line2[j])){
                j--;
            }
            num = std::stoi(&(line2[j+1]));
            found++;
            ratio *= num;
        }
        else if(isNum(line2[i-1])){
            int j = i-2;
            while(isNum(line2[j])){
                j--;
            }
            num = std::stoi(&(line2[j+1]));
            found++;
            ratio *= num;
        }
    }
    else{
        int num = 1;
        if(isNum(line1[i-1])){
            int j = i-2;
            while(isNum(line1[j]) && j >= 0){
                j--;
            }
            num = std::stoi(&(line1[j+1]));
            found++;
            ratio *= num;
        }

        num = 1;
        if(isNum(line1[i+1])){
            num = std::stoi(&(line1[i+1]));
            found++;
            ratio *= num;
        }
        
        num = 1;
        if(!isNum(line0[i])){
            if(isNum(line0[i-1])){
                int j = i-2;
                while(isNum(line0[j]) && j >= 0){
                    j--;
                }
                num = std::stoi(&(line0[j+1]));
                found++;
                ratio *= num;   
            }

            num = 1;
            if(isNum(line0[i+1])){
                num = std::stoi(&(line0[i+1]));
                found++;
                ratio *= num;
            }
            
        }
        else{
            int j = i-1;
            while(isNum(line0[j]) && j >= 0){
                j--;
            }
            num = std::stoi(&(line0[j+1]));
            found++;
            ratio *= num;
        }

        //std::cout << "r:" << ratio << " n:" << num << std::endl;
        num = 1;
        if(!isNum(line2[i])){
            if(isNum(line2[i-1])){
                int j = i-2;
                while(isNum(line2[j]) && j >= 0){
                    j--;
                }
                num = std::stoi(&(line2[j+1]));
                found++;
                ratio *= num;
            }

            num = 1;
            if(isNum(line2[i+1])){
                num = std::stoi(&(line2[i+1]));
                found++;
                ratio *= num;
            }
        }
        else{
            int j = i-1;
            while(isNum(line2[j]) && j >= 0){
                j--;
            }
            num = std::stoi(&(line2[j+1]));
            found++;
            ratio *= num;
        }
    }

    //std::cout << found << std::endl;
    if(found >= 2){
        //std::cout << ratio << std::endl;
        return ratio;
    }
    else
        return 0;
}

int main()
{
    std::fstream input("input.txt");

    std::string line0;
    std::string line1;
    std::string line2;

    std::getline(input, line0);
    std::getline(input, line1);
    std::getline(input, line2);

    int sum = 0;

    for(int ln = 1; ln < 139; ++ln){
        for(int i = 0; i < (int)line1.length(); ++i){
            if(line1[i] == '*'){
                sum += gear(line0, line1, line2, i);
            }
        }
        line0 = line1;
        line1 = line2;
        std::getline(input, line2);
    }

    std::cout << sum << std::endl;
}