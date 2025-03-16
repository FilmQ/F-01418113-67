#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int birthdayCakeCandles(vector<int> candles) 
{
    // nothing to see here folks
    return std::count(candles.begin(), candles.end(), *std::max_element(candles.begin(), candles.end()));
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

    int result = birthdayCakeCandles(ar);
    cout << result << endl;
    return 0;
}