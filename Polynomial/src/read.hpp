#pragma once
#include <iostream>
#include <string>

template <typename Term>
Term read(const std::string &err, bool valid(Term))
{
    Term t;
    bool wrong;
    do{
        std::cin >> t;
        if((wrong = std::cin.fail())) std::cin.clear();
        std::string tmp = "";
        getline(std::cin, tmp);
        wrong = wrong || tmp.size()!=0 || !valid(t);
        if(wrong) std::cout << err << std::endl;
    }while(wrong);
    return t;
}