#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Orange{
    int i;
    int j;
    Orange(){}
    Orange(int i,int j):i(i),j(j){}
};

class Solution {
public:
    bool WillBad(vector<vector<int>>& grid, int &i, int &j, int &n, int &m){
        if(j-1>=0)if(grid[i][j-1]==2)return 1;
        if(j+1<m)if(grid[i][j+1]==2)return 1;
        if(i-1>=0)if(grid[i-1][j]==2)return 1;
        if(i+1<n)if(grid[i+1][j]==2)return 1;
        return 0;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.size()==0)return 0;
        int n=grid.size();
        int m=grid[0].size();
        queue<Orange> Q,bad;

        for(int i=0;i<n;++i)
        for(int j=0;j<m;++j){
            if(grid[i][j]==1){
                Q.push(Orange(i,j));
            }
        }
        int nowL=Q.size();
        int lastL=-1,min=0;
        while(lastL!=nowL){
            lastL=nowL;
            for(int i=0;i<nowL;++i){
                Orange T = Q.front();
                Q.pop();
                if(WillBad(grid,T.i,T.j,n,m))
                    bad.push(T);
                else Q.push(T);
            }
            while(!bad.empty()){
                grid[bad.front().i][bad.front().j]=2;
                bad.pop();
            }
            ++min;
            nowL=Q.size();
        }
        if(Q.empty())return min-1;
        else return -1;
    }
};

int main(){
    
    vector<vector<int>> nums = {{1,2}};
    
    Solution T;
    int ans = T.orangesRotting(nums);
    
    printf("%d\n",ans);
    getchar();
    return 0;
}