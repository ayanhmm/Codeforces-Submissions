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

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;

#define pb push_back
#define allof(x) (x).begin(), (x).end()
#define loop(a,b) for(int i = a; i<b; i++)
#define haan cout << "YES" << endl
#define nahn cout << "NO" << endl
#define ppc  __builtin_popcountll
#define msb  63-__builtin_clzll

typedef long long lol;
typedef vector<char> v1d;
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
    cout<<endl;
    return;
}

v1d getvec(int size){
    v1d ans;
    while(size--){
        char temp; cin>>temp; ans.push_back(temp);
    }
    return ans;
}
v2d getvec(int rows, int columns){
    v2d ans;
    for(int i = 0; i<rows; i++) ans.push_back(getvec(columns));
    return ans;
}

v1d sieve(lol n){
    vector<bool> arr(n+1, 1); 
    v1d primes; 
    for(lol i=2;i<=n;i++) if(arr[i]) {
                                        primes.emplace_back(i); 
                                        for(lol j=2*i;j<=n;j+=i) arr[j]=0;
                                    } 
    return primes;}

#pragma endregion

int n,m;
pair<int,int> clamp(int x, int y){
    if(x < 0) x = 0;
    if(x > n-1) x = n-1;
    if(y < 0) y = 0;
    if(y > m-1) y=  m-1;
    return {x, y};

}

// ---------------------------------------------------------------------------------------------
void runtestcases(){
    int k; cin>>n>>m>>k;

    v2d nums = getvec(n, m);

    k--;

    int total = 0;

    print(nums);

    queue<pair<int, int>> q;
    vector<vector<lol>> yo(n, vector<lol>(m, 0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(nums[i][j] == '.'){
                q.push({i, j});
            }
            int i2 = max(0, i-1);
            int j2 = max(0, j-1);

            yo[i][j] = yo[i2][j] + yo[i][j2];
            if(nums[i][j] == 'g'){
                total++;
                yo[i][j]++;
            }
        }
    }

    int ans = n*m;

    while(!q.empty()){
        auto [x, y] = q.front(); q.pop();
        if(nums[x][y] != '.') continue;

        pair<int,int> p1 = clamp(x-k, y-k);
        int x1,y1;
        x1 = p1.first;
        y1 = p1.second;
        pair<int,int> p2 = clamp(x-k, y-k);
        int x2,y2;
        x2 = p2.first;
        y2 = p2.second;

        int g = yo[x2][y2] - yo[x1-1][y2] - yo[x2][y1-1] + yo[x1-1][y1-1];

        ans = min(ans, g);


    }

    cout<<total - ans<<endl;



    





    return;
}
// ----------------------------------------------------------------------------------------------

#pragma region mainfunction
int main() {
    fastio();
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