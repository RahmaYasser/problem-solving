#include <iostream>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define FOR( i, S, E ) for(int i=(int)S ; i<=(int)E ; i++ )

/*
 * MAZE codeforces 377 A
 * 1. get the number of nodes of the connected component that we want to keep
 * 2. mark them with different character (e,g. *)
 * 3. mark the rest to be x
 * 4. remark * with .
 *
 *
*/
int dirR[4]={1,-1,0,0};
int dirC[4]={0,0,1,-1};

// if child can be visited, return true
bool valid(int r, int c,int R,int C, vector<vector<char>> &grid){
    return r>=0 && r<R && c>=0 && c<C && grid[r][c]=='.';
}

// count has to be passed by reference, backtracking counts for each visited node, not for each visited path
void dfs(int x,int y,int n,int m, vector<vector<char>> &grid,int &count){
    if(count==0)return;
    count--;
    grid[x][y] = '*';
    int childX,childY;
    FOR(i,0,3){
        childX=x+dirR[i];
        childY=y+dirC[i];
        if(valid(childX,childY,n,m,grid)){
            dfs(childX,childY,n,m,grid,count);
        }
    }
}

int main(){
    int n,m,k;
    cin >>n>>m>>k;
    vector<vector<char>> grid;
    // init
    FOR(i,0,n-1){
        vector<char> v(m);
        grid.push_back(v);
    }
    int x,y,count=0; // starting point
    char c;
    FOR(i,0,n-1){
        FOR(j,0,m-1){
            cin >>c;
            if(c=='.'){
                count++;
                x=i;y=j;
            }
            grid[i][j]=c;
        }
    }
    count=count-k; // number of nodes to keep (mark with *)
    dfs(x,y,n,m,grid,count);

    // mark the remaining to 'X'
    FOR(i,0,n-1){
        FOR(j,0,m-1){
            if(grid[i][j]=='.'){
                grid[i][j]='X';
            }
        }
    }
    // remark * to be .
    FOR(i,0,n-1){
        FOR(j,0,m-1){
            if(grid[i][j]=='*'){
                grid[i][j]='.';
            }
            cout<<grid[i][j];
        }
        cout <<"\n";
    }
    return 0;

}