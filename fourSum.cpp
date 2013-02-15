#include<algorithms>
class Solution
{
private:
    bool compare(int x, int y)
    {
        return x<y;
    }
public:
    vector<vector<int> > fourSum(vector<int> &num, int target)
    {
        std::sort(num.begin(), num.end());
        vector< vector<int> > ret;
        long longsum;
        if (num.size() <=3)
        {
            return ret;
        }
        for (int j=0; j<num.size()-3; j++)
        {
            if ((j>0) && (num[j]==num[j-1]))
            {
                continue;
            }
            for (int i=j+1; i<num.size()-2; i++)
            {
                int start = i+1;
                int end = num.size()-1;
                if ((i>j+1) && (num[i]==num[i-1]))
                {
                    continue;
                }
                while ((start<end) && (start!=end))
                {
                    longsum = num[j]+num[i]+num[start]+num[end];
                    if (longsum == target)
                    {
                        vector<int> newv ;
                        newv.push_back(num[j]);
                        newv.push_back(num[i]);
                        newv.push_back(num[start]);
                        newv.push_back(num[end]);
                        ret.push_back(newv);
                        int endl = end;
                        while ((num[endl]==num[end]) && (end>=start))
                        {
                            end--;
                        }
                        int startl = start;
                        while ((num[startl]==num[start])&&(end>=start))
                        {
                            start++;
                        }
                    }
                    else if ((longsum> target))
                    {
                        int endl = end;
                        while ((num[endl]==num[end]) &&(start<=end))
                        {
                            end--;
                        }
                    }
                    else
                    {
                        int startl = start;
                        while ((num[startl]==num[start])&&(start<=end))
                        {
                            start++;
                        }
                    }
                }
            }
        }
        return ret;
    }
};
 
 