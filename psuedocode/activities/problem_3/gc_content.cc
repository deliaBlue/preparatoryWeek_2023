#include <iomanip>
#include <iostream>
#include <set>
#include <string>

using namespace std;

double gc_content(string const& s){
  
  int gc = 0;
  set<char> S = {'G','C'};
  
  for(int i = 0; i <= s.length(); i++){
    if (S.find(s[i]) != S.end()){
      gc ++;
    }
  }
  return gc*100.0 /s.length();
}

int main(){

  string s;

  while (cin >> s){

    cout << setprecision(3) << gc_content(s) << '%' << endl;
  }

return 0;
}

