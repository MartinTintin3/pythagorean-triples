#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

template <typename T1, typename T2, typename T3>
using triple = std::tuple<T1, T2, T3>;

unsigned int GCD(unsigned int a, unsigned int b, unsigned int c) {
  for (int r = std::min(a, std::min(b, c)); true; --r)
    if (!(a % r | b % r | c % r))
      return r;
}

int main() {
  int limit;
  std::cout << "Maximum c value: ";
  std::cin >> limit;

  std::vector<triple<int, int, int>> triples = {};

  for (int c = 1; c <= limit; c++) {
    for (int a = 1; a < c; a++) {
      for (int b = 1; b < a; b++) {
        if (a * a + b * b == c * c) {
          int temp_a = ((a < b) ? a : b);
          int temp_b = ((a < b) ? b : a);

          triple<int, int, int> t = {temp_a, temp_b, c};

          if (std::find(triples.begin(), triples.end(), t) != triples.end() ||
              GCD(temp_a, temp_b, c) != 1) {
            continue;
          } else {
            triples.push_back(t);
            std::cout << "a: " << ((a < b) ? a : b)
                      << " b: " << ((a < b) ? b : a) << " c: " << c << "\n";
          }
        }
      }
    }
  }
}
