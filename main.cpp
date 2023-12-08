#include <bits/stdc++.h>

using namespace std;

#define FOR(i,st,end) for(int i=st;i<=end;i++)
typedef long long ll;
 // spoj phone list
const int alphabetCount = 10;
class TrieNode{
public:
    TrieNode(){
        for(int i=0;i<alphabetCount;i++){
            children[i]= nullptr;
        }
        isWord=false;
    }
    TrieNode* children[alphabetCount]{};
    bool isWord;
};
class Trie{
private: TrieNode* root;
public:
    Trie(){
        root = new TrieNode;
    }
    void insert(const string& s){
        TrieNode* cur = root;
        for(auto c : s){
            if(cur->children[c-'0']== nullptr){
                cur->children[c-'0'] = new TrieNode;
            }
            cur = cur->children[c-'0'];
        }
        cur->isWord = true;
    }
    bool searchTrie(const string& s){
        TrieNode* cur = root;
        for(int i=0;i<s.size()-1;i++){
            if(cur->children[s[i]-'0']->isWord) return false;
            cur = cur->children[s[i]-'0'];
        }
        return true;
    }
};
int main() {
    int t,n;
    string s;
    cin >>t;
    while(t--){
        Trie *trie = new Trie();
        cin >>n;
        stack<string> st;
        FOR(i,1,n){
            cin >> s;
            trie->insert(s);
            st.push(s);
        }
        bool res = false;
        while(!st.empty()){
            s=st.top();
            st.pop();
            if(!trie->searchTrie(s)){
                cout << "NO\n";
                res = true;
                break;
            }

        }
        if(!res)cout <<"YES\n";
    }
    return 0;
}



