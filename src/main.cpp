#include <iostream>

#include <ContainerTester.hpp>

int main(int /*argc*/, char** /*argv*/)
{
    std::cout << "\nThis is just a library";
    src::testContainer();

    std::cout << "\nEnd\n";
    return 0;
}

// cmake .. && make && src/mystl_src > output.txt
