#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxval(vector<int> subarr, int k)
{
    int max = subarr.at(0);
    int i;
    for (i = 0; i < k; i++)
    {
        if (i < subarr.size() && subarr.at(i) > max)
        {
            max = subarr.at(i);
        }
    }
    return max;
}

void subarray(vector<int> arr, int n, int k)
{
    int sum = 0;
    int i, j;
    vector<int> subarr;
    while (!arr.empty())
    {
        if (subarr.size() == k)
        {
            vector<int>::iterator itr = subarr.begin();
            subarr.erase(itr);
            subarr.push_back(arr.back());
            arr.pop_back();
        }
        else if (subarr.size() == 0)
        {
            for (j = 0; j < k; j++)
            {
                subarr.push_back(arr.back());
                arr.pop_back();
            }
        }
        sum += maxval(subarr, k);
    }
    cout << sum;
}

int main()
{
    int i, n, k, a;
    cin >> n >> k;
    vector<int> arr;
    for (i = 0; i < n; i++)
    {
        cin >> a;
        arr.push_back(a);
    }
    subarray(arr, n, k);
    return 0;
}