#ifndef IPERMUTATION_H
#define IPERMUTATION_H

#include <vector>

namespace rsl
{
class IPermutation
{
public:
    virtual void reshuffle(std::vector<int>& arr) = 0;
};
}

#endif // IPERMUTATION_H
