#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string elect_student(vector<string>& V){

  sort(V.begin(), V.end());

  int current_votes, votes = 0;
  string winner, current_student;

  for (string x: V){

    if (winner.empty()){
      winner = x;
      current_votes = 0;
      current_student = x;
    }

    if (x == current_student){
      current_votes++;
    }
    else{
      if (current_votes > votes){
        winner = current_student;
        votes = current_votes;
      }
      current_student = x;
      current_votes = 1;
    }
  }

  if (current_votes > votes) return current_student;

  return winner;
}

int main(){

  string s;
  vector<string> V;

  while (cin >> s){
    V.push_back(s);
  }

  cout << elect_student(V) << endl;

  return 0;
}
