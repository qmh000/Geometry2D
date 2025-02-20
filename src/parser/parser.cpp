#include "parser.h"
#include <vector>
#include <cassert>
#include <thread>

const size_t buffer_size = 10 * 1024 * 1024;

inline bool file_exist(const char* path) {
	struct stat buffer;
	return (stat(path, &buffer) == 0);
}

std::vector<Polygon*> load_binary_file(const char* path, Context& global_ctx) {
	global_ctx.index = 0;
	global_ctx.index_end = 0;
	std::vector<Polygon*> polygons;
	if (!file_exist(path)) {
		printf("%s does not exist", path);
		exit(0);
	}

	std::ifstream infile;
	infile.open(path, std::ios::in | std::ios::binary);
	size_t num_polygons_infile = 0;
	infile.seekg(0, infile.end);
	//seek to the first polygon
	infile.seekg(-sizeof(size_t), infile.end);
	infile.read((char*)&num_polygons_infile, sizeof(size_t));
	assert(num_polygons_infile > 0 && "the file should contain at least one polygon");

	PolygonMeta* pmeta = new PolygonMeta[num_polygons_infile];
	infile.seekg(-sizeof(size_t) - sizeof(PolygonMeta) * num_polygons_infile, infile.end);
	infile.read((char*)pmeta, sizeof(PolygonMeta) * num_polygons_infile);
	// the last one is the end
	size_t num_polygons = std::min(num_polygons_infile, global_ctx.max_num_polygons);

	printf("loading %ld polygon from %s", num_polygons, path);

	char* buffer = new char[buffer_size];


	infile.close();
	delete[]pmeta;
	for (load_holder* lh : tasks) {
		delete lh;
	}
	logt("loaded %ld polygons", start, polygons.size());
	return polygons;
}