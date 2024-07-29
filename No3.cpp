//問題:https://x.com/e869120/status/1377391097836544001/photo/2
/*
回答拝見済
//bool型を使わずに作る必要がある->stackで実装!
*/

#include <iostream>
#include <vector>
#define N_MAX 111111
using namespace std;
typedef long long llint;

llint e = -1;//最大値
llint node_e = -1;
vector <bool> do_search(N_MAX);




void dfs(llint v_start,llint v_goal , vector <vector <llint>> g , llint n , llint dis){
    do_search[v_start] = true;
    //cout << "(v_start,v_goal,dis) = " << v_start << "," << v_goal << "," <<dis << endl;
    if(v_start == v_goal){
        if(dis > e) {
            e = dis;//最大値更新
            node_e = v_goal;//ノードを更新
        }
        return;
    }
    
    for (int i = 0; i < g[v_start].size(); i++)
    {
        //cout << "(v_start,i,g[v_start][i],g[v_start].size())) = " << v_start << "," << i << "," << g[v_start][i] << "," << g[v_start].size() << endl;
        if(do_search[g[v_start][i]] == true){
            //cout << "continue" << endl;
            continue;
        }else{
            if(do_search[g[v_start][i]] == false){
                dis++;
                dfs(g[v_start][i],v_goal,g,n,dis);
            }
        }
    }
    return;
}

int main(void){
    llint n,v1,v2,v_mid;
    vector <vector <llint>> graph(N_MAX);

    cin >> n;

    for (llint i = 0; i < n-1; i++)
    {
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        do_search[v1] = false;
        graph[v2].push_back(v1);
        do_search[v2] = false;
    }

    for (llint i = 1; i <= n; i++)
    {
        dfs(v1,i,graph,n,0);
        //cout << "e = " << e <<endl;
        for (llint j = 0; j < n; j++)
        {
            do_search[j] = false;
        }
        
    }

    e = -1;//定一のみ初期化
    v_mid = node_e;
    cout  << "asdg" << endl;

    for (llint i = 1; i <= n; i++)
    {
        dfs(v_mid,i,graph,n,0);
        //cout << "e = " << e <<endl;
        for (llint j = 0; j < n; j++)
        {
            do_search[j] = false;
        }
        
    }

    cout << e + 1 << endl;

    return 0;
}