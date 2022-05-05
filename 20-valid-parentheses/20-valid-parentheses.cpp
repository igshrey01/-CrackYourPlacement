class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        int n = s.size();
        
        for(int i=0;i<n;i++){
            
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
                st.push(s[i]);
            else{
                
                if(st.empty())
                    return false;
                
                char topp = st.top();
                
                if((s[i]==')' && topp!='(') || (s[i]==']' && topp!='[') || (s[i]=='}' && topp!='{') )
                    return false;
                
                st.pop();
                
            }
            
        }
        
        if(st.empty())
            return true;
        return false;
        
    }
};