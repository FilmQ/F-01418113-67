#include <iostream>
#include <vector>
using namespace std;

int diagonalDifference(vector<vector<int>> arr) {
    int sumMatrixTrace = 0, sumMatrixTraceReversed = 0;

    for(int i = 0, j = arr.size() - 1; i < arr.size(); i++, j--) {
        sumMatrixTrace += arr[i][i];
        sumMatrixTraceReversed += arr[j][i];
    }
    return abs(sumMatrixTrace - sumMatrixTraceReversed);
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> arr(n);

    for (int i = 0; i < n; ++i) {
        arr[i].resize(n);
        for (int j = 0; j < n; ++j) {
            int temp;
            cin >> temp;
            arr[i][j] = temp;
        }
    }

    int result = diagonalDifference(arr);
    cout << result << endl;
    return 0;
}