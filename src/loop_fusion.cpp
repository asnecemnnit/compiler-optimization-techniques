// loop_fusion.cpp

#include "bits/stdc++.h"

// Original function to perform a multiply by 2 operation on an array
void OP_mult_by_2(int arr[], int size) {
  for (int i = 0; i < size; ++i) {
    arr[i] = arr[i] * 2;
  }
}

// Function to perform a multiply by 2 operation on two arrays using separate
// loops
void OP_mult_by_2_separate(int arr1[], int arr2[], int size) {
  for (int i = 0; i < size; ++i) {
    arr1[i] = arr1[i] * 2;
  }
  for (int i = 0; i < size; ++i) {
    arr2[i] = arr2[i] * 2;
  }
}

// Function to perform a multiply by 2 operation on two arrays using loop fusion
void OP_mult_by_2_fused(int arr1[], int arr2[], int size) {
  for (int i = 0; i < size; ++i) {
    arr1[i] = arr1[i] * 2;
    arr2[i] = arr2[i] * 2;
  }
}

int main() {
  const int size = 10;
  int array_original[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int array_separate_1[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int array_separate_2[size] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
  int array_fused_1[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int array_fused_2[size] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

  // Call the non-fused function
  OP_mult_by_2(array_original, size);

  // Call the function with separate loops
  OP_mult_by_2_separate(array_separate_1, array_separate_2, size);

  // Call the fused function
  OP_mult_by_2_fused(array_fused_1, array_fused_2, size);

  // Verify the arrays are the same after all operations
  // Verify the arrays are the same after all operations
  for (int i = 0; i < size; ++i) {
    assert(array_separate_1[i] == array_fused_1[i]);
    assert(array_separate_2[i] == array_fused_2[i]);
  }

  std::cout << "Loop Fusion demonstration successful!" << std::endl;

  return 0;
}
