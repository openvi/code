nclude<algorithms>
#include<cmath>
#define INT32_MAX 0x7fffffff 
class Solution {
private: bool compare(int x, int y) {
    return x<y;
}
public:
    int threeSumClosest(vector<int> &num, int target) {
        std::sort(num.begin(), num.end());
        vector< vector<int> > ret;
		int mostClose = INT32_MAX;
		int realsum = INT32_MAX;
        if (num.size() <=2) {
            return 0;
        }
		for (int i=0; i<num.size()-2; i++) {
			int start = i+1;
			int end = num.size()-1;
			if ((i>0) && (num[i]==num[i-1])) {
				continue;
			}
		    while ((start<end) && (start!=end)) {
			   if (num[i]+num[start]+num[end] >= target) {
				if (abs(num[i]+num[start]+num[end] - target) < mostClose) {
					mostClose = abs(num[i]+num[start]+num[end] - target);
					realsum = num[i]+num[start]+num[end];
				}
				end--;
			} else if 	 (num[i]+num[start]+num[end] < target) {
					if (abs(num[i]+num[start]+num[end] - target) < mostClose) {
						mostClose = abs(num[i]+num[start]+num[end] - target);
							realsum = num[i]+num[start]+num[end];

					}
					start++;
				}
		  }
		}
		return realsum;
    }
};

