#include "stdafx.h"
#include<iostream>;

using namespace std;

const int nmax = 1000;

void Merg(int arr[], int begin, int end)
{
	int i = begin,
		t = 0,
		mid = begin + (end - begin) / 2,
		j = mid + 1,
		d[nmax];


	while (i <= mid && j <= end) {

		if (arr[i] <= arr[j]) {
			d[t] = arr[i]; i++;
		}
		else {
			d[t] = arr[j]; 
			j++;
		}
		t++;
	}

	while (i <= mid) {
		d[t] = arr[i]; i++; t++;

	}

	while (j <= end) {
		d[t] = arr[j]; j++; t++;
	}

	for (i = 0; i < t; i++)
		arr[begin + i] = d[i];
}

void MergSort(int *arr, int left, int right)
{
	int temp;
	if (left < right)
		if (right - left == 1) {
			if (arr[right] < arr[left]) {
				temp = arr[left];
				arr[left] = arr[right];
				arr[right] = temp;
			}
		}
		else {
			MergSort(arr, left, left + (right - left) / 2);
			MergSort(arr, left + (right - left) / 2 + 1, right);
			Merg(arr, left, right);
		}

}

void input(int *m, int &n)
{

	cout << "Enter length: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int elem = 0;
		cout << "Enter element " << i + 1 << endl;
		cin >> elem;
		m[i] = elem;
	}

}
void print(int *m, int n)
{
	for (int i = 0; i< n; i++)
		cout << m[i] << " ";
	cout << " \n";

}
int main()
{
	int n, a[nmax];
	input(a, n);
	cout << " Your array : \n";
	print(a, n);
	MergSort(a, 0, n - 1);
	cout << " New array(sorted) : \n";
	print(a, n);
	system("pause");

}
