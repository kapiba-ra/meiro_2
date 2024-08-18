//#pragma once
//
//#include <queue>
//#include <vector>
//#include <unordered_map>

/* 旧 */
// 隣接するノードの情報を持っている
//struct GraphNode
//{
//	std::vector<GraphNode*> mAdjacent;
//};
//struct Graph
//{
//	std::vector<GraphNode*> mNodes;
//};
//
//using NodeToParentMap = std::unordered_map<const GraphNode*, const GraphNode*>;
//
//bool BFS(const Graph& graph, const GraphNode* start, const GraphNode* goal, NodeToParentMap& outMap)
//{
//	bool pathFound = false;			// 経路を見つけたかどうか
//	std::queue<const GraphNode*> q; // 検討するノード
//	q.emplace(start);				// 最初のノードから検討
//
//	while (!q.empty())
//	{
//		const GraphNode* current = q.front();	// 手前から調べる
//		q.pop();								//	既に調べたものは無くす
//		// ゴールを見つけたら探索終了
//		if (current == goal)
//		{
//			pathFound = true;
//			break;
//		}
//
//		// 隣接するノードをキューにいれる
//		for (const GraphNode* node : current->mAdjacent)
//		{
//			const GraphNode* parent = outMap[node];
//			if (parent == nullptr && node != start)
//			{
//				outMap[node] = current;
//				q.emplace(node);
//			}
//		}
//	}
//	return pathFound;
//}
