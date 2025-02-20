#pragma once

#include "../geometry.h"
#include "context.h"
#include <fstream>

// the structured metadata of a polygon
typedef struct PolygonMeta_ {
	uint32_t size; // size of the polygon in bytes
	uint32_t num_vertices; // number of vertices in the boundary (hole excluded)
	size_t offset; // the offset in the file
} PolygonMeta;

typedef struct {
	std::ifstream* infile;
	size_t offset;
	size_t poly_size;
	size_t load(char* buffer) {
		infile->seekg(offset, infile->beg);
		infile->read(buffer, poly_size);
		return poly_size;
	}
}load_holder;

inline bool file_exist(const char* path);

std::vector<Polygon*> load_binary_file(const char* path, Context& global_ctx);
