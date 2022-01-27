#pragma once
#include <string>
#include <iostream>

class pipes // Testing class. This is gonna be removed later.
{
private:
    /* data */
public:

    int ID = 0;
    std::string str = "";
    void pipesInit();
    pipes(int _ID, std::string _str);
    ~pipes();
};

pipes::pipes(int _ID, std::string _str)
{
    ID = _ID;
    str = _str;
    std::cout << "PIPES INIT" << std::endl;
}

pipes::~pipes()
{
    std::cout << "Pipes " << str << " ID: " << ID << " died, rest in piss. You will not be missed. :pray:" << std::endl;
}

void pipes::pipesInit(){
    std::cout << "Pipes number " << ID << " instansiated: " << "Custom name: " << str << " ]" << std::endl;
}