// caching.cpp

#include "bits/stdc++.h"

// Function to perform a multiply by 2 operation on an array
void OP_mult_by_2(int arr[], int size) {
  for (int i = 0; i < size; ++i) {
    arr[i] = arr[i] * 2;
  }
}

// Function to perform a multiply by 2 operation on an array with loop
// reordering
void OP_mult_by_2_cached(int arr[], int size) {
  for (int i = 0; i < size; i += 2) {
    arr[i] = arr[i] * 2;
  }
  for (int i = 1; i < size; i += 2) {
    arr[i] = arr[i] * 2;
  }
}

int main() {
  const int size = 10;
  int array_original[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int array_cached[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  // Call the original function
  OP_mult_by_2(array_original, size);

  // Call the cached function
  OP_mult_by_2_cached(array_cached, size);

  // Verify the arrays are the same after both operations
  for (int i = 0; i < size; ++i) {
    assert(array_original[i] == array_cached[i]);
  }

  std::cout << "Caching demonstration successful!" << std::endl;

  return 0;
}
