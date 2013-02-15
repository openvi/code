#include<algorithms>
class Solution {
private: bool compare(int x, int y) {
    return x<y;
}
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        std::sort(num.begin(), num.end());
    	vector< vector<int> > ret;
        if (num.size() <=2) {
            return ret;
        }
		for (int i=0; i<num.size()-2; i++) {
			int start = i+1;
			int end = num.size()-1;
			if ((i>0) && (num[i]==num[i-1])) {
				continue;
			}
		    while ((start<end) && (start!=end)) {
				if (num[i]+num[start]+num[end] == 0) {
					vector<int> newv ;
					newv.push_back(num[i]);
					newv.push_back(num[start]);
					newv.push_back(num[end]);
					ret.push_back(newv);
					int endl = end;
					while (num[endl]==num[--end]){
					}
					int startl = start;
					while (num[startl]==num[++start]){
					}
				} else if (num[i]+num[start]+num[end] > 0) {
					int endl = end;
					while (num[endl]==num[--end]){
					}
				} else {
					int startl = start;
					while (num[startl]==num[++start]){
					}
				}
			}
		}
		return ret;
    }
};
