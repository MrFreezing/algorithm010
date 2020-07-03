学习笔记

1.搜索
    每个节点访问一次
    1.1 深度优先搜索Depth first Search

    递归模板
    visited = set()
    def dfs(node, visited):
        #terminator
        if node in visited: 
            #already visited
            return

        visited.add(node)
        #process current node here.
        ...
        for next_node in node.children():
            if not next_node in visited:
                dfs(nex node, visited)


	非递归模板
	def DFS(self, tree):
		if tree.root is Node:
			return []	
		
		visited, stack = [], [tree.root]

		while stack：
			node = stack.pop()
			visited.add(node)
			
			process(node)
			nodes = generate_related_nodes(node)
			stack.push(nodes)

		# other processing work
		...


    1.1 广度优先搜索Breadth first Search

	def BFS(graph, start, end):
		queue = []
		queue.append([start])
		visited.add(start)

		while queue:
			node = queue.pop()
			visited.add(node)

			process(node)
			nodes = generate_related_nodes(node)
			queue.push(nodes)
		#other processing work
		...



2.贪心算法Greedy
	贪心算法是一种在每一步选择中都采取当前状态下最好或最优（即最有利）的选择，从而希望导致结果是全局最好或最优的算法。

	贪心算法与动态规划的不同在于它对每个子问题的解决方案都做出选择，不能回退。动态规划会保存以前的运算结果，并根据以前的结果对当前进行选择，有回退功能。

	贪心：当下做局部最优判断
	回溯：能够回退
	动态规划：最优判断+回退



















