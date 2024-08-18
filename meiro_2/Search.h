//#pragma once
//
//#include <queue>
//#include <vector>
//#include <unordered_map>

/* �� */
// �אڂ���m�[�h�̏��������Ă���
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
//	bool pathFound = false;			// �o�H�����������ǂ���
//	std::queue<const GraphNode*> q; // ��������m�[�h
//	q.emplace(start);				// �ŏ��̃m�[�h���猟��
//
//	while (!q.empty())
//	{
//		const GraphNode* current = q.front();	// ��O���璲�ׂ�
//		q.pop();								//	���ɒ��ׂ����͖̂�����
//		// �S�[������������T���I��
//		if (current == goal)
//		{
//			pathFound = true;
//			break;
//		}
//
//		// �אڂ���m�[�h���L���[�ɂ����
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
