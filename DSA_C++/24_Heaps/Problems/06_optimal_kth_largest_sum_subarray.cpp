#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
  public:
    int kthLargest(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < arr.size(); i++) {
            int tempSum = 0;
            for (int j = i; j < arr.size(); j++) {
                tempSum += arr[j];

                if (pq.size() < k) {
                    pq.push(tempSum);
                } else if (pq.top() < tempSum) {
                    pq.pop();
                    pq.push(tempSum);
                }
            }
        }

        return pq.top();
    }
};