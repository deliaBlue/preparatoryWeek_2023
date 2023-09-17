#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

set<string> color_set(vector<string>& V){
  set<string> S;

  for (string i : V){
    if (i != "Blue"){
      S.insert(i);
    }
  }

  return S;
}

int main(){

  string s;
  vector <string> V;

  while(cin >> s) V.push_back(s);

  for (string i : color_set(V)){
    cout << i << endl;
  }

return 0;
}
