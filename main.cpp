// spoj, ada and indexing!
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,st,end) for(int i=st;i<=end;i++)
typedef long long ll;

const int alphabetCount = 26;
class TrieNode{
public:
    TrieNode(){
        for(int i=0;i<alphabetCount;i++){
            nodes[i]= nullptr;
        }
        isWord=0;
    }
    TrieNode* nodes[alphabetCount]{};
    int isWord;
    ~TrieNode(){
        for(auto i : nodes){
            delete i;
        }
    }
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
            if(cur->nodes[c - 'a'] == nullptr){
                cur->nodes[c - 'a'] = new TrieNode;
            }
            cur = cur->nodes[c - 'a'];
            cur->isWord++;
        }
    }
    int search( string& s){
        TrieNode* cur = root;
        for(auto c : s){
            if(cur->nodes[c - 'a'] == nullptr){
                return 0;
            }
            cur = cur->nodes[c - 'a'];
        }
        //cur is pointing to the nodes of the last character
        return cur->isWord;
    }
    ~Trie(){
        delete root;
    }
};
int main() {
    int n,k;cin >>n>>k;
    string s;
    Trie *trie = new Trie;
    FOR(i,1,n){
        cin >>s;
        trie->insert(s);
    }
    int ans;
    FOR(i,1,k){
        cin >>s;
        ans = trie->search(s);
        cout <<ans<<"\n";
    }
    return 0;
}



