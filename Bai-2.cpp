#include <bits/stdc++.h>

using namespace std;


int adj[1000][1000];


int main() {

    ifstream file("Bai2input.txt"); // đọc file
    int n; 
    
    file >> n;
   
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            file  >> adj[i][j];
        }
    }
   
    file.close();


    vector<int> dinhTreo;
    vector<int> dinhCoLap;
    
    // đỉnh treo, cô lập
    for (int i = 0; i < n; ++i) {
        int bac = 0;
        for (int j = 0; j < n; ++j) {
            bac += adj[i][j];
            if (i == j && adj[i][j] != 0){
                bac += adj[i][j];
            }
        }

        if (bac == 0) dinhCoLap.push_back(i);
        else if (bac == 1) dinhTreo.push_back(i);
    }



    cout << "\nDinh treo: ";
    for (int v : dinhTreo) cout << v << " ";

    cout << "\nDinh co lap: ";
    for (int v : dinhCoLap) cout << v << " ";

  
    cout << "\nCap dinh co canh song song: "<< '\n' ;

    // cặp cạnh song song
    bool timThay = false;
    for (int i = 0; i < n ; ++i) {
        for (int j = i + 1; j < n; ++j) {   // tìm ở trên đường chéo chính
            if (adj[i][j] >= 2) {
                cout << i << " " << j << '\n';
                timThay = true;
            }
        }
    }     
   
    if(!timThay) cout << "\nKhong co cap dinh co canh song song.\n";

    return 0;
}
