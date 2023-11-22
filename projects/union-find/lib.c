#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

size_t find_root(size_t index, size_t forest[]) {
  size_t parent = forest[index];
  return parent == SIZE_MAX ? index : find_root(parent, forest);
}

void find_replace(size_t index, size_t new_parent, size_t forest[]) {
  size_t parent = forest[index];
  forest[index] = new_parent == index ? SIZE_MAX : new_parent;
  if (parent != SIZE_MAX) {
    find_replace(parent, new_parent, forest);
  }
}

size_t find_compress(size_t index, size_t forest[]) {
  size_t root = find_root(index, forest);
  find_replace(index, root, forest);
  return root;
}

void union_nodes(size_t index_a, size_t index_b, size_t forest[]) {
  size_t root_a = find_compress(index_a, forest);
  find_replace(index_b, root_a, forest);
}
