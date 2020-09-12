#include<bits/stdc++.h>
using namespace std;

const int alpha = 26, key = 10;
int T[alpha] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9};

struct Trie_node {
   int count;
   bool isEnd;
   string wyraz;
   Trie_node *W[key];
   Trie_node() {
      count = 0;
      isEnd = false;
      for(int i = 0; i < key; i++)
         W[i] = NULL;
   }
};

Trie_node* root = new Trie_node();

void Insert(Trie_node* node, string s)
{
   Trie_node *now = node;
   for(int i = 0; i < (int)s.size(); i++)
   {
      char z = s[i];
      Trie_node *dalej = now->W[T[z-'a']];
      if(!dalej)
      {
         dalej = new Trie_node();
         now->W[T[z-'a']] = dalej;
      }
      now = dalej;
      now->count++;
   }
   now->isEnd = true;
   now->wyraz = s;
}

Trie_node* Query( Trie_node* node, string s)
{
   Trie_node* now = node;
   for(int i = 0; i < (int)s.size(); i++)
   {
      if(now == nullptr)   return now;
      char z = s[i];
      Trie_node *dalej = now->W[z-'0'];
      now = dalej;
   }
   return now;
}

string Find( Trie_node* node)
{
   string K = node->wyraz;
   for(int i = 2; i <key; i++)
      if(node->W[i] != nullptr)
         K = Find( node->W[i]);
   return K;
}

void Result( string s)
{
   Trie_node* x = Query(root, s);
   if (x == nullptr)
      cout << "NIE\n";
   else if (x->count > 1) cout << x->count << "\n";
      else cout << Find(x) << "\n";
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0);          cout.tie(0);

   string W;
   int n, q;   cin >> n >> q;
   while(n--)  {
      cin >> W;   Insert(root, W);
   }
   while(q--)  {
      cin >> W;   Result(W);
   }
}
