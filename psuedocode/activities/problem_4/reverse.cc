#include <iostream>
#include <string>

using namespace std;

string reverse(string const& s){
  
  string rev_s = s;
  int n = s.length();

  for (int i = 0; i < n; i++){
    rev_s[i] = s[n - i - 1];
  }
  return rev_s;
}

int main(){
  string s;

  while(cin >> s){
    cout << reverse(s) << endl;
  }
  return 0;
}
