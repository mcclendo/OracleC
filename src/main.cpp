#include <iostream>
#include <memory>
#include <string>

#include "WoodOrderManager.hpp"

int main(int argc, char *argv[]) {
    if(argc != 2) {
        std::cout << "usage: " << argv[0] << " <filename>" << std::endl;
        exit(-1);
    }

    std::string filename(argv[1]);

    try {
        WoodOrderManager manager;
        manager.initializeData(filename);
    }
    catch(WoodOrderManagerException &e) {
        std::cout << "An error occurred: " << e.what() << std::endl;
    }

    return 0;
}
