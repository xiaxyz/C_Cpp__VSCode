//两个字符串, 一个转换成另一个的最少操作数
#include <iostream>
#define N 255

using namespace std;

int res(string a, string b);

int main(void)
{
    string a, b;
    cin >> a >> b;
    cout << res(a, b);
    return 0;
}

int res(string a, string b)
{
    int dp[N][N], al = a.length(), bl = b.length();
    for (int i = 1; i <= al; i++)
        dp[0][i] += dp[0][i - 1] + 1;
    for (int i = 1; i <= bl; i++)
        dp[i][0] += dp[i - 1][0] + 1;
    for (int i = 1; i <= al; i++)
    {
        for (int j = 1; j <= bl; j++)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else 
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
        }
    }
    return dp[al][bl];
}