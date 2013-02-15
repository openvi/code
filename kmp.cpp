class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len1 = strlen(haystack);
        int len2 = strlen(needle);
        
        int p[200000];
        int j = -1;
        p[0]=-1;
        if (!*needle) {
            return haystack;
        }
        for (int i=1; i<len2;i++) {
            if (j>=0 && (needle[i]!= needle[j+1])) {
                j = p[j];
            }
            if (needle[i]==needle[j+1]) {
                j++;
            }
            p[i] = j;
        }
        
        j = -1;
        for (int i=0; i <len1; i++) {
            if (j>=0 && (haystack[i]!=needle[j+1])) {
                j = p[j];
            }
            if (haystack[i] == needle[j+1]) {
                j++;
            }
            if (j==len2-1) {
                return &haystack[i-j];
            }
        }
        return 0;
    }
};