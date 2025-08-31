#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for (int n : nums) freq[n]++;   // count frequency

    // Convert map into vector of pairs (num, frequency)
    vector<pair<int,int>> vec(freq.begin(), freq.end());

    // Sort by frequency in descending order
    sort(vec.begin(), vec.end(), [](auto &a, auto &b) {
        return a.second > b.second;
    });

    // Take top k elements
    vector<int> res;
    for (int i = 0; i < k; i++) {
        res.push_back(vec[i].first);
    }
    return res;
    }
};