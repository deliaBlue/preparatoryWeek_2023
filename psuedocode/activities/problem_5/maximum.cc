#include <iostream>
#include <vector>

using namespace std;

int maximum(vector<int>& V){
  int m = V[0];

  for(int i = 1; i < V.size(); i++){
    if (m < V[i]){
      m = V[i];
    }
  }
  return m;
}

int main(){
 
  int x;
  vector<int> V;

  while (cin >> x) V.push_back(x);
  cout << maximum(V) << endl;

  return 0;
}
