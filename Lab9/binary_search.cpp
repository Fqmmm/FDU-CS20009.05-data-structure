#include <bits/stdc++.h>
using namespace std;

int find(vector<int> arr, int begin, int end, int key)
{
    if (begin == end && arr[begin] != key) return -1;
    int mid = (begin + end) / 2;
    if (arr[mid] == key) return mid;
    else if (arr[mid] < key) return find(arr, mid + 1, end, key);
    else return find(arr, begin, mid, key);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int key;
    cin >> key;

    int idx = find(arr, 0, n - 1, key);

    // 看idx前面是否有arr[id]=key
    while (arr[idx - 1] == key)
    {
        idx--;
    }

    cout << idx;
    return 0;
}