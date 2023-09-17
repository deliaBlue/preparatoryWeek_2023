#include <iostream>
#include <set>
#include <string>

using namespace std;

string find_coding_region(string const& s){

  int i = 0;
  set<string> S = {"TAA", "TAG", "TGA"};

  while (i +2 <= s.length()){
      if (s.substr(i, 3) == "ATG"){
        int j = i + 3;
        while (j + 2 <= s.length()){
          if (S.find(s.substr(j, 3)) != S.end()){
            return s.substr(i + 3, j -(i + 3));
          }
          j += 3;
        }
      }
      i++;
  }
  return "";
}

int main(){
  string s;
  while (cin >> s){
    cout << find_coding_region(s) << endl;
   }
  return 0;
}
