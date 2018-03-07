#include <bits/stdc++.h>
using namespace std;
template <class T> int size(const T &x) { return x.size(); }
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it,c) for (__typeof((c).begin()) \
  it = (c).begin(); it != (c).end(); ++it)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
const int INF = ~(1<<31);

const double EPS = 1e-9;
const double pi = acos(-1);
typedef unsigned long long ull;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> T smod(T a, T b) {
  return (a % b + b) % b; }
// vim: cc=60 ts=2 sts=2 sw=2:

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<char> > ground(n, vector<char>(m, '.'));
    rep(i,0,n) {
        rep(j,0,m) {
            cin >> ground[i][j];
        }
    }
    int q;
    vvi biggest(n, vi(m));
    rep(i, 0, n){
        rep(j, 0, m){
            int s = 0;
            for(;i + s < n && j + s < m; ++s){
                bool good = true;
                rep(k, 0, s + 1){
                    if(ground[i + s][j + k] == '#' || ground[i + k][j + s] == '#'){
                        good = false;
                        break;
                    }
                }
                if(!good){
                    break;
                }
            }
            rep(k, 0, s){
                rep(l, 0, s){
                    biggest[i + k][j + l] = max(biggest[i + k][j + l], s);
                }
            }
        }
    }

    cin >> q;
    rep(i, 0, q){
        int a, b;
        cin >> a >> b;
        --a, --b;
        cout << biggest[a][b]*biggest[a][b] << endl;
    }
}