#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdio>
using namespace std;

void signedRatio(vector<int> arr) 
{
    int countPositive = 0, countNegative = 0, countZero = 0;
    float arraySize = arr.size();

    for(int i = 0; i < arraySize; i++) {
        if(arr[i] < 0)
            countNegative++;
        else if(arr[i] == 0) 
            countZero++;
        else
            countPositive++;
    }

    std::cout << std::fixed << std::setprecision(6) 
                            << countPositive / arraySize << "\n" 
                            << countNegative     / arraySize << "\n" 
                            << countZero / arraySize << std::endl;
    
}

int main() {
    int n;
    cin >> n;
    vector<int> ar(n);

    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        ar[i] = temp;
    }

    signedRatio(ar); return 0;
}