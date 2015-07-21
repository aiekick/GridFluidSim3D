#pragma once

#include <stdio.h>
#include <iostream>
#include <vector>
#include <assert.h>

#include "implicitpointprimitive.h"
#include "array3d.h"
#include "grid3d.h"
#include "glm/glm.hpp"


class SurfaceField
{
public:
    SurfaceField();
    SurfaceField(int i_width, int j_height, int k_depth, double cell_size);
    ~SurfaceField();

    void getDimensions(double *w, double *h, double *d) { *w = width; *h = height; *d = depth; }
    double getWidth()  { return width; }
    double getHeight() { return height; }
    double getDepth()  { return depth; }

    void getGridDimensions(int *i, int *j, int *k) { *i = i_width; *j = j_height; *k = k_depth; }
    double getCellSize() { return dx; }

    void setSurfaceThreshold(double val) { surfaceThreshold = val; }
    void setMaterialGrid(Array3d<int> matGrid);
    void setMaterialGrid();
    double getSurfaceThreshold() { return surfaceThreshold; }

    virtual void clear();

    virtual double getFieldValue(glm::vec3 p);
    double getFieldValue(double x, double y, double z) { getFieldValue(glm::vec3(x, y, z)); }
    bool isInside(double x, double y, double z) { return isInside(glm::vec3(x, y, z)); }
    bool isInside(glm::vec3 p);
    bool isOutside(double x, double y, double z) { return isOutside(glm::vec3(x, y, z)); }
    bool isOutside(glm::vec3 p);
    bool _isPointNearSolid(glm::vec3 p);

    double width, height, depth;

protected:

    int i_width, j_height, k_depth;
    double dx = 1.0;

    Array3d<int> materialGrid;
    bool isMaterialGridSet = false;

    double surfaceThreshold;

    
};

