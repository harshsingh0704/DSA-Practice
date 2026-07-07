class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    int n = pushed.size();
    int m = popped.size();
    stack<int>st;
   
    int r =0;
   for(int i =0; i<n ; i++){

        st.push(pushed[i]);
    
    while(!st.empty()&&st.top()==popped[r]){
        st.pop();
        r++;

    }
   
   }
   return st.empty();
    }
};