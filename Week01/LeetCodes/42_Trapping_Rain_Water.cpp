class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        if (len < 2) return 0;        

        stack<int> idx;//位置栈
        stack<int> hi;//高度向量栈
        int area = 0;//雨水总面积

        for (int i = 1; i < len; i++) {
            int t_hi = height[i] - height[i-1];
            if ( t_hi > 0 ) area += pop(idx, hi, i, t_hi);
            else if (t_hi < 0 ) {
                idx.push(i);
                hi.push(-t_hi);
            }  else {
                //do nothing
            }
        }
        
        return area;    
    }

    int pop (stack<int> &idx, stack<int>& hi, int index, int height ) {
        if (idx.size() == 0 ) return 0;

        int s_hi = hi.top(); hi.pop();
        int s_idx = idx.top(); idx.pop();

        if (height > s_hi) {
            return s_hi * (index - s_idx) + pop(idx, hi, index, height - s_hi);
        } else if (height == s_hi) {
            return s_hi * (index - s_idx);
        } else {
            idx.push(s_idx);
            hi.push(s_hi - height);
            return height * (index - s_idx);
        }
    }    
};

