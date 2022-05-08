#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int getTotalMoves(int n) {
    int moveCounter = 0;
    while ((n % 2) == 0) {
        moveCounter += 1;
        n /= 2;
    }
    return moveCounter;
}


vector<int> solve(int n, int m) {
    int allowedMoves = getTotalMoves(n);
    vector<int> answers;
    int i;
    for (i=1; i<=m; i++) {
        int moves = getTotalMoves(i);
        if (moves < allowedMoves)
            answers.push_back(i);
        else {}
    }    
    return answers;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, m;
    cin >> n >> m;
    vector<int> answers = solve(n, m);
    cout << answers.size() << endl;
    if (answers.size() > 0) {
        for(int i : answers)
            cout << i << " ";
    }
  
    return 0;
}