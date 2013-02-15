class Solution {

vector< vector<int> > ret;
void findCombin(vector<int> &candidates, vector<int> stack, int target, int first) {
    if ((target<0) || (first > (candidates.size()-1))) {
        return;
    }
    if (target==0) {
        vector<int> copy(stack);
        ret.push_back(copy);
        return;
    }
    
    stack.push_back(candidates[first]);
    findCombin(candidates, stack, target - candidates[first], first);
    stack.pop_back();
    findCombin(candidates, stack, target, first+1);
        
}
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> stack;
        ret.clear();
        sort(candidates.begin(), candidates.end());
        findCombin(candidates, stack, target, 0);
        return ret;
    }
};