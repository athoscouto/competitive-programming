#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n;
    long long int D;
    long long int d = 40000000000000;
    cin >> n;

    long long int p[n][2];

    for (int i = 0; i < n; i++)
    {
        cin >> p[i][0] >> p[i][1];
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            D = (p[i][0] - p[j][0])*(p[i][0] - p[j][0]) + (p[i][1] - p[j][1])*(p[i][1] - p[j][1]);
            if (D < d)
                d = D;
        }
    }
    float a = d;
    cout << setprecision(3) << fixed <<  sqrt(a) << endl;

    return 0;
}
