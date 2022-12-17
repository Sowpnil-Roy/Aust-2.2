#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<vector<int>> v = {
        {INT_MAX, 20, 30, 10, 11},
        {15, INT_MAX, 16, 4, 2},
        {3, 5,  INT_MAX, 2, 4},
        {19, 6, 18, INT_MAX, 3},
        {16, 4, 7, 16, INT_MAX}
    };

    vector<vector<int>> s;

    s = v;



    for(int i = 0; i < v.size(); i++)
    {
        for(int j = 0; j < v[i].size(); j++)
        {
            cout << s[i][j];
        }
        cout << endl;
    }

}
