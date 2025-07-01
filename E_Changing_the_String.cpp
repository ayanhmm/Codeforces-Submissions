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
    int n, m;
    cin>>n>>m;

    string nums;
    cin>>nums;

    for (char &c : nums) {
        c = tolower(c);
    }

    // minh bees;
    // minh cees;

    int ba=0,ca=0,bc=0,cb=0,bca = 0, cba =0;
    while(m--){
        char x,y; cin>>x>>y;
        tolower(x);
        tolower(y);
        if(x == 'a') continue;
        if(x == 'b' && y == 'a') {ba++; if(cb) cba++;}
        else if(x == 'c' && y == 'a') {ca++; if(bc) bca++;}
        else if(x == 'b' && y == 'c') {bc++; }
        else if(x == 'c' && y == 'b') {cb++;}
    }
    
    for(int i = 0; i < n; ++i){
        if(nums[i] == 'a') continue;
        else if(nums[i] == 'b'){
            if(ba){nums[i] = 'a'; ba--;}
            else if(bc && ca && bca){nums[i] = 'a'; bc--; ca--; bca--;} 
        }
        else if(nums[i] == 'c'){
            if(ca){nums[i] = 'a'; ca--;}
            else if(cb && ba && cba){nums[i] = 'a'; cb--; ba--;cba--;}
            else if(cb){nums[i] = 'b'; cb--;}

        }
        // cout<<nums<<endl;

    }




    cout<<nums<<endl;



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