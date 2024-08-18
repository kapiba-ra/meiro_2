#pragma once

#include <queue>
#include <vector>
#include <unordered_map>

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

/* �V */
// �m�[�h��\���\����
struct GraphNode
{
    int x, y;  // �m�[�h�̈ʒu
    std::vector<GraphNode*> mAdjacent; // �אڂ���m�[�h

    // �f�t�H���g�R���X�g���N�^�[
    GraphNode() : x(0), y(0) {}

    // �����t���R���X�g���N�^�[
    GraphNode(int x, int y) : x(x), y(y) {}
};

// �O���t��\���\����
struct Graph
{
    std::vector<std::vector<GraphNode>> mNodes; // �m�[�h��2D�z��
};

// ���D��T�� (BFS) ��p���čŒZ�������v�Z����֐�
bool BFS(const Graph& graph, const GraphNode* start, const GraphNode* goal, std::unordered_map<const GraphNode*, const GraphNode*>& outMap)
{
    bool pathFound = false; // �o�H�������������ǂ���
    std::queue<const GraphNode*> q; // �T������m�[�h�̃L���[
    q.emplace(start); // �X�^�[�g�m�[�h���L���[�ɒǉ�
    outMap[start] = nullptr; // �X�^�[�g�m�[�h�̐e�� nullptr

    while (!q.empty())
    {
        const GraphNode* current = q.front(); // �L���[����m�[�h���擾
        q.pop(); // �m�[�h���L���[����폜

        // �S�[���m�[�h�ɓ��B������T���I��
        if (current == goal)
        {
            pathFound = true;
            break;
        }

        // �אڃm�[�h���L���[�ɒǉ�
        for (const GraphNode* node : current->mAdjacent)
        {
            if (outMap.find(node) == outMap.end()) // �m�[�h�����K��Ȃ�
            {
                outMap[node] = current; // ���݂̃m�[�h��e�ɐݒ�
                q.emplace(node); // �m�[�h���L���[�ɒǉ�
            }
        }
    }

    return pathFound;
}
