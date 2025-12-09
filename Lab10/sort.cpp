#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500005;
int arr[MAXN];
int temp[MAXN]; // 临时数组

// 合并两个有序数组
void merge(int left, int mid, int right)
{
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    while (j <= right)
    {
        temp[k++] = arr[j++];
    }

    // 拷贝回原数组
    for (int p = left; p <= right; p++)
    {
        arr[p] = temp[p];
    }
}

// 归并排序
void mergeSort(int left, int right)
{
    if (left >= right)
        return;

    int mid = (left + right) / 2;
    mergeSort(left, mid);
    mergeSort(mid + 1, right);
    merge(left, mid, right);
}

int main()
{
    ios::sync_with_stdio(false);    // 快速 I/O
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    mergeSort(0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}