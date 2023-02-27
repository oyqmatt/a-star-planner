#include "astar/common.hpp"
#include <iostream>

int main(int argc, char ** argv){
    Position a{1,2};
    Position b{0,0};
    std::cout << (a<b) << std::endl;
    return 0;
}
