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
  // size_t forest_len = 4;
  // size_t forest[forest_len];
}

int main(void) {
  test_union();
  test_find_replace();
}
