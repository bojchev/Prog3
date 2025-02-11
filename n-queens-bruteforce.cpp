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




int main()
{
    return 0;
}