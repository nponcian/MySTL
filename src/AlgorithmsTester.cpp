#include <AlgorithmsTester.hpp>

#include <string>
#include <vector>

#include <Algorithms/Next_permutation.hpp>

namespace src
{
namespace
{

void testNextPermutation()
{
    std::string name{"abcd"};
    unsigned ctr = 1u;

    do
    {
        std::cout << "\nPermutation #" << ctr++ << " : " << name;
    }
    while (mystl::next_permutation(name));
}

} // namespace

void testAlgorithms()
{
    testNextPermutation();
}

} // namespace src
