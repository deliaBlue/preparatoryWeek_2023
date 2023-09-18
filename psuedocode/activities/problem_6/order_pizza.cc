#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<string, int> order_pizza(vector<string>& V){
  
  map<string, int> M;

  for (string i : V){
    if (M[i] == 0){
      M[i] = 1;
    }
    else{
      M[i]++;
    }
  }
  return M;
}

int main(){

  vector <string> V;
  string s;

  while (cin >> s) V.push_back(s);

  map<string, int> M = order_pizza(V);

  for (const auto& i:M){
    cout << i.first << ": " << i.second << endl;
  }
  return 0;
}
