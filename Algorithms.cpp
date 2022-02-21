#include <iostream>
#include <chrono>
#include <math.h>
using namespace std;
const int limit = 1000000;
void primeFinder01();
void primeFinder02();
void primeFinder03();
void primeFinder04();
void sieveOfEratosthenes();
void sieveOfEratosthenesV2();
void SieveOfAtkin();


int main() {
	
	auto start = chrono::high_resolution_clock::now();
	sieveOfEratosthenes();
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<float> duration = end - start;
	cout << endl << duration.count() << " s" << endl;

	return 0;
}

// Time complexity O(n^2)  1729.09 s (28 m)

void primeFinder01() { 
	int counter = 0;
	cout << 2 << endl;
	for (int i = 3; i < limit; i++) {
		for (int j = 2; j < i; j++) {
			if (i % j == 0)
				counter++;
		}
		if (counter == 0)
			cout << i << endl;
		counter = 0;
	}
}

// Time complexity O(n^2)  195.024 s  (3.15 m)		???

void primeFinder02() { 
	int counter = 0;
	cout << 2 << endl;
	for (int i = 3; i < limit; i++) {
		for (int j = 2; j < i; j++) {
			if (i % j == 0)
				counter++;
			if (counter == 1)
				break;
		}
		if (counter == 0) {
			cout << i << endl;
		}
		counter = 0;
	}
}


// Time complexity O(n.sqrt(n))  27.8937 s

void primeFinder03() {
	int counter = 0;
	cout << 2 << endl;
	for (int i = 3; i < limit; i++) {
		for (int j = 2; j <= int(sqrt(i)); j++) {
			if (i % j == 0)
				counter++;
			if (counter > 0)
				break;
		}
		if (counter == 0)
			cout << i << endl;
		counter = 0;
	}
}


// Time complexity O()  27.2221 s		???

void primeFinder04() {
	int counter = 0;
	const int n = limit / 2 - 1;
	int* arr = new int[n];
	int index = 0;
	for (int  i = 3; i <= limit; i += 2) {
		arr[index] = i;
		index++;
	}
	cout << 2 << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 3; j < int(sqrt(arr[i])) + 1; j += 2) {
			if (arr[i] % j == 0)
				counter++;
			if (counter == 1)
				break;
		}
		if (counter == 0) {
			cout << arr[i] << endl;
		}
		counter = 0;
	}
	delete[] arr;
}


// Time complexity O(N log (log N))  100.803 s

void sieveOfEratosthenes() {
	bool* prime = new bool[limit + 1];
	memset(prime, true, limit);

	for (int p = 2; p * p < limit; p++) {
		if (prime[p] == true) {
			for (int i = p * p; i <= limit; i += p) {
				prime[i] = false;
			}
		}
	}
	for (int i = 2; i <= limit/2 + 1; i+= 2) {
		if (prime[i])
			cout << i << endl;
	}

	delete[] prime;
}


// Time complexity O(n/(log log n))  37.5424 s

void SieveOfAtkin() {
	bool* arr = new bool[limit + 1];

	if (limit > 2)
		cout << "2" << endl;
	if (limit > 3)
		cout << "3" << endl;

	for (int i = 0; i < limit; i++) {
		arr[i] = false;
	}
	
	for (int x = 1; x * x < limit; x++) {
		for (int y = 1; y * y < limit; y++) {

			int n = (4 * x * x) + (y * y);
			if (n <= limit && (n % 12 == 1 || n % 12 == 5))
				arr[n] = true;

			n = (3 * x * x) + (y * y);
			if (n <= limit && n % 12 == 7)
				arr[n] = true;
			n = (3 * x * x) + (y * y);
			if (x > y && n <= limit && n % 12 == 11)
				arr[n] = true;
		}
	}

	for (int r = 5; r * r < limit; r++) {
		if (arr[r]) {
			for (int i = r * r; i < limit; i += r * r) {
				arr[i] = false;
			}
		}
	}
	for (int a = 5; a < limit; a++) {
		if (arr[a])
			cout << a << endl;
	}

	delete[] arr;
}
