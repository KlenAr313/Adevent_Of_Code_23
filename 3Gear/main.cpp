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

    //std::cout << line0.length() << std::endl;

    for (int i = 0; i < (int)line0.length(); ++i)
    {
        if (line0[i] >= '0' && line0[i] <= '9')
        {
            int num = std::stoi(&(line0[i]));
            //std::cout << num << std::endl;
            std::string s = std::to_string(num);
            int end = s.length() + i;

            if ((i != 0 && (spec(line0[i - 1]) || spec(line1[i - 1]))) || ((int)line0.length() > end && (spec(line0[end]) || spec(line1[end]))))
            {
                sum += num;
                //std::cout << num << " " << (int)line0.length() << std::endl;
            }
            else
            {
                for (int j = i; j <= end - 1; ++j)
                {
                    if (spec(line1[j]))
                    {
                        sum += num;
                        //std::cout << num << std::endl;
                        break;
                    }
                }
            }
            i = end - 1; 
        }
    }

    for(int i = 1; i < 139; ++i){
        for (int i = 0; i < (int)line1.length(); ++i)
        {
            if (line1[i] >= '0' && line1[i] <= '9')
            {
                int num = std::stoi(&(line1[i]));
                //std::cout << num << std::endl;
                std::string s = std::to_string(num);
                int end = s.length() + i;

                if ((i != 0 && (spec(line1[i - 1]) || spec(line2[i - 1]) || spec(line0[i-1]))) 
                    || ((int)line1.length() > end && (spec(line1[end]) || spec(line2[end]) || spec(line0[end]))))
                {
                    sum += num;
                    //std::cout << num << std::endl;
                }
                else
                {
                    for (int j = i; j <= end-1; ++j)
                    {
                        if (spec(line2[j]) || spec(line0[j]))
                        {
                            sum += num;
                            //std::cout << num << std::endl;
                            break;
                        }
                    }
                }
                i = end - 1; 
            }
        }
        if(i < 138){
            line0 = line1;
            line1 = line2;
            std::getline(input, line2);
            //std::cout << line0 << "  " << line1 << "  " << line2 << std::endl;
        }
    }


    for (int i = 0; i < (int)line2.length(); ++i)
    {
        if (line2[i] >= '0' && line2[i] <= '9')
        {
            int num = std::stoi(&(line2[i]));
            //std::cout << num << std::endl;
            std::string s = std::to_string(num);
            int end = s.length() + i;

            if ((i != 0 && (spec(line2[i - 1]) || spec(line1[i - 1]))) || ((int)line2.length() > end && (spec(line2[end]) || spec(line1[end]))))
            {
                sum += num;
                //std::cout << num << std::endl;
            }
            else
            {
                for (int j = i; j <= end - 1; ++j)
                {
                    if (spec(line1[j]))
                    {
                        sum += num;
                        //std::cout << num << std::endl;
                        break;
                    }
                }
            }
            i = end - 1; 
        }
    }

    std::cout << sum << std::endl;
}