#include<bits/stdc++.h>

using namespace std;



int main()
{
    int val = 1;
    int n = 5;
    vector<vector<int> > m(n, vector<int>(n));

    m[0][0] = val;
    for(int i = 1; i < n; i++)
    {
        for(int j = i; j >= 0; j--)
        {
            m[i][j] = pow(m[0][0] + i, 2);
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(m[i][j] != 0)
                cout << m[i][j] << "\t";
        }

        cout << endl;
    }

}
