#include <iostream>
#include "../module/module.h"

void main()
{
    std::string file;
    std::cout << "Enter file name with extension:" << std::endl;
    std::cin >> file;
    getwchar();
    module::SearchManager(file);
    std::cout << "Press any key to exit." << std::endl;
    getwchar();
}

