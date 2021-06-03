#include <bits/stdc++.h>

using namespace  std;

// Sorts the array using Insertion Sort technique in ascending order.
void insertion_sort(int arr[], int sz) {
	int i, key, pos;

	for (i = 1; i < sz; i++) {
		key = arr[i];
		pos = i - 1;

		// Comparing the current element with the elements of the subarray before it.
		while (pos >= 0 && arr[pos] > key) { 
			arr[pos + 1] = arr[pos]; // Shifting the elements 1 place to the right.
			--pos;
		}

		arr[pos + 1] = key; // Shifting the current element at the appropriate position in the subarray before it.
	}
}

int main() {
	int n, i;

	cout << "Enter the number of elements in the array: ";
	cin >> n; // Taking the size of array from the user.

	int arr[n];
	cout << "Enter the elements inside the array: \n";
	for (i = 0; i < n; i++) {
		cin >> arr[i]; // Taking elements of the array as input.
	}

	insertion_sort(arr, n); // Calling the insertion_sort function to sort the array.

	cout << "The array after sorting is: \n";
	for (i = 0; i < n; i++) {
		cout << arr[i] << " "; // Prints the sorted array.
	}
	cout << "\n";

	return 0;
}