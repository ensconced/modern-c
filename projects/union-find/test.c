#include "lib.h"
#include <assert.h>
#include <stdint.h>

static const size_t forest_len = 6;

void test_union(void) {
  size_t forest[forest_len];
  init_forest(forest, forest_len);

  for (size_t i = 0; i < forest_len; ++i) {
    assert(find_root(i, forest) == i);
  }

  union_nodes(0, 1, forest);
  assert(find_root(0, forest) == find_root(1, forest));

  assert(find_root(1, forest) != find_root(2, forest));
  union_nodes(1, 2, forest);
  assert(find_root(1, forest) == find_root(2, forest));

  assert(find_root(3, forest) == 3);
  assert(find_root(4, forest) == 4);
  union_nodes(3, 4, forest);
  assert(find_root(3, forest) == find_root(4, forest));

  assert(find_root(5, forest) == 5);
  union_nodes(4, 5, forest);
  assert(find_root(3, forest) == find_root(4, forest));
  assert(find_root(4, forest) == find_root(5, forest));
  assert(find_root(3, forest) != find_root(0, forest));

  union_nodes(0, 5, forest);
  assert(find_root(0, forest) == find_root(1, forest));
  assert(find_root(1, forest) == find_root(2, forest));
  assert(find_root(2, forest) == find_root(3, forest));
  assert(find_root(3, forest) == find_root(4, forest));
  assert(find_root(4, forest) == find_root(5, forest));
}

void test_find_replace(void) {
  size_t forest[] = {1, SIZE_MAX, 1, SIZE_MAX};
  find_replace(2, 3, forest);
  assert(forest[0] == 1);
  assert(forest[1] == 3);
  assert(forest[2] == 3);
  assert(forest[3] == SIZE_MAX);
}

void test_find_compress(void) {
  size_t forest[] = {1, 2, 3, 4, SIZE_MAX, 4};
  size_t root = find_compress(0, forest);
  assert(root == 4);
  assert(forest[0] == 4);
  assert(forest[1] == 4);
  assert(forest[2] == 4);
  assert(forest[3] == 4);
  assert(forest[4] == SIZE_MAX);
  assert(forest[5] == 4);
}

int main(void) {
  test_find_replace();
  test_find_compress();
  test_union();
}
