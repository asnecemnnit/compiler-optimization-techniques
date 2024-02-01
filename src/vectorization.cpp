// vectorization.cpp

#include "bits/stdc++.h"

// Function to perform a multiply by 2 operation on an array
void OP_mult_by_2(int arr[], int size) {
  for (int i = 0; i < size; ++i) {
    arr[i] = arr[i] * 2;
  }
}

// Function to perform a multiply by 2 operation on an array, optimized with
// vectorization
void OP_mult_by_2_vectorized(int arr[], int size) {
#pragma clang loop vectorize(enable) interleave(enable)
  // vectorize: compiler transforms a loop to use SIMD (Single Instruction,
  //            Multiple Data) instructions, allowing multiple operations to be
  //            performed in parallel on a vector of data
  // interleave: executing instructions from multiple iterations simultaneously
  //             or overlapping them, compiler interleaves multiple iterations
  //             of a loop to increase instruction-level parallelism
  for (int i = 0; i < size; ++i) {
    arr[i] = arr[i] * 2;
  }
}

int main() {
  const int size = 10;
  int array1[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int array2[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  // Call the function
  OP_mult_by_2(array1, size);
  OP_mult_by_2_vectorized(array2, size);

  for (int i = 0; i < size; ++i) {
    assert(array1[i] == array2[i]);
  }

  std::cout << "Vectorization demonstration successful!" << std::endl;

  return 0;
}
