#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Usage: ./PmergeMe <positive integers...>\n";
        return 1;
    }
    try {
        PmergeMe pm;
        pm.parse(argc, argv);
        pm.print("Before:");
        pm.sort();
        pm.print("After:");
        std::cout << "Time to process a range of "
                  << pm.size() << " elements with std::vector : "
                  << pm.getTimeVec() << " us\n";
        std::cout << "Time to process a range of "
                  << pm.size() << " elements with std::deque  : "
                  << pm.getTimeDeq() << " us\n";
    } catch (std::exception &e) {
        std::cerr << e.what() << "\n";
        return 1;
    }

}