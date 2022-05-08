#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


vector<int> getPrefixSumArray(vector<int> arr, int n) {
    vector<int> prefixSumArr;
    prefixSumArr.push_back(0);
    int i;
    for (i=0; i<n; i++) {
        prefixSumArr.push_back(prefixSumArr.at(i) + arr.at(i));
    }
    return prefixSumArr;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n, t, i;
    vector<int> arr;
    cin >> n;
    for (i=0; i<n; i++) {
        int number;
        cin >> number;
        arr.push_back(number);
    }
    vector<int> prefixSumArr = getPrefixSumArray(arr, n);
    cin >> t;
    for (i=0; i<t; i++) {
        int l, r;
        cin >> l >> r;
        int answer = prefixSumArr.at(r) - prefixSumArr.at(l - 1);
        cout << answer << endl;
    }
    
    return 0;
}