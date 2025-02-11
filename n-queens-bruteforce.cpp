#include <iostream>
#include <vector>

using namespace std;

bool Valid(vector<int>& positions, int row) {
    for (int i = 0; i < row; i++) {
        if (positions[i] == positions[row] || 
            abs(positions[i] - positions[row]) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

void Solve(int n, int row, vector<int>& positions, int& solutions) {
    if (row == n) { 
        solutions++;
        return;
    }
    for (int col = 0; col < n; col++) {
        positions[row] = col; 
        if (Valid(positions, row)) { 
            Solve(n, row + 1, positions, solutions); 
        }
    }
}






int main()
{
    return 0;
}