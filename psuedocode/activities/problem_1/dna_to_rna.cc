#include <iostream>
#include <string>

using namespace std;

string dna_to_rna(string const& s){
  string ss = s;

  for (int i = 0; i < s.length(); i++){
    if (s[i] == 'T'){
      ss[i] = 'U';
    }
    else{
      ss[i] = s[i];
    }
  }
  return ss;
}


int main(){
  string s;

  while (cin >> s){
    cout << dna_to_rna(s) << endl;
  }
  return 0;
}
