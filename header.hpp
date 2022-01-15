// Copyright 2018 Your Name <your_email>
#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include <chrono>
#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#define MULT(x) x x x x x x x x x x
void direct_traversal(int N) {
  int* arr = new int[N];
  for (int i = 0; i < N; i += 16) {
    arr[i] = i + 16;
  }
  arr[N - 16] = 0;
  int k = 0;
  for (int i = 0; i < N; i += 16) {
    k = arr[i];
  }
  auto begin = std::chrono::steady_clock::now();
  for (int i = 0; i < 10000000; i++) {
    MULT(k = arr[k];)
  }
  auto end = std::chrono::steady_clock::now();
  auto elapsed_ms =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
  auto working_time = elapsed_ms;
  std::cout << "Time for N = " << N << ": " << working_time.count()
            << std::endl;
  delete[] arr;
}

void back_traversal(int N) {
  int* arr = new int[N];
  for (int i = N - 1; i >= 0; i -= 16) {
    arr[i] = i - 16;
  }
  arr[15] = N - 1;
  int k = 0;
  for (int i = N - 1; i >= 0; i -= 16) {
    k = arr[i];
  }
  auto begin = std::chrono::steady_clock::now();
  for (int i = 0; i < 10000000; i++) {
    MULT(k = arr[k];)
  }
  auto end = std::chrono::steady_clock::now();
  auto elapsed_ms =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
  auto working_time = elapsed_ms;
  std::cout << "Time for N = " << N << ": " << working_time.count()
            << std::endl;
  delete[] arr;
}

void random_traversal(int N) {
  int* arr = new int[N];
  std::vector<int> m(N / 16);
  for (int i = 0; i < static_cast<int>(m.size()); i++) {
    m[i] = i * 16;
  }
  auto seed = std::chrono::system_clock::now().time_since_epoch().count();
  unsigned b = static_cast<unsigned>(seed);
  std::default_random_engine e(b);
  std::shuffle(m.begin(), m.end(), e);
  for (int i = 0, l = 0; i < N; i += 16) {
    arr[i] = m[l];
    l++;
  }
  int k = 0;
  for (int i = 0; i < N; i += 16) {
    k = arr[i];
  }
  auto begin = std::chrono::steady_clock::now();
  for (int i = 0; i < 10000000; i++) {
    MULT(k = arr[k];)
  }
  auto end = std::chrono::steady_clock::now();
  auto elapsed_ms =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
  auto working_time = elapsed_ms;
  std::cout << "Time for N = " << N << ": " << working_time.count()
            << std::endl;
  delete[] arr;
}

#endif  // INCLUDE_HEADER_HPP_
