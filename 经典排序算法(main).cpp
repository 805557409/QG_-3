#include"qgsort.h"

using namespace std;

int main()
{
	int choice = 0;
	int choice1 = 0;
	int n = 0; int x = 0, y = 0;
	int a[101];
	int temp[101];  // 分配一个与待排序数组相同大小的数组。
	int j = 0; int i = 0; int k = 0; int begin = a[0];
	int top = 0, low = 0, high, pivot;
	clock_t diff2, diff4, diff5, diff6, diff7, diff8, diff9, diff10, diff11;
	clock_t start2, start4, start5, start6, start7, start8, start9, start10, start11;

	ofstream outFile;

	while (true)
	{
		show_Menu1();
		cout << "请输入您的选择" << endl;
		cin >> choice1;

		switch (choice1)
		{
		case 0://退出系统
			exitSystem();
			break;
		case 1:	
			outFile.open("text1.txt");
			cout << "请输入您的数值" << endl;
			cin >> j;
			while (j) {
				a[n] = j;
				n++;
				cin >> j;
			}
			for (i = 0; i < n; i++) {
				outFile << a[i] << "\t";
			}
			outFile.close();
			cout << "已写入文件中" << endl;
			break;
		case 2:
			for (i = 0; i < 100; i++) {
				a[i] = random(10000);
			}
			n = 100;
			outFile.open("text1.txt");
			for (i = 0; i < n; i++) {
				outFile << a[i];
			}
			cout << "生成随机数据成功" << endl;
			break;
		case 3:
			x = 10000, y = 50000;
			for (i = 0; i < 100; i++) {
				a[i] = rand() % (x - y + 1) + x;
			}
			n = 100;
			outFile.open("text1.txt");
			for (i = 0; i < n; i++) {
				outFile << a[i];
			}
			cout << "生成随机数据成功" << endl;
			break;
		case 4:
			x = 50000, y = 200000;
			for (i = 0; i < 100; i++) {
				a[i] = rand() % (x - y + 1) + x;
			}
			n = 100;
			outFile.open("text1.txt");
			for (i = 0; i < n; i++) {
				outFile << a[i];
			}
			cout << "生成随机数据成功" << endl;
			break;
		case 5:
			x = 0, y = 4;
			for (i = 0; i < 100; i++) {
				a[i] = rand() % (x - y + 1) + x;
			}
			n = 100;
			outFile.open("text1.txt");
			for (i = 0; i < n; i++) {
				outFile << a[i];
			}
			cout << "生成随机数据成功" << endl;
			break;
		case 6:
			goto end;
			break;
		default:
			cout << "输入错误" << endl;
			cout << "请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
end:
	cout << "正在打开文件......" << endl;
	ifstream fileinput;
	fileinput.open("text1.txt");
	for (i = 0; i < n; i++)
	{
		fileinput >> a[i];
	}
	fileinput.close();
	for (i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	cout << "已将文件中的随机数存储在数组中" << endl;

	while (true)
	{
		show_Menu();
		cout << "请输入您的选择" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0://退出系统
			exitSystem();
			break;
		case 1://存入文件
			//打开文件
			outFile.open("test2.txt");
			for (i = 0; i < n; i++)
			{
				//写入数据
				outFile << a[i];
			}
			//关闭文件
			outFile.close();
			cout << "文件保存成功" << endl;
			break;
		case 2://插入排序算法
			start2 = clock();
			for (i = 1; i < n; i++) {
				insertSort(a, i);
			}
			for (i = 0; i < n; i++) {
				cout << a[i] << " ";
			}
			cout << endl;
			diff2 = clock() - start2;
			cout << "排序所用的时间为：" << diff2 << " ms" << endl;
			break;
		case 3://归并排序
			cout << "归并排序已完成，请合并数组（输入4）" << endl;
			break;
		case 4://归并排序（合并数组）
			start4 = clock();
			MergeArray(a, n, temp);
			for (i = 0; i < n; i++) {
				cout << a[i] << " ";
			}
			cout << endl;
			diff4 = clock() - start4;
			cout << "排序所用的时间为：" << diff4 << " ms" << endl;
			break;
		case 5://快速排序（递归版）
			start5 = clock();
			QuickSort_Recursion(a, begin, n);
			for (i = 0; i < n; i++) {
				cout << a[i] << " ";
			}
			cout << endl;
			diff5 = clock() - start5;
			cout << "排序所用的时间为：" << diff5 << " ms" << endl;
			break;
		case 6://快速排序（非递归版）
			start6 = clock();
			high = n - 1;
			//第一次快速排序
			pivot = QuickSort(a, 0, n - 1);

			//子集边界入栈
			if (pivot - 1 > low)
			{
				temp[top++] = pivot - 1;
				temp[top++] = low;
			}

			if (pivot + 1 < high)
			{
				temp[top++] = high;
				temp[top++] = pivot + 1;
			}

			//从栈中取出边界继续进行快速排序
			while (top > 0)
			{
				low = temp[--top];
				high = temp[--top];
				//复又得到左右边界，继续入栈
				pivot = QuickSort(a, low, high);

				if (pivot - 1 > low)
				{
					temp[top++] = pivot - 1;
					temp[top++] = low;
				}

				if (pivot + 1 < high)
				{
					temp[top++] = high;
					temp[top++] = pivot + 1;
				}
			}

			for (i = 0; i < n; i++) {
				cout << a[i] << " ";
			}
			cout << endl;
			diff6 = clock() - start6;
			cout << "排序所用的时间为：" << diff6 << " ms" << endl;
			break;
		case 7://快速排序（枢轴存放）
			start7 = clock();
			Partition(a, begin, n);
			for (i = 0; i < n; i++) {
				cout << a[i] << " ";
			}
			cout << endl;
			diff7 = clock() - start7;
			cout << "排序所用的时间为：" << diff7 << " ms" << endl;
			break;
		case 8://计数排序
			start8 = clock();
			CountSort(a, n, amax);
			for (i = 0; i < n; i++) {
				cout << a[i] << " ";
			}
			cout << endl;
			diff8 = clock() - start8;
			cout << "排序所用的时间为：" << diff8 << " ms" << endl;
			break;
		case 9://基数计数排序
			start9 = clock();
			RadixCountSort(a, n);
			for (i = 0; i < n; i++) {
				cout << a[i] << " ";
			}
			cout << endl;
			diff9 = clock() - start9;
			cout << "排序所用的时间为：" << diff9 << " ms" << endl;
			break;
		case 10://颜色排序
			start10 = clock();
			ColorSort(a, n);
			for (i = 0; i < n; i++) {
				cout << a[i] << " ";
			}
			cout << endl;
			diff10 = clock() - start10;
			cout << "排序所用的时间为：" << diff10 << " ms" << endl;
			break;
		case 11://在一个无序序列中找到第K大/小的数
			start11 = clock();
			cout << "输入您要找的第K小的数" << endl;
			cin >> k;
			RadixCountSort(a, n);
			cout << "您要找的第K小的数是：" << a[k-1] << endl;
			diff11 = clock() - start11;
			cout << "排序所用的时间为：" << diff11 << " ms" << endl;
			break;
		default:
			cout << "输入错误" << endl;
			cout << "请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	//ifstream fin("test.txt");
	//while (!fin.eof())//判断是否输入结束
	//{
	//	fin >> a[i];
	//	i++;
	//}

	//for (i = 0; i < n; i++) {
	//	cout << a[i] << endl;
	//}

	system("pause");
	return 0;

}