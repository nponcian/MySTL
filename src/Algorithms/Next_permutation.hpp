#ifndef SRC_ALGORITHMS_NEXT_PERMUTATION_HPP
#define SRC_ALGORITHMS_NEXT_PERMUTATION_HPP

#include <algorithm>
#include <string>

namespace mystl
{

template <typename T>
bool next_permutation(T& objectToPermutate)
{
    for (auto currentIt = objectToPermutate.rbegin(), nextIt = ++(objectToPermutate.rbegin());
        currentIt != objectToPermutate.rend() and nextIt != objectToPermutate.rend();
        ++currentIt, ++nextIt)
    {
        // Early continue is nice to avoid such nested {{{}}}. But to be clear with the purpose of
        // this block that finds first occurrence of greater item[ctr] than item[ctr-1] thus is
        // preferred for increased readability of purpose
        if (*currentIt > *nextIt)
        {
            for (auto reverseIt = objectToPermutate.rbegin(); reverseIt != nextIt; ++reverseIt)
            {
                if (*reverseIt > *nextIt)
                {
                    std::swap(*reverseIt, *nextIt);
                    std::sort(nextIt.base(), objectToPermutate.end());
                    return true;
                }
            }
        }
    }
    return false;
}

} // namespace mystl

#endif // SRC_ALGORITHMS_NEXT_PERMUTATION_HPP
