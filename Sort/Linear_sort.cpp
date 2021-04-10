#include<iostream>
#include<algorithm>
#include<vector>

//Heap sort
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

int Partition(int* arr, int p, int r) {
	int x = arr[r];
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (arr[j] <= x) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[r]);
	return i + 1;
}

int Random_partition(int* array_list, int left, int right){
	srand(left);
	int ran_num = (rand()) % right;
	if ((ran_num < left)){
		ran_num = left;
	}
	swap(array_list[right], array_list[ran_num]);
	return Partition(array_list, left, right);
}

//计数排序
void Counting_Sort(int* a, int *b,int k,int len) {
	int* c = (int*)malloc((k+1) * sizeof(int));
	//int* b = (int*)malloc((len+1) * sizeof(int));
	for (int i = 0; i <= k;i++)c[i] = 0;
	for (int i = 0; i < len; i++) {
		c[a[i]]++;
		

	}
	for (int i = 1; i <= k; i++) c[i] += c[i - 1];
	for (int i = len - 1; i >= 0; --i) {
		int num1 = a[i];
		int num2 = c[num1];
		int s = num2;
		b[num2 - 1] = a[i];
		c[num1]--;
	}
}

int Find_MAX(int a[],int len) {
	int max = -0xfffffff;
	for (int i = 0; i < len; i++) {
		if (max < a[i])max = a[i];
	}
	return max;
}

//桶排序
template <typename T>

void Bucket_Sort(vector<T>&A, int n) {
	int i, j;
	vector<T> B[1000];  //桶容器
	for (i = 0; i < n; i++)
	{
		int temp = n * A[i];
		B[temp].push_back(A[i]);
	}
	for (i = 0; i < n; i++)
		sort(B[i].begin(), B[i].end());  //对每个桶排序
	int index = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < B[i].size(); j++)
			A[index++] = B[i][j];
	}
}
