#include<iostream>
#include<algorithm>
#include<cstring>
#include <random>
#include <chrono>
#include<math.h>
#include<cstdio>
#include<vector>
#include<stdio.h>
#include<cstring>
#include<string>
#include<string.h>
#include<set>
#include<map>
#include<stack>

#define speed ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;


int heap_size, heap_length;
int Parent(int i) {
	return i / 2;
}

int Left(int i) {
	return 2 * i;
}

int Right(int i) {
	return 2 * i + 1;
}

void MAX_Heapify(int* a, int i) {
	int l = Left(i);
	int r = Right(i);
	int largest = 0;
	if (l < heap_size && a[l] > a[i]) {
		largest = l;
	}
	else largest = i;
	if (r < heap_size && a[r] > a[largest]) largest = r;
	if (largest != i) {
		swap(a[i], a[largest]);
		MAX_Heapify(a, largest);
	}
}

void Build_MAX_HEAP(int* a) {
	heap_size = heap_length;
	for (int i = heap_length / 2 - 1; i >= 0; --i) {
		MAX_Heapify(a, i);
	}
}

void HeapSort(int* a,int len) {
	heap_length = len;
	Build_MAX_HEAP(a);
	for (int i = heap_length - 1; i >= 1; --i) {
		swap(a[0], a[i]);
		heap_size--;
		MAX_Heapify(a, 0);
	}
}


int main() {
  
	int a[10] = { 1,3,2,5,4,6,9,8,7,10 };
	int len = sizeof(a) / sizeof(a[0]);
	HeapSort(a, len);
	for (int i = 0; i < 10; i++)cout << a[i] << ' ';
}
