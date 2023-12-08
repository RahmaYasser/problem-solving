#include <bits/stdc++.h>

using namespace std;

#define FOR(i,st,end) for(int i=st;i<=end;i++)
typedef long long ll;

const int alphabetCount = 26;
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
            if(cur->children[c-'a']== nullptr){
                cur->children[c-'a'] = new TrieNode;
            }
            cur = cur->children[c-'a'];
        }
        cur->isWord = true;
    }
    bool search(const string& s){
        TrieNode* cur = root;
        for(auto c : s){
            if(cur->children[c-'a']== nullptr){
                return false;
            }
            cur = cur->children[c-'a'];
        }
        return cur->isWord;
    }
};
int main() {
    Trie *trie = new Trie();

    return 0;
}



