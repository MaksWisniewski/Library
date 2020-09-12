#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>T;

const int BITS = 50;

class Trie_node{
	public:
		Trie_node* left;
		Trie_node* right;
};

void Insert(ll n, Trie_node* node){
	Trie_node* current = node;
	for(int i = BITS; i >=0; i--)	{
		ll b = (1LL<<i)&n;

		if(b == 0)
		{
			if(!current->left)
				current->left = new Trie_node();
			current = current->left;
		}
		else
		{
			if(!current->right)
				current->right = new Trie_node();
			current = current->right;
		}
	}
}

ll Find(int n, Trie_node* node)
{
	ll R = -1;
	for(int k = 0; k < n; k++)
	{
		ll A = T[k];
		ll currR = 0;
		Trie_node* current = node;
		for(int i = BITS; i >= 0; i--)	{
			ll b = (1LL<<i)&A;

			if(b==0)
			{
				if(current->right)
				{
					current = current->right;
					currR += (1LL<<i);
				}
			       	else
					current = current->left;
			}
			else
			{
				if(current->left)
				{
					current = current->left;
					currR += (1LL<<i);
				}
				else
					current = current->right;
			}
		}
		R = max(R, currR);
	}
	return R;
}

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(0);				cout.tie(0);

	Trie_node* root = new Trie_node();

	int q;	cin >> q;
	
	for(int i = 0; i < q; i++) {
		ll x;	cin >> x;	Insert(x, root);	T.push_back(x);
	}
	cout << Find(q, root) << "\n";
}
