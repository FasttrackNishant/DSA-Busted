#include <iostream>
using namespace std;

vector<int> mergeKArrays(vector<vector<int>> &arr, int K) {
    vector<int> result;
    
    for (int i = 0; i < K; i++) {
        result.insert(result.end(), arr[i].begin(), arr[i].end());
    }

    sort(result.begin(), result.end());
    return result;
}

int main() {

    
    
    return 0;
}