#include <iostream>
using namespace std;
int min (int a, int b, int c) {
   return (a < b) ? ((a < c) ? a : c ) : ((b < c) ? b : c );
}
int main ()
{
   int r, c, res;
   while (cin >> r >> c) {
      if (!r && !c) break;
      int ara[r][c], tem[r][c];
      for (int i = 0; i < r; i++) {
         for (int j = 0; j < c; j++) {
            cin >> ara[i][j];
         }
      }
      res = 0;
      for (int i = 0; i < r; i++) {
         for (int j = 0; j < c; j++) {
            if (i == 0 || j == 0) tem[i][j] = ara[i][j];
            else if (ara[i][j] == 1) tem[i][j] = min (tem[i][j-1], tem[i-1][j], tem[i-1][j-1]) + 1;
            else tem[i][j] = 0;
            res = max (res, tem[i][j]);
         }
      }
      cout << res << endl;
   }
   return 0;
}
