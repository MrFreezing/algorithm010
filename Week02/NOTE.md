学习笔记

树的遍历
1.前中后序遍历
	递归写法注意边界条件和顺序。
	非递归写法可以用颜色栈比较方便。
2.重建树，已知前中、中后，求剩下的遍历
	前序的首即为根，后序的尾即为根，在中序中检索，可以求得左子树、右子树
	对于前后序，求中序，则无法确定左右子树，如前{4，7}， 后{7，4}

堆
1.建堆、排序、调整算法
2.大根堆一般用于排序，小根堆一般用于组建优先队列（摘自算法导论）
3.priority_queue<T, container<T>, compare<T>>
	默认使用less即大根堆
	可以使用lambda表达式作为第三个参数
        auto cmp = [](pair<int, int>& a, pair<int, int>& b) {return a.second > b.second;};
        priority_queue<pair<int, int> , vector<pair<int, int>>, decltype(cmp)> pq(cmp);
4.当TopK问题中的n取值范围较为固定时，可以使用线性排序算法以取得更优的时间复杂度O(n)，如桶排序，计数排序，基数排序。
 
