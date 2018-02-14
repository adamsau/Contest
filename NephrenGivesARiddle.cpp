#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

ll f[100005];

string s0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
string s1 = "What are you doing while sending \"";
string s2 = "\"? Are you busy? Will you send \"";
string s3 = "\"?";

ll q, n, k, MAX;

char check(ll n, ll k) {
	if(k > f[n] && n < MAX) return '.';
	else if(n == 0) return s0[k - 1];
	else if(k <= 34) return s1[k - 1];
	else if(n >= MAX) return check(n - 1, k - 34);
	else if(k <= (34 + f[n - 1])) return check(n - 1, k - 34);
	else if(k <= (34 + f[n - 1] + 32)) return s2[k - (34 + f[n - 1]) - 1];
	else if(k <= (34 + f[n - 1] + 32 + f[n - 1])) return check(n - 1, k - (34 + f[n - 1] + 32));
	else return s3[k - (34 + f[n - 1] + 32 + f[n - 1]) - 1];
}

int main() {
	f[0] = 75;
	f[1] = 218;
	
	for(ll i = 2; i <= 100000 && f[i - 1] <= 1e18; ++i, MAX = i) f[i] = 34 + f[i - 1] + 32 + f[i - 1] + 2;
	
	scanf("%lld", &q);
	
	for(int i = 0; i < q; ++i) {
		scanf("%lld %lld", &n, &k);
		char c = check(n, k);
		
		printf("%c", c);
	}

	return 0;
}
