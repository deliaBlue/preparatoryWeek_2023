# include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<string>> fill_rows(vector<string> &L){
    int n = L.size();
    vector<string> row1, row2, row3;

    for (int i = 0; i < n; i += 3) {
        row1.push_back(L[i]);
        if (i + 1 < n) {
            row2.push_back(L[i + 1]);
            if (i + 2 < n) {
                row3.push_back(L[i + 2]);
            }
        }
    }

    vector<vector<string>> outlist = {row1, row2, row3};
    return outlist;
}

int main(){

    string name;
    vector<string> L;

    while (getline(cin, name) && !name.empty()) {
            L.push_back(name);
        }
    vector<vector<string>> rows = fill_rows(L);

    //printing output
    for (int i = 0 ; i < rows.size(); ++i) {
        cout << "Row"<< i +1 << ": ";
        for (int name = 0; name < rows[i].size(); ++name){
            if (name > 0) {
                cout << ", ";
            }
            cout << rows[i][name];
        }
        cout << endl;
    }
}