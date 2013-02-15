struct node {
    int index;
    int start;
    int v;
};
node t;
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       stack<node> st;
       node t;
       if (height.size() == 0) {
           return 0;
       }
       int max = -1;
       t.index = 0;
       t.start = 0;
       t.v = height[0];
       max = t.v;
       st.push(t);
       for (int i=1;i<height.size();i++) {
           if(height[i]>st.top().v) {
               node tt;
               tt.start=i;
               tt.index=i;
               tt.v=height[i];
               st.push(tt);
           } else if( height[i] == st.top().v) {
               node tt;
               tt.start = st.top().start;
               tt.v = height[i];
               tt.index = i;
               st.push(tt);
           } else {
               node lastPop;
               while(st.size()>0 && height[i]<st.top().v) {
                   lastPop = st.top();
                   st.pop();
                   int temp = lastPop.v * (i-lastPop.index + lastPop.index - lastPop.start);
                   if (temp > max) {
                       max = temp;
                   }
                   
               }
               if (st.size() ==0) {
                   node tt;
                   tt.index = i;
                   tt.start = 0;
                   tt.v = height[i];
                   st.push(tt);
               } else {
                   node tt;
                   tt.index = i;
                   tt.start = (st.top().v == height[i])? st.top().start:lastPop.start;
                   tt.v = height[i];
                   st.push(tt);
                   
               }
               
               
           }
       }
       if (st.size()>0) {
            int i = st.top().index;
            while (st.size()>0) {
                int temp = st.top().v * (st.top().index - st.top().start + i - st.top().index +1);
                if (temp > max) {
                    max = temp;
                } 
                st.pop();
            }

       }
        return max;
        
    }
};