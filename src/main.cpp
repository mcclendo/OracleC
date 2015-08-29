#include <iostream>
#include <memory>
#include <string>

#include "WoodOrderManager.hpp"

int main(int argc, char *argv[]) {
    if(argc != 2) {
        std::cout << "usage: " << argv[0] << " <filename>" << std::endl;
        exit(-1);
    }

    WoodOrderManager manager;

    return 0;
}
