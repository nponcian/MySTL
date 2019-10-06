#include <iostream>

#include <AlgorithmsTester.hpp>
#include <ContainersTester.hpp>

int main(int /*argc*/, char** /*argv*/)
{
    std::cout << "\nThis is just a library";
    src::testContainers();
    src::testAlgorithms();

    std::cout << "\nEnd\n";
    return 0;
}

// cmake .. && make && src/mystl_src > output.txt
