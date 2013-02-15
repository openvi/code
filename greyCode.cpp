class Solution {
public:
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
        if (n==0) {
            ret.push_back(0);
            return ret;
        }
        if (n==1) {
            ret.push_back(0);
            ret.push_back(1);
            return ret;
        }
        ret.push_back(0);
        ret.push_back(1);
        ret.push_back(3);
        ret.push_back(2);
        int i = 4;
        while (n>=3) {
            int len = ret.size();
            for (int j=len-1;j>=0;j--) {
                ret.push_back(i+ret[j]);
            }
            i*=2;
            n--;
        }
        return ret;
    }
};