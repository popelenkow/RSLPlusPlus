#ifndef PERMUTATIONSHIFT_H
#define PERMUTATIONSHIFT_H

#include <algorithm>

#include "Period.h"
#include "IPermutation.h"

namespace rsl
{
class PermutationShift final : public IPermutation
{
    //variables
public:
    int PosShift;


public:
    PermutationShift(int posShift = 1) : PosShift(posShift)
    {
    }

    virtual void reshuffle(std::vector<int>& arr)
    {
        int p = Period<int>::calculate(PosShift, 0, arr.size());
        std::rotate(arr.begin(), arr.begin()+p, arr.end());
    }
};
}

#endif // PERMUTATIONSHIFT_H
