// Problem URL: https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
private:
    void joinList(Node* parent, Node* CHead, Node* CTail) {
        Node* parentNext = parent->next;
        parent->next = CHead;
        CHead->prev = parent;
        CTail->next = parentNext;
        if (parentNext != NULL) parentNext->prev = CTail;
    }
    pair <Node*,Node*> flattenList(Node* node) {
        Node* tail = node, *ptr = node;
        while (ptr != NULL) {
            tail = ptr;
            Node * nextPtr = ptr->next;
            if (ptr->child != NULL) {
                pair <Node*,Node*> p = flattenList(ptr->child);
                joinList(ptr, p.first, p.second);
                ptr->child = NULL;
                tail = p.second;
            }
            ptr = nextPtr;
        }
        return make_pair(node,tail);
    }
public:
    Node* flatten(Node* head) {
        return flattenList(head).first;
    }
};