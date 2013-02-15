#include<iostream>  
#include<vector>  
#include<algorithm>  
#include<map>  
using namespace::std;  
class Solution {  
public:  
    long BKDRHash(string str)  
    {  
        int seed = 131;  
        long hash = 0;  
        for(int i = 0; i < str.size(); i++)  
        {  
            hash = hash * seed + str[i];  
        }  
        return hash;  
    }  
    vector<string> anagrams(vector<string> &strs) {  
        // Start typing your C/C++ solution below  
        // DO NOT write int main() function  
        vector<string> copy(strs);  
        vector<string> result;  
        map<long, vector<int> > mymap;  
        long key = 0;  
        for(size_t i = 0; i < strs.size(); i++)  
        {  
            sort(strs[i].begin(), strs[i].end());  
        }  
          
        for(size_t i = 0; i < strs.size(); i++)  
        {  
            //mymap[strs[i]].push_back(i);  
            mymap[RSHash(strs[i])].push_back(i);  
        }  
          
          
        for(size_t i = 0; i < strs.size(); i++)  
        {  
            if(mymap[RSHash(strs[i])].size() > 1)  
            while(mymap[RSHash(strs[i])].size() > 0)  
            {  
                result.push_back(copy[mymap[RSHash(strs[i])].back()]);  
                mymap[RSHash(strs[i])].pop_back();  
            }  
  
        }  
          
        return result;  
          
    }  
};  