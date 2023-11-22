#include <stddef.h>

void init_forest(size_t forest[], size_t forest_len);

size_t find_root(size_t index, size_t forest[]);

void find_replace(size_t index, size_t new_parent, size_t forest[]);

size_t find_compress(size_t index, size_t forest[]);

void union_nodes(size_t index_a, size_t index_b, size_t forest[]);
