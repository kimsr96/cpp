#include "RPN.hpp"

int main(int argc, char **argv){
    if (argc != 2){
        std::cerr << "Error" << std::endl;
        return 1;
    }
    RPN rpn;
    try{
        rpn.splitData(argv[1]);
        rpn.result();
    }
    catch(std::exception &e){
        std::cerr << e.what() << std::endl;
    }
    return 0;
}