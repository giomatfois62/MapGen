#include "mapgenerator.h"

#include <cmath>
#include <cstdio>

MapGenerator::MapGenerator()
{

}

Matrix<float> MapGenerator::generate(int size, int seed)
{
    int n = pow(2, size) + 1;
    Matrix<float> mat(n, n);

    int step = n - 1;
    float scale = 0.1f;

    srand48(seed);

    mat(0,0) = drand48() * scale;
    mat(0, n - 1) = drand48() * scale;
    mat(n - 1, 0) = drand48() * scale;
    mat(n - 1, n - 1) = drand48() * scale;

    while(step > 1)
    {
        // Diamond step
        for(int i = 0; i < n - 1; i += step)
        {
            for(int j = 0; j < n - 1; j += step)
            {
                float avg = mat(i,j) + mat(i+step, j) + mat(i, j+step)+ mat(i + step, j+step);
                avg /= 4.0f;
                avg += drand48() * scale - scale/2.0f;
                mat(i + step/2, j + step/2) = avg;
            }
        }

        // Square step
        bool isEven = true;
        for(int i = 0; i < n; i += step/2)
        {
            int start = isEven ? step/2 : 0;
            for(int j = start; j < n; j += step)
            {
                float left = j - step/2 < 0 ? mat(i , n - 1 - step/2) : mat(i , j - step/2);
                float right = j + step/2 >= n ? mat(i , step/2) : mat(i, j + step/2);
                float down = i + step/2 >= n ? mat(step/2, j) : mat(i + step/2, j);
                float up = i - step/2 < 0 ? mat(n - 1 - step/2, j) : mat(i - step/2, j);
                float avg = left + right + down + up;
                avg /= 4.0f;
                avg += drand48() * scale - scale/2.0f;
                mat(i, j) = avg;
            }
            isEven = !isEven;
        }

        step /= 2;
        scale *= 0.4f;
    }

    return mat;
}

void MapGenerator::squareStep()
{

}

void MapGenerator::diamondStep()
{

}
