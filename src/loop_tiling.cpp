// loop_tiling.cpp

#include "bits/stdc++.h"

// Function to perform a multiply by 2 operation on an array
void OP_mult_by_2(int arr[], int size) {
  for (int i = 0; i < size; ++i) {
    arr[i] = arr[i] * 2;
  }
}

// Function to perform a multiply by 2 operation on an array with loop tiling
void OP_mult_by_2_tiled(int arr[], int size, int tile_size) {
  // loop tiling: dividing the iterations of the outermost loop into smaller
  //              blocks, often referred to as tiles. The inner loops then
  //              operate on these smaller tiles of data
  //              better cache usage by ensuring that the data accessed by the
  //              inner loops is localized and fits within the cache
  for (int i = 0; i < size; i += tile_size) {
    for (int j = i; j < std::min(i + tile_size, size); ++j) {
      arr[j] = arr[j] * 2;
    }
  }
}

int main() {
  const int size = 10;
  int array_original[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int array_tiled[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  const int tile_size = 3;

  // Call the original function
  OP_mult_by_2(array_original, size);

  // Call the tiled function
  OP_mult_by_2_tiled(array_tiled, size, tile_size);

  // Verify the arrays are the same after both operations
  for (int i = 0; i < size; ++i) {
    assert(array_original[i] == array_tiled[i]);
  }

  std::cout << "Loop Tiling demonstration successful!" << std::endl;

  return 0;
}
