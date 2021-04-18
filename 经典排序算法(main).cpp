#include"qgsort.h"

using namespace std;

int main()
{
	int choice = 0;
	int choice1 = 0;
	int n = 0; int x = 0, y = 0;
	int a[101];
	int temp[101];  // ����һ���������������ͬ��С�����顣
	int j = 0; int i = 0; int k = 0; int begin = a[0];
	int top = 0, low = 0, high, pivot;
	clock_t diff2, diff4, diff5, diff6, diff7, diff8, diff9, diff10, diff11;
	clock_t start2, start4, start5, start6, start7, start8, start9, start10, start11;

	ofstream outFile;

	while (true)
	{
		show_Menu1();
		cout << "����������ѡ��" << endl;
		cin >> choice1;

		switch (choice1)
		{
		case 0://�˳�ϵͳ
			exitSystem();
			break;
		case 1:	
			outFile.open("text1.txt");
			cout << "������������ֵ" << endl;
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
			cout << "��д���ļ���" << endl;
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
			cout << "����������ݳɹ�" << endl;
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
			cout << "����������ݳɹ�" << endl;
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
			cout << "����������ݳɹ�" << endl;
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
			cout << "����������ݳɹ�" << endl;
			break;
		case 6:
			goto end;
			break;
		default:
			cout << "�������" << endl;
			cout << "����������" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
end:
	cout << "���ڴ��ļ�......" << endl;
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
	cout << "�ѽ��ļ��е�������洢��������" << endl;

	while (true)
	{
		show_Menu();
		cout << "����������ѡ��" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0://�˳�ϵͳ
			exitSystem();
			break;
		case 1://�����ļ�
			//���ļ�
			outFile.open("test2.txt");
			for (i = 0; i < n; i++)
			{
				//д������
				outFile << a[i];
			}
			//�ر��ļ�
			outFile.close();
			cout << "�ļ�����ɹ�" << endl;
			break;
		case 2://���������㷨
			start2 = clock();
			for (i = 1; i < n; i++) {
				insertSort(a, i);
			}
			for (i = 0; i < n; i++) {
				cout << a[i] << " ";
			}
			cout << endl;
			diff2 = clock() - start2;
			cout << "�������õ�ʱ��Ϊ��" << diff2 << " ms" << endl;
			break;
		case 3://�鲢����
			cout << "�鲢��������ɣ���ϲ����飨����4��" << endl;
			break;
		case 4://�鲢���򣨺ϲ����飩
			start4 = clock();
			MergeArray(a, n, temp);
			for (i = 0; i < n; i++) {
				cout << a[i] << " ";
			}
			cout << endl;
			diff4 = clock() - start4;
			cout << "�������õ�ʱ��Ϊ��" << diff4 << " ms" << endl;
			break;
		case 5://�������򣨵ݹ�棩
			start5 = clock();
			QuickSort_Recursion(a, begin, n);
			for (i = 0; i < n; i++) {
				cout << a[i] << " ";
			}
			cout << endl;
			diff5 = clock() - start5;
			cout << "�������õ�ʱ��Ϊ��" << diff5 << " ms" << endl;
			break;
		case 6://�������򣨷ǵݹ�棩
			start6 = clock();
			high = n - 1;
			//��һ�ο�������
			pivot = QuickSort(a, 0, n - 1);

			//�Ӽ��߽���ջ
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

			//��ջ��ȡ���߽�������п�������
			while (top > 0)
			{
				low = temp[--top];
				high = temp[--top];
				//���ֵõ����ұ߽磬������ջ
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
			cout << "�������õ�ʱ��Ϊ��" << diff6 << " ms" << endl;
			break;
		case 7://�������������ţ�
			start7 = clock();
			Partition(a, begin, n);
			for (i = 0; i < n; i++) {
				cout << a[i] << " ";
			}
			cout << endl;
			diff7 = clock() - start7;
			cout << "�������õ�ʱ��Ϊ��" << diff7 << " ms" << endl;
			break;
		case 8://��������
			start8 = clock();
			CountSort(a, n, amax);
			for (i = 0; i < n; i++) {
				cout << a[i] << " ";
			}
			cout << endl;
			diff8 = clock() - start8;
			cout << "�������õ�ʱ��Ϊ��" << diff8 << " ms" << endl;
			break;
		case 9://������������
			start9 = clock();
			RadixCountSort(a, n);
			for (i = 0; i < n; i++) {
				cout << a[i] << " ";
			}
			cout << endl;
			diff9 = clock() - start9;
			cout << "�������õ�ʱ��Ϊ��" << diff9 << " ms" << endl;
			break;
		case 10://��ɫ����
			start10 = clock();
			ColorSort(a, n);
			for (i = 0; i < n; i++) {
				cout << a[i] << " ";
			}
			cout << endl;
			diff10 = clock() - start10;
			cout << "�������õ�ʱ��Ϊ��" << diff10 << " ms" << endl;
			break;
		case 11://��һ�������������ҵ���K��/С����
			start11 = clock();
			cout << "������Ҫ�ҵĵ�KС����" << endl;
			cin >> k;
			RadixCountSort(a, n);
			cout << "��Ҫ�ҵĵ�KС�����ǣ�" << a[k-1] << endl;
			diff11 = clock() - start11;
			cout << "�������õ�ʱ��Ϊ��" << diff11 << " ms" << endl;
			break;
		default:
			cout << "�������" << endl;
			cout << "����������" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	//ifstream fin("test.txt");
	//while (!fin.eof())//�ж��Ƿ��������
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