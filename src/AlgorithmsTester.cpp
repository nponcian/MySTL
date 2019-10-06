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
    unsigned ctr = 1u;

    std::string letters{"abcd"};
    do
    {
        std::cout << "\nPermutation #" << ctr++ << " : " << letters;
    }
    while (mystl::next_permutation(letters));

    ctr = 1u;

    std::vector numbers{1, 3, 5, 7};
    do
    {
        std::cout << "\nPermutation #" << ctr++ << " :";
        for (const auto& num : numbers)
        {
            std::cout << " " << num;
        }
    }
    while (mystl::next_permutation(numbers));
}

} // namespace

void testAlgorithms()
{
    testNextPermutation();
}

} // namespace src
