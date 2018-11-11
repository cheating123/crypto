
Program 11: Implement Mix Column and Inverse Mix Column operations on S-AES with previous matrix as key.
#include<bits/stdc++.h>
#define N 2
using namespace std;
string MOD;
string dp[N][N], idp[N][N], C[N][N];
string stuffZero(string s, int n){
  while (s.length() < n) s = '0' + s;
  return s;
}
int binaryToInt(string s){
  int ans = 0;
  reverse(s.begin(), s.end());
  for (int i = 0; i < s.length(); i++)
    ans += (1 << i) * (s[i] - '0');
  return ans;
}
string intToBinary(int num){
  string ans = "";
  while (num){
    char c = num % 2;
    ans += (c + '0');
    num /= 2;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}
int len(int n){
  int m = 0;
  while (n){
    n = n / 2;
    m++;
  }
  return m;
}
string divide(string m, string MOD){
  int mod = binaryToInt(MOD), n = binaryToInt(m);
  while (len(n) >= len(mod)) {
    n = n ^ (mod << (len(n) - len(mod)));
  }
  return intToBinary(n);
}
string add(string s, string p) {
  int n = binaryToInt(s), m = binaryToInt(p);
  return divide(intToBinary(n ^ m), MOD);
}
string mul(string s, string p){
  int n = binaryToInt(s), m = binaryToInt(p), ans = 0;
  for (int i = 0;
    (1 << i) <= n; i++) {
    if (n & (1 << i))
      ans = ans ^ (m << i);
  }
  return divide(intToBinary(ans), MOD);
}
void matrixMul(string A[N][N], string B[N][N]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      C[i][j] = "0";
      for (int k = 0; k < N; k++)
        C[i][j] = add(C[i][j], mul(A[i][k], B[k][j]));
    }
  }
}
int main() {
  int t, c;
  string s, p;
  MOD = "10011";
  cout << "\n** S-AES Encryption **\nEnter the matrix\n";
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      cin >> dp[i][j];
  string det = add(mul(dp[0][0], dp[1][1]), mul(dp[0][1], dp[1][0]));
  idp[0][0] = divide(dp[1][1], det);
  idp[0][1] = divide(dp[1][0], det);
  idp[1][0] = divide(dp[0][1], det);
  idp[1][1] = divide(dp[0][0], det);
  string A[N][N] = {
    {"0110","1111"},
    {"0110","1011"}
  };
  matrixMul(A, dp);
  cout << "\nMIX COLUMN: \n";
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++)
      cout << stuffZero(C[i][j], 2 * N) << " ";
    cout << endl;
  }
  cout << endl;
  matrixMul(A, idp);
  cout << "\nINVERSE MIX COLUMN: \n";
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++)
      cout << stuffZero(C[i][j], 2 * N) << " ";
    cout << endl; }
  cout << endl;
  return 0;
}