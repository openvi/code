class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector< vector<string> > list;
        vector<string> st0,st1,st2;
        st0.push_back("");
        st1.push_back("()");
        st2.push_back("()()");
        st2.push_back("(())");
        list.push_back(st0);
        list.push_back(st1);
        list.push_back(st2);
        for (int i=3;i<=n;i++) {
            vector<string> st;
            for (int j=0;j<i;j++) {
                stack<string> ss;
                ss.push("(");
                for (int k=0;k<list[j].size();k++)
                {
                    ss.push(list[j][k]);
                    ss.push(")");
                    for (int l=0;l<list[i-1-j].size();l++) {
                        ss.push(list[i-1-j][l]);
                        string sss;
                        stack<string> ssss(ss);
                        while (!ssss.empty()) {
                            string sst = ssss.top();
                            ssss.pop();
                            sss=sst+sss;
                        }
                        st.push_back(sss);
                        ss.pop();
                    }
                    ss.pop();
                    ss.pop();
                    
                }
                ss.pop();
                
                
            }
            list.push_back(st);
        }
        return list[n];
    }
};