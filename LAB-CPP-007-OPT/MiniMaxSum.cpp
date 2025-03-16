#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void miniMaxSum(vector<int> arr, long *minSum, long &maxSum) 
{
    long long getMin = 0, getMax = 0, sumNoMin = 0, sumNoMax = 0;

    getMin = *std::min_element(arr.begin(), arr.end());
    getMax = *std::max_element(arr.begin(), arr.end());

    bool flag = 0;
    for( long i : arr ) {
        if(i == getMin && flag == 0) {
            flag = 1;
            continue;
        }

        sumNoMin += i;
    }

    flag = 0;
    for( long i : arr ) {
        if(i == getMax && flag == 0) {
            flag = 1;
            continue;
        }
        sumNoMax += i;
    }

    maxSum = sumNoMin;
    *minSum = sumNoMax;
}

int main()
{
    int n = 5;
    long min, max;
    vector<int> ar;

    for (int i = 0; i < n; ++i) {
        long temp;
        cin >> temp;
        ar.push_back(temp);
    }

    miniMaxSum(ar, &min, max);
    cout << min << " " << max << endl;
    return 0;
}