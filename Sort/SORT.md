# 排序算法-GLRS 2-8章
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

## 堆排序

## 线性排序
### 计数排序
### 基数排序
### 桶排序


