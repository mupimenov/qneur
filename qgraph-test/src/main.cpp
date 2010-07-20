// place your code here
#include <iostream>
#include <sstream>
#include <string.h>
#include "HGraphTest.h"

int main() {
    std::cout << "Hello, world!" << std::endl;
    graph_test::HGraphTest* ht = new graph_test::HGraphTest();
    std::cout << "HGraphTest created." << std::endl;
    ht->runTest(); 
    std::cout << "Test complited" << std::endl;
    delete ht;   
    return 0;
}