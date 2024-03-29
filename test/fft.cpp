#include "fft.hpp"
#include <iostream>



void reorder(CArray &arr, const unsigned int &start, const unsigned int &size, const unsigned int &step) {
	for (unsigned int i = start; i < size + start - 1; i++) {
		std::swap(arr[i], arr[arr.size()-i]);
	}
}

void fft(CArray &arr, size_t N) {
	if (N <= 1) return;

	CArray a1 = arr[std::slice(0, N/2, 2)];
	CArray a2 = arr[std::slice(1, N/2, 2)];

	std::cout << "\na1: ";
	for (Complex i : a1) {
		std::cout << i;
	}
	std::cout << "\na2: ";
	for (Complex i : a2) {
		std::cout << i;
	}

	fft(a1);
	fft(a2);

	for (unsigned int i = 0; i < N/2; i++) {
		Complex t  = std::polar(1.0, -2 * PI * i / N) * a2[i];
		arr[i]     = a1[i] + t;
		arr[i+N/2] = a1[i] - t;
	}
}

void fft(CArray &arr) {
	size_t N = arr.size();	
	fft(arr, N);
}