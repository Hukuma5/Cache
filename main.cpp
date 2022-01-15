// Copyright 2018 Your Name <your_email>

#include <header.hpp>

int main() {
  std::vector<int> v{32768,  65536,   131072,  262144,
                     524288, 1048576, 2097152, 2359296};
  for (auto i : v) {
    direct_traversal(i);
  }
  for (auto i : v) {
    back_traversal(i);
  }
  for (auto i : v) {
    random_traversal(i);
  }
}
