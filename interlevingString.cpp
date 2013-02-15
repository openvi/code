class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function   
        
        int len1 = s1.size();
        int len2 = s2.size();
        if (len1 ==0 ) {
            return (s2.compare(s3)==0);
        }
        
        if (len2 ==0) {
            return (s1.compare(s3)==0);
        }
        
        if ((len1+len2 )!=s3.size())
        {
            return false;
        }
        bool a[1000][1000];
        
        a[-1][0] = true;
        a[0][-1] = true;
        a[0][0] =true;
        
        for (int i=0;i<=s1.size(); i++) {
            for (int j=0; j<=s2.size();j++) {
                if (i+j ==0) {
                    continue;
                }
                a[i][j] = false;
                if (j>0) {
                    a[i][j] = ((a[i][j-1]) && (s2[s2.size()-j]==s3[s3.size() -i -j]))? true:a[i][j];
                }
                if (i>0) {
                    a[i][j] = ((a[i-1][j]) && (s1[s1.size()-i] == s3[s3.size() - i -j]))? true:a[i][j];
                }
            }
        }
        return a[s1.size()][s2.size()];
    }
};