#include <algorithm>
#include <cmath> // for std::abs
#include <iostream>
#include <vector>

int main() {
  std::vector<int> v1 = {3, 3, 12, 14, 17, 25, 30};
  std::vector<int> v2 = {2, 3, 12, 14, 24};

  // Part (a): Find the first element in v1 greater than 15 using find_if with a lambda
  auto it = std::find_if(v1.begin(), v1.end(), [](int x) { return x > 15; });
  if (it != v1.end()) {
    std::cout << "a) First element in v1 greater than 15: " << *it << std::endl;
  } else {
    std::cout << "a) No element greater than 15 found in v1." << std::endl;
  }

  // Part (b): Check "approximately equal" for intervals using equal with a lambda
  bool interval_5_equal = std::equal(v1.begin(), v1.begin() + 5, v2.begin(), [](int a, int b) {
    return std::abs(a - b) <= 2;
  });
  std::cout << "b) Are the first 5 elements of v1 and v2 approximately equal? "
            << (interval_5_equal ? "Yes" : "No") << std::endl;

  bool interval_4_equal = std::equal(v1.begin(), v1.begin() + 4, v2.begin(), [](int a, int b) {
    return std::abs(a - b) <= 2;
  });
  std::cout << "b) Are the first 4 elements of v1 and v2 approximately equal? "
            << (interval_4_equal ? "Yes" : "No") << std::endl;

  // Part (c): Replace all odd numbers in v1 with 100 using replace_copy_if with a lambda
  std::vector<int> v1_modified(v1.size());
  std::replace_copy_if(
      v1.begin(), v1.end(), v1_modified.begin(), [](int x) {
        return x % 2 != 0;
      },
      100);

  // Output the modified v1
  std::cout << "c) v1 after replacing odd numbers with 100: ";
  for (int num : v1_modified) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  return 0;
}
