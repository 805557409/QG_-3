#include"qgsort.h"

using namespace std;

void show_Menu()
{
	cout << "****************************************************************************" << endl;
	cout << "*****************0.退出系统*************************************************" << endl;
	cout << "*****************1.存入文件*************************************************" << endl;
	cout << "*****************2.插入排序算法*********************************************" << endl;
	cout << "*****************3.归并排序*************************************************" << endl;
	cout << "*****************4.归并排序（合并数组）*************************************" << endl;
	cout << "*****************5.快速排序（递归版）***************************************" << endl;
	cout << "*****************6.快速排序（非递归版）*************************************" << endl;
	cout << "*****************7.快速排序（枢轴存放）*************************************" << endl;
	cout << "*****************8.计数排序*************************************************" << endl;
	cout << "*****************9.基数计数排序*********************************************" << endl;
	cout << "*****************10.颜色排序************************************************" << endl;
	cout << "*****************11.在一个无序序列中找到第K大/小的数************************" << endl;
	cout << "*****************12.显示各个序列的时间（用户使用过的）**********************" << endl;
	cout << "****************************************************************************" << endl;
	cout << endl;
}

void show_Menu1() {
	cout << "****************************************************************************" << endl;
	cout << "*****************0.退出系统*************************************************" << endl;
	cout << "*****************1.用户自己输入数值*****************************************" << endl;
	cout << "*****************2.随机生成0-10000的数**************************************" << endl;
	cout << "*****************3.随机生成10000-50000的数**********************************" << endl;
	cout << "*****************4.随机生成50000-200000的数*********************************" << endl;
	cout << "*****************5.随机生成0-2的数(颜色排序)********************************" << endl;
	cout << "*****************6.进入下一步***********************************************" << endl;
	cout << "****************************************************************************" << endl;
	cout << endl;
}

void exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

//插入排序算法
void insertSort(int* a, int n) {
	int key = a[n];
	int i = n;
	while (a[i - 1] > key) {
		a[i] = a[i - 1];//将大于key的值向前排
		i--;
		if (i == 0) {
			break;
		}
	}
	a[i] = key;
}

//归并排序
// 采用递归的方法实现归并排序函数。
// a-待排序数组的首地址，temp-用于排序的临时数组的首地址
// begin-排序区间第一个元素的位置，n-排序区间最后一个元素的位置。
void MergeSort(int* a, int* temp, int begin, int n)
{
	// 如果begin>=n，表示该区间的元素少于两个，递归终止。
	if (begin >= n) return;

	int mid = begin + (n - begin) / 2;  // 计算排序区间中间的位置。

	int ibegin1 = begin, in1 = mid;  // 区间左边元素的第一和最后一个元素的位置。
	int ibegin2 = mid + 1, in2 = n;  // 区间右边元素的第一和最后一个元素的位置。

	MergeSort(a, temp, ibegin1, in1);   // 对区间左边元素递归排序。
	MergeSort(a, temp, ibegin2, in2);   // 对区间右边元素递归排序。

	int ii = begin; // 已排序数组temp的计数器。

	// 把区间左右两边数列合并到已排序数组temp中。
	while (ibegin1 <= in1 && ibegin2 <= in2)
		temp[ii++] = a[ibegin1] < a[ibegin2] ? a[ibegin1++] : a[ibegin2++];

	// 把左边数列其它的元素追加到已排序数组。
	while (ibegin1 <= in1) temp[ii++] = a[ibegin1++];

	// 把右边数列其它的元素追加到已排序数组。
	while (ibegin2 <= in2) temp[ii++] = a[ibegin2++];

	// 把已排序数组temp中的元素复制到a中。
	memcpy(a + begin, temp + begin, (n - begin + 1) * sizeof(int));
}

//归并排序（合并数组）
// a为待排序的数组的地址，n为数组的长度。
void MergeArray(int* a, int n, int* temp)
{
	if (n < 2) return;  // 小于两个元素不需要排序。

	//vector<int> temp(n);// 分配一个与待排序数组相同大小的数组。

	MergeSort(a, temp, 0, n - 1);  // 调用递归函数进行排序。
}

//快速排序（递归版）
void QuickSort_Recursion(int* a, int begin, int n)
	{
		if (n < 2) return;  // 数组的元素小于2个就不用排序了。

		begin = a[0];  // 选取最左边的数作为中心轴。
		int ileft = 0;      // 左下标。
		int iright = n - 1; // 右下标。
		int imoving = 2;    // 当前应该移动的下标，1-左下标；2-右下标。

		while (ileft < iright)
		{
			if (imoving == 2) // 移动右下标的情况。
			{
				// 如果右下标位置元素的值大于等于中心轴，继续移动右下标。
				if (a[iright] >= begin) { iright--; continue; }

				// 如果右下标位置元素的值小于中心轴，把它填到左下标的坑中。
				a[ileft] = a[iright];
				ileft++;    // 左下标向右移动。
				imoving = 1;  // 下次循环将移动左下标。
				continue;
			}

			if (imoving == 1) // 移动左下标的情况。
			{
				// 如果左下标位置元素的值小等于中心轴，继续移动左下标。
				if (a[ileft] <= begin) { ileft++; continue; }

				// 如果左下标位置元素的值大于中心轴，把它填到右下标的坑中。
				a[iright] = a[ileft];
				iright--;   // 右下标向左移动。
				imoving = 2;  // 下次循环将移动右下标。
				continue;
			}
		}

		// 如果循环结束，左右下标重合，把中心轴的值填进去。
		a[ileft] = begin;

		QuickSort_Recursion(a, begin, ileft);					  // 对中心轴左边的序列进行排序。
		QuickSort_Recursion(a + ileft + 1, begin, n - ileft - 1); // 对中心轴右边的序列进行排序。
	}

//快速排序（非递归版）
int QuickSort(int* a, int begin, int end)
{
	int pivot, i = begin, j = end;

	pivot = a[i];

	while (i < j)
	{

		while (j > i && a[j] >= pivot)j--;
		if (j > i)
			swap(a + j, a + i);
		else
			break;
		while (i < j && a[i] <= pivot)i++;
		if (i < j)
			swap(a + j, a + i);
		else
			break;
	}

	return i;
}


void swap(int* a, int* b)
{
	if (a == b)
		return;
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}


//快速排序（枢轴存放）
void Partition(int* a, int begin, int n) {
	if (n < 2) return;  // 数组的元素小于2个就不用排序了。

	begin = a[0];  // 选取最左边的数作为中心轴。
	int ileft = 0;      // 左下标。
	int iright = n - 1; // 右下标。
	int imoving = 2;    // 当前应该移动的下标，1-左下标；2-右下标。

	while (ileft < iright)
	{
		if (imoving == 2) // 移动右下标的情况。
		{
			// 如果右下标位置元素的值大于等于中心轴，继续移动右下标。
			if (a[iright] >= begin) { iright--; continue; }

			// 如果右下标位置元素的值小于中心轴，把它填到左下标的坑中。
			a[ileft] = a[iright];
			ileft++;    // 左下标向右移动。
			imoving = 1;  // 下次循环将移动左下标。
			continue;
		}

		if (imoving == 1) // 移动左下标的情况。
		{
			// 如果左下标位置元素的值小等于中心轴，继续移动左下标。
			if (a[ileft] <= begin) { ileft++; continue; }

			// 如果左下标位置元素的值大于中心轴，把它填到右下标的坑中。
			a[iright] = a[ileft];
			iright--;   // 右下标向左移动。
			imoving = 2;  // 下次循环将移动右下标。
			continue;
		}
	}

	// 如果循环结束，左右下标重合，把中心轴的值填进去。
	a[ileft] = begin;

	Partition(a, begin, ileft);					    // 对中心轴左边的序列进行排序。
	Partition(a + ileft + 1, begin, n - ileft - 1); // 对中心轴右边的序列进行排序。
}


//计数排序
void CountSort(int* a, int n, int(*amax)(int* a, int n)) {
	if (n < 2) return;

	int imax = amax(a, n);  // 获取待排序数组的最大元素的值。

	int len = imax + 1;;
	vector<int> atmp(len); // 临时数组的大小为imax+1。

	for (int i = 0; i < len; i++) {
		atmp[i] = 0;
	}

	int ii, jj, kk;

	// 临时数组计数。
	for (ii = 0; ii < n; ii++) atmp[a[ii]]++;

	// 把临时数组计数的内容填充到a中。
	ii = 0;
	for (jj = 0; jj < imax + 1; jj++)
	{
		for (kk = 0; kk < atmp[jj]; kk++) a[ii++] = jj;
	}
}

// 对数组arr按指数位进行排序。
// arr-待排序的数组，len-数组arr的长度。
// exp-排序指数，exp=1：按个位排序；exp=10：按十位排序；......
void _radixsort(int* a, int n, int exp)
{
	int ii;
	int result[101];			// 存放从桶中收集后数据的临时数组。
	int buckets[10] = { 0 };   // 初始化10个桶。

	// 遍历arr，将数据出现的次数存储在buckets中。
	for (ii = 0; ii < n; ii++)
		buckets[(a[ii] / exp) % 10]++;

	// 调整buckets各元素的值，调整后的值就是arr中元素在result中的位置。
	for (ii = 1; ii < 10; ii++)
		buckets[ii] = buckets[ii] + buckets[ii - 1];

	// 将arr中的元素填充到result中。
	for (ii = n - 1; ii >= 0; ii--)
	{
		int iexp = (a[ii] / exp) % 10;
		result[buckets[iexp] - 1] = a[ii];
		buckets[iexp]--;
	}

	// 将排序好的数组result复制到数组arr中。
	memcpy(a, result, n * sizeof(int));
}

//基数计数排序
// 基数排序主函数，arr-待排序的数组，len-数组arr的长度。
void RadixCountSort(int* a, int n)
{
	int imax = arrmax(a, n);    // 获取数组arr中的最大值。

	int iexp;    // 排序指数，iexp=1：按个位排序；iexp=10：按十位排序；......

	// 从个位开始，对数组arr按指数位进行排序。
	for (iexp = 1; imax / iexp > 0; iexp = iexp * 10)
	{
		_radixsort(a, n, iexp);
		/*int yy; printf("exp=%-5d  ", iexp); for (yy = 0; yy < n; yy++) printf("%2d ", a[yy]); printf("\n");*/
	}
}

//int sortArr[n][n];
//int front[n], rear[n];
//initArr(front, n); initArr(rear, n);
//int cursor = 1;
//for (int i = 0; i < max; i++) {
//	for (int j = 0; j < n; j++) {
//		int r = (arr【j】 / cursor) % 10;
//		cout << r << endl;					//计算基数
//		rear[r] = (rear[r] + 1) % n;        //进队列 
//		sortArr[r][rear[r]] = arr[j];       //基数确定行标 
//	}
//
//	int k = 0;
//	for (int j = 0; j < n; j++) {
//		while (rear[j] != front[j]) {       //队列不空 
//			front[j] = (front[j] + 1) % n;  //出队 
//			arr[k] = sortArr[j]】[front[j]];
//			cout << arr[k] << " ";
//			k++;
//		}
//	}
//	cout << endl;
//
//	//初始化数据
//	cursor *= 10;                           //除数进位 
//}
//}​

//颜色排序
void ColorSort(int* a, int n) {
	int i = 0, j = 0, k = 0;
	int num[3] = { 0 };

	for (i = 0; i < n; i++) {
		if (a[i] >= 0 && a[i] <= 2) {
			cout << "您输入的数据不都是0，1或2。" << endl;
			cout << "请重新输入" << endl;
			return;
		}
		if (a[i] == 0) {
			num[0]++;
		}
		if (a[i] == 1) {
			num[1]++;
		}
		if (a[i] == 2) {
			num[2]++;
		}
	}

	for (i = 0; i < num[0]; i++) {
		a[i] = 0;
	}
	for (j = i; j < num[0] + num[1]; j++) {
		a[j] = 1;
	}
	for (k = j; k < num[0] + num[1] + num[2]; k++) {
		a[k] = 2;
	}
}

//在一个无序序列中找到第K大/小的数


// 获取待排序数组的最大元素的值。
int amax(int* a, int n)
{
	int ii = 0;
	int imax = 0;

	for (ii = 0; ii < n; ii++) if (imax < a[ii]) imax = a[ii];

	return imax;
}

// 获取数组arr中最大值，arr-待排序的数组，len-数组arr的长度。
int arrmax(int* a, int n)
{
	int ii, imax;

	imax = a[0];

	for (ii = 1; ii < n; ii++)
		if (a[ii] > imax) imax = a[ii];

	return imax;
}