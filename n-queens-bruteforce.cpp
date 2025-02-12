#include <iostream>
#include <vector>

using namespace std;

bool Valid(vector<int>& pos, int row) {
    for (int i = 0; i < row; i++) {
        if (pos[i] == pos[row] || 
            abs(pos[i] - pos[row]) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

void Solve(int n, int row, vector<int>& pos, int& s) {
    if (row == n) { 
        s++;
        return;
    }
    for (int col = 0; col < n; col++) {
        pos[row] = col; 
        if (Valid(pos, row)) { 
            Solve(n, row + 1, pos, s); 
        }
    }

    cout<<s;
}






int main()
{
    return 0;
}
