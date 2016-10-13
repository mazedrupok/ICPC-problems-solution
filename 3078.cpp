#include <bits/stdc++.h>
using namespace std;
#define LL long long
string s;
int len;
int dp[100005][2];
int func (int i, bool k) {
    if (dp[i][k] != -1) return dp[i][k];
    if (i >= len-1) return dp[i][k] = 1;

    if (s[i] == '0') return dp[i][k] = 0;

    int a = 0, b = 0;
    if (s[i+1] != '0') a = func (i+1, 0);
    if (s[i] == '1' || (s[i] == '2' && s[i+1] < '7')) {
        if (s[i+2] != '0') b = func (i+2, 1);
    }
    return dp[i][k] = a+b;
}

int main ()
{
    while(cin >> s) {
        if (s[0] == '0') break;
        len = s.length();
//        int test = 1;
//        for (int i = 0; i < len-1; i++) {
//            if (s[i] == '0' && s[i+1] == '0') {test = 0; break;}
//            if (s[i] > '2' && s[i+1] == '0') {test = 0; break;}
//        }
//        if (test == 0) {cout << "0\n"; continue;}
        for (int i = 0; i <= len; i++) dp[i][0] = -1 , dp[i][1] = -1;
        cout << func (0, 0) << endl;
    }


    return 0;
}
