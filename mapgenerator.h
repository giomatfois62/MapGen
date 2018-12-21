#ifndef MAPGENERATOR_H
#define MAPGENERATOR_H

#include "matrix.h"

class MapGenerator
{
public:
    MapGenerator();

    Matrix<float> generate(int size, int seed);

private:
    void squareStep();
    void diamondStep();
};

#endif // MAPGENERATOR_H
