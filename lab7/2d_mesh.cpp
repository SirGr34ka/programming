#include <math.h>

#include "2d_mesh.h"

bool is_it_possible_to_get(const int32_t sx, const int32_t sy, const int32_t fx, const int32_t fy, const uint32_t t)
{
    uint32_t mesh_rows = abs(fy - sy) + 1, mesh_columns = abs(fx - sx) + 1;

    uint32_t max_steps = mesh_rows * mesh_columns - 1;
    uint32_t min_steps = (uint32_t)sqrt(pow(mesh_columns, 2) + pow(mesh_rows, 2)) - 1;

    return (t <= max_steps && t >= min_steps);
}