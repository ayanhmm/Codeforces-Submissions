#pragma region HelperFunctions
#include<bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define RESETCOL   "\033[0m"
#define BOLD    "\033[1m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"

#define debug(x) cerr<<RED << #x << " = " << x << endl << RESETCOL
#define showtc(x) cerr<<endl <<YELLOW <<  #x << " " << x << ": "<< RESETCOL
#else
#define debug(x)
#define showtc(x)
#endif

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

#define pb push_back
#define allof(x) (x).begin(), (x).end()
#define loop(a,b) for(int i = a; i<b; i++)
#define haan cout << "YES" << endl
#define nahn cout << "NO" << endl


typedef long long lol;
typedef vector<lol> v1d;
typedef vector<v1d> v2d;
typedef vector<v2d> v3d;
typedef priority_queue<lol, v1d, greater<lol>> minh; 
typedef priority_queue<lol> maxh;

void print(v1d nums){
    for(int i = 0; i<nums.size(); i++) cout<<nums[i]<<" ";
    cout<<"\n";
    return;
}
void print(v2d nums){
    for(int i=0; i<nums.size(); i++) print(nums[i]);
    return;
}

v1d getvec(int size){
    vector<lol> ans;
    while(size--){
        lol temp; cin>>temp; ans.push_back(temp);
    }
    return ans;
}
v2d getvec(int rows, int columns){
    v2d ans;
    for(int i = 0; i<rows; i++) ans.push_back(getvec(columns));
    return ans;
}

#pragma endregion

// ---------------------------------------------------------------------------------------------
void runtestcases(){
    int n,k;

    cin >> n >> k;

    v2d a;
    loop(0,k){
        v1d toadd;

        cout<<"? "<<i+1<<endl; cout.flush();
        int temp;
        cin>>temp;
        toadd.push_back(temp);

        cout<<"? "<<n-k+i+1<<endl; cout.flush();
        cin>>temp;
        toadd.push_back(temp);

        a.push_back(toadd);
    }

    // print(a);

    if(n%k == 0){
        loop(0,k){
            if(a[i][0] != a[i][1]) break;
            if(i == k-1){cout<<"! "<<-1<<endl ; cout.flush();  return;}
        }
    }

    debug(n);

    int rem = 0;
    while(rem <k && a[rem][0] == a[rem][1]) rem++;
    debug(rem);

    if(rem == k) rem = 0;

    int l = 0;
    int h = n/k;

    while(l < h){
        debug(l); debug(h); 
        int mid = (l +(h-l)/2);
        cout<<"? "<<rem + k*mid + 1<<endl; cout.flush();
        int m; cin>>m;
        
        if(a[rem][0] == m) l = mid;
        else {h = mid;}

        if(l == h-1 || l == h-2) break;
    }

    loop(0,2*k){
        cout<<"? "<< (l*k) + i + 1<<endl; cout.flush();
        int temp;
        cin>>temp;

        if(i<k && temp != a[i][0]){cout<<"! "<<(l*k) + i<<" "<<n - ((l*k) + i)<< endl;cout.flush(); return;}
        if(i>=k && temp != a[i-k][0]){cout<<"! "<<(l*k) + i<<" "<<n - ((l*k) + i)<< endl;cout.flush(); return;}

    }
    cout<<"! "<<-1<<endl; cout.flush();
    // bs on rem
    

    return;
}
// ----------------------------------------------------------------------------------------------

#pragma region mainfunction
int main() {
    int testcases = 1; 
    cin>>testcases;
    int tc = 1;

    while(testcases--){
        showtc(tc); tc++; 
        runtestcases();
    }

    return 0;
}
#pragma endregion