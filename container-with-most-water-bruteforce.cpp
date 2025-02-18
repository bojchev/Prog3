#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vektorche = {1,8,6,2,5,4,8,3,7};
    
    int n = 0;
    for(int i =0; i < vektorche.size(); i++)
    {
        for(int j = 0; j < vektorche.size(); j++)
        {
            n = max(n, min(vektorche[i], vektorche[j])*abs(j-i) );
        }
    }

    cout<<n;
    
    return 0; 
}

