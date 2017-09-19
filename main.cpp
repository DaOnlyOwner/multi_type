#include <iostream>
#include <memory>
#include <vector>
#include <map>


#include "multi_type.h"

struct d
{

};

int main()
{

    multi_type<int, std::string, std::vector<int>,d> t = {4,"hi",{2,3},d()};
    std::cout<<(std::string) t << std::endl;
    int n = 3 * t;
    std::cout << n << std::endl;

    t = "Okay?";

    std::cout << (std::string&) t << std::endl;

    std::cout << static_cast<std::vector<int>&>(t)[0] << std::endl;



    return 0;
}