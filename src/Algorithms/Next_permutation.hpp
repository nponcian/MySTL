#ifndef SRC_ALGORITHMS_NEXT_PERMUTATION_HPP
#define SRC_ALGORITHMS_NEXT_PERMUTATION_HPP

#include <algorithm>
#include <string>

namespace mystl
{

bool next_permutation(std::string& stringToPermutateSorted)
{
    for (int ctr = stringToPermutateSorted.size() - 1; ctr > 0; --ctr)
    {
        // Early continue is nice to avoid such nested {{{}}}. But to be clear with the purpose of
        // this block that finds first occurrence of greater item[ctr] than item[ctr-1] thus is
        // preferred for increased readability of purpose
        if (stringToPermutateSorted[ctr] > stringToPermutateSorted[ctr-1])
        {
            for (int ctr2 = stringToPermutateSorted.size() - 1; ctr2 >= ctr; --ctr2)
            {
                if (stringToPermutateSorted[ctr2] > stringToPermutateSorted[ctr-1])
                {
                    std::swap(stringToPermutateSorted[ctr2], stringToPermutateSorted[ctr-1]);
                    std::sort((stringToPermutateSorted.begin() + ctr), stringToPermutateSorted.end());
                    return true;
                }
            }
        }
    }
    return false;
}

} // namespace mystl

#endif // SRC_ALGORITHMS_NEXT_PERMUTATION_HPP
