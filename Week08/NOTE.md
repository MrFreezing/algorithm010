学习笔记


1. 快速排序
int parttion(int *arr, int begin, int end) {
	if (begin < 0 || end < begin || !arr) 
		return -1;
	
	int pis = arr[end];
	int i = begin - 1;
	for (int j = begin; j < end; j++) {
		if (arr[j] <= pis) {
			i++;
			swap(arr[j], arr[i]);
		}
	}
	swap(arr[i], arr[end]);
	return i + 1;
}

void qsort(int *arr, int begin, int end) {
	if (begin < 0 || end < begin || !arr) 
		return;

	stack<int> s;
	s.push(end);
	s.push(begin);

	while (s.size()) {
		int left = s.top();
		s.pop();
		int right = s.top();
		s.pop();

		int k = pattion(arr, left, right);
		if (left < k) {
			s.push(k - 1);
			s.push(left));
		}
		if (right > k) {
			s.push(right);
			s.push(k + 1));
		}
	}
}


2. 位图
	布隆过滤器
	LRU
	整数类算法题
