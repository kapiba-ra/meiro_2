#pragma once

#include <queue>
#include <vector>
#include <unordered_map>

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

/* 新 */
// ノードを表す構造体
struct GraphNode
{
    int x, y;  // ノードの位置
    std::vector<GraphNode*> mAdjacent; // 隣接するノード

    // デフォルトコンストラクター
    GraphNode() : x(0), y(0) {}

    // 引数付きコンストラクター
    GraphNode(int x, int y) : x(x), y(y) {}
};

// グラフを表す構造体
struct Graph
{
    std::vector<std::vector<GraphNode>> mNodes; // ノードの2D配列
};

// 幅優先探索 (BFS) を用いて最短距離を計算する関数
bool BFS(const Graph& graph, const GraphNode* start, const GraphNode* goal, std::unordered_map<const GraphNode*, const GraphNode*>& outMap)
{
    bool pathFound = false; // 経路が見つかったかどうか
    std::queue<const GraphNode*> q; // 探索するノードのキュー
    q.emplace(start); // スタートノードをキューに追加
    outMap[start] = nullptr; // スタートノードの親は nullptr

    while (!q.empty())
    {
        const GraphNode* current = q.front(); // キューからノードを取得
        q.pop(); // ノードをキューから削除

        // ゴールノードに到達したら探索終了
        if (current == goal)
        {
            pathFound = true;
            break;
        }

        // 隣接ノードをキューに追加
        for (const GraphNode* node : current->mAdjacent)
        {
            if (outMap.find(node) == outMap.end()) // ノードが未訪問なら
            {
                outMap[node] = current; // 現在のノードを親に設定
                q.emplace(node); // ノードをキューに追加
            }
        }
    }

    return pathFound;
}
