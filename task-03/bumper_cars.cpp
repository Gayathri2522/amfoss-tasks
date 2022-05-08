#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solve(vector<int> positions, vector<int> directions, int x, int n) {
    int i;
    int maximumDistanceToEnd = 0;
    for (i=0; i<x; i++) {
        int distance;
        if (directions.at(i) == 1) 
            distance = (n + 1) - positions.at(i);
        else
            distance = positions.at(i) - 0;
        
        if (distance > maximumDistanceToEnd) 
            maximumDistanceToEnd = distance;
        else {}
    }
    return maximumDistanceToEnd;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int x, n, i;
    vector<int> positions;
    vector<int> directions;
    cin >> x >> n;
    for (i=0; i<x; i++) {
        int position;
        cin >> position;
        positions.push_back(position);
    }
    for (i=0; i<x; i++) {
        int direction;
        cin >> direction;
        directions.push_back(direction);
    }
    cout << solve(positions, directions, x, n);
    return 0;
}