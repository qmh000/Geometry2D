#pragma once

#include <climits>

class Context {
public:
	size_t index = 0;
	size_t index_end = 0;
	size_t max_num_polygons = INT_MAX;
	size_t target_num = 0;
};