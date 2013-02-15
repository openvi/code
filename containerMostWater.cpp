class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int first = 0;
        int end = height.size()-1;
        int maxArea = (height.size()-1) * min(height[0], height[height.size()-1]);
        while (first<end) {
            if (height[first] < height[end]) {
                first++;
            } else if( height[first] > height[end]) {
                end--;
            } else {
               first++;
               end --;
            }
            
            int area = (end-first)* min(height[first], height[end]);
            if (area>maxArea) {
                maxArea = area;
            }
        }
        
        return maxArea;
    }
};