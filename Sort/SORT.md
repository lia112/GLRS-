# 排序算法-GLRS 2-8章

算法|平均时间复杂度|最坏时间复杂度|空间复杂度|稳定性
-|-|-|-|-
插入排序|O（N^2）|O（N^2）|O(1)|稳定
归并排序|O(nlogn)|O(nlogn)|O（N)|稳定
快速排序|O(nlogn)|O(n^2)|O（logn）|不稳定
堆排序|O(nlogn)|O(nlogn)|O（1）|不稳定
计数排序|O(n+k)|O(n+k)|O(n+k)|稳定
桶排序|O（n）|O(nlogn)|O(n)|稳定


## 插入排序
```c
void InsertSort(int size) {
	for (int i = 1; i < size; i++) {        // 第 1 个数肯定是有序的，从第 2 个数开始遍历，依次插入有序序列
		int temp = arr[i];                // 取出第 i 个数，和前 i-1 个数比较后，插入合适位置
		int j = i - 1;                   // 因为前 i-1 个数都是从小到大的有序序列，所以只要当前比较的数 (array[j]) 比 temp 大，就把这个数后移一位
		while (j >= 0 && arr[j] > temp) { // 当 j < 0 或 array[j] < temp(array[i]) 时终止
			arr[j + 1] = arr[j];        // 将大于 temp(array[i]) 的数据后移
			j--;                            // 向前比较
		}                                   // 结束循环
		arr[j + 1] = temp;                // array[i]插入到正确的位置上
	}
}
```

## 归并排序
```c
void Merge(int* a, int p, int q, int r){
	int n1 = q - p + 1;       //左部分的的元素个数
	int n2 = r - q;           //同上
	int i, j, k;
	int* L = new int[n1 + 1];
	int* R = new int[n2 + 1];
	for (i = 0; i < n1; i++) L[i] = a[p + i];
	for (j = 0; j < n2; j++) R[j] = a[q + j + 1];
	L[n1] = 11111111;
	R[n2] = 11111111;
	// 数组L从0~n1-1存放，第n1个存放int型所能表示的最大数，即认为正无穷，这是为了
	//处理合并时，比如当数组L中的n1个元素已经全部按顺序存进数组a中，只剩下数组R的
	//部分元素，这时因为R中剩下的元素全部小于11111111,则执行else语句，直接将剩下的
	//元素拷贝进a中。
	for (i = 0, j = 0, k = p; k <= r; k++){
		if (L[i] <= R[j]) a[k] = L[i++];
		else a[k] = R[j++];
	}
	delete[]L;
	delete[]R;
}

void merge_sort(int* a, int l, int r){
	if (l < r){
		int m = (l + r) / 2;
		merge_sort(a, l, m);
		merge_sort(a, m + 1, r);
		Merge(a, l, m, r);
	}
}

## 快速排序
```c
void QuickSort(int array[], int low, int high) {
	if (low < high) {
		int i   = low;
		int j   = high;
        int key = array[i];
        while (i < j) {
			while (i < j && array[j] >= key) {
				j--;
			}
			if (i < j) {
				array[i] = array[j];
			}
			while (i < j && array[i] <= key) {
				i++;
			}
			if (i < j) {
				array[j] = array[i];
			}
		}
		array[i] = key;
		QuickSort(array, low, i - 1);
		QuickSort(array, i + 1, high);
    }
}
```

## 随机化快排&&HOARE
### 随机化快排
```cpp
int Random_partition(int* array_list, int left, int right){
	srand(left);
	int ran_num = (rand()) % right;
	if ((ran_num < left)){
		ran_num = left;
	}
	swap(array_list[right], array_list[ran_num]);
	return Partition(array_list, left, right);
}

void Randomized_Sort(int* arr, int p, int r) {
	if (p < r) {
		int q = Randomized_Partition(arr, p, r);
		Randomized_Sort(arr, p, q - 1);
		Randomized_Sort(arr, q+1,r);

	}
}
```

### Hoare
```cpp
int Hoare_partition(int* arr, int p, int r) {
	int x = arr[p];
	int i = p - 1;
	int j = r + 1;
	while (1) {
		while (arr[j] > x) j--;
		while (arr[i] < x)i++;
		if (i < j) {
			swap(arr[i], arr[j]);
			cnt++;
		}
		else return j;
	}
}

void Hoare_QSort(int* arr, int p, int r) {
	if (p < r) {
		int q = Hoare_partition(arr, p, r);
		Hoare_QSort(arr, p, q - 1);
		Hoare_QSort(arr, q + 1, r);

	}
}
```


## 堆排序

详情见[Heap_sort](https://github.com/lia112/GLRS-/blob/main/Sort/Heap_sort.cpp)


## 线性排序
### 计数排序
数组中任意n>0时
```cpp
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
```
### 基数排序
### 桶排序
感觉像hash
桶排序是一种比较简单的排序算法，排序速度极快，但是对空间要求很大，尤其是那种排序的数范围特别大的时候，可以理解为用空间换时间，所以桶排序更适于那种要排序的数处于比较小的范围的情况。
```cpp
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
```


