class Solution {
public:

 bool solve(int node , int col ,vector<vector<int>>& graph,int color[]){
    color[node]=col;
    for (auto it:graph[node]){
        if(color[it]==-1){
            if(solve(it, !col,graph, color)==false ) return false;
        }
        else if(color[it]==col){
            return false ;
        }
    
    }
    return true;
 }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
       int color[n];
       for(int i =0; i<n;i++) color[i]=-1;
     for (int i =0; i<n ; i++){
    if(color[i] == -1){
        if(!solve(i , 0 , graph, color))
        {
            return false ;
        }
    }
}
    
       return true ; 
    }
};
       