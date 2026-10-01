#include "bits/stdc++.h"
#define ll long long
using namespace std;
 
void solve(int p,int s,int e){
    if(p==1){
        cout<<s<<" "<<e<<"\n";
        return;
    }
    solve(p-1,s,6-s-e);
    cout<<s<<" "<<e<<"\n";
    solve(p-1,6-s-e,e);
}
 
int main(){
    int N;
    cin>>N;
    cout<<(1<<N)-1<<endl;
    solve(N,1,3);
}