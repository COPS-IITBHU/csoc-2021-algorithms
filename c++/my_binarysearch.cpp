#include <iostream>

int main() {

  std::cout << "Enter the size of your array: ";
  int size;
  std::cin >> size;
  int arr[size];

  std::cout << "Enter your " << size <<" elements in sorted order: ";
  for (int i = 0; i < size; i++) {
    std::cin >> arr[i];
  }

  std::cout << "Enter the element you want to look up: ";
  int target;
  std::cin >> target;

  //Binary search

  int i = 0;
  int j = size - 1;
  bool check = false;

  while (i <= j) {
    int mid = ((unsigned int)i + (unsigned int)j) >> 1;
    if (arr[mid] == target) {
      check = true;
      std::cout << "Element found! Its index is: " << mid << ".\n";
      break;
    }
    else if (arr[mid] > target) j = mid - 1;
    else if (arr[mid] < target) i = mid + 1;
  }

  if (!check) {
    std::cout << "Element is not present in the array.\n";
  }
}
