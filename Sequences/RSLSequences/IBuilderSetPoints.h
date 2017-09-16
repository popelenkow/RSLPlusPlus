#ifndef IBUILDERSETPOINTS_H
#define IBUILDERSETPOINTS_H

#include <vector>

#include "Vector3.h"


namespace rsl
{
class IBuilderSetPoints
{
public:
    virtual std::vector<Vector3<double>> Create(std::size_t count) = 0;
};
}


#endif // IBUILDERSETPOINTS_H
