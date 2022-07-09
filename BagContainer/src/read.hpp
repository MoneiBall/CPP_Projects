#pragma once
#include <iostream>
#include <string>

template <typename Item>
Item read(const std::string &err, bool valid(Item))
{
    Item n;
    bool wrong;
    do{
        std::cin >> n;
        if((wrong = std::cin.fail())) std::cin.clear();
        std::string tmp = "";
        getline(std::cin, tmp);
        wrong = wrong || tmp.size()!=0 || !valid(n);
        if(wrong) std::cout << err << std::endl;
    }while(wrong);
    return n;
}
