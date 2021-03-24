#include<iostream>
using namespace std;


//插入排序
void  Insertion_sort() {
    int len = sizeof(arr) / sizeof(arr[0]);
    for (int j = 1; j < len; j++) {
        int key = arr[j];
        int i = j - 1;
        while (i >= 0 && arr[i] > key) {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = key;
    }
}


//merge_sort
void Merge(int* a, int p, int q, int r)
{
    int n1 = q - p + 1;       //左部分的的元素个数
    int n2 = r - q;           //同上
    int i, j, k;
    int* L = new int[n1 + 1];
    int* R = new int[n2 + 1];
    for (i = 0; i < n1; i++)
        L[i] = a[p + i];
    for (j = 0; j < n2; j++)
        R[j] = a[q + j + 1];
    L[n1] = 11111111;
    R[n2] = 11111111;
    // 数组L从0~n1-1存放，第n1个存放int型所能表示的最大数，即认为正无穷，这是为了
    //处理合并时，比如当数组L中的n1个元素已经全部按顺序存进数组a中，只剩下数组R的
    //部分元素，这时因为R中剩下的元素全部小于11111111,则执行else语句，直接将剩下的
    //元素拷贝进a中。
    for (i = 0, j = 0, k = p; k <= r; k++)
    {
        if (L[i] <= R[j])
            a[k] = L[i++];
        else
            a[k] = R[j++];
    }

    delete[]L;
    delete[]R;
}

void merge_sort(int* a, int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        merge_sort(a, l, m);
        merge_sort(a, m + 1, r);
        Merge(a, l, m, r);
    }
}



int random_s(int l, int r) {
	unsigned seed = chrono::high_resolution_clock::now().time_since_epoch().count();
	mt19937 rand_generator(seed);
	uniform_int_distribution<int> dist(l, r);
	return dist(rand_generator);
}



int partition(int* arr, int p, int r) {
	int x = arr[r];
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (arr[j] <= x) {
			i++;
			swap(arr[i], arr[j]);
			cnt++;
		}
	}
	swap(arr[i + 1], arr[r]);
	cnt++;
	return i + 1;
}

void Quick_sort(int* arr, int p, int r) {
	if (p < r) {
		int q = partition(arr, p, r);
		Quick_sort(arr, p, q - 1);
		Quick_sort(arr, q + 1, r);
	}
}

//随机化快排
int Randomized_Partition(int* arr, int p, int r) {
	int i = random_s(p, r);
	swap(arr[r], arr[i]);
	cnt++;
	return partition(arr, p, r);
}

void Randomized_Sort(int* arr, int p, int r) {
	if (p < r) {
		int q = Randomized_Partition(arr, p, r);
		Randomized_Sort(arr, p, q - 1);
		Randomized_Sort(arr, q+1,r);

	}
}

//hoare
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

