/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> map;

    Node* copyRandomList(Node* head) {
        // Base Case 1: If the input node is null, return null
        if (head == nullptr) return nullptr;

        // Base Case 2: If the node has already been cloned, return its cached copy from the map.
        // This avoids redundant creation and prevents infinite recursion on cycles.
        if (map.count(head)) return map[head];

        // Step 1: Instantiate a new node with the original node's value
        Node* copy = new Node(head->val);

        // Step 2: Register the [original -> clone] mapping in the map IMMEDIATELY.
        // This must be done before recursive calls to handle self-referencing or cyclic references.
        map[head] = copy;

        // Step 3: Recursively clone and assign the `next` node
        copy->next = copyRandomList(head->next);

        // Step 4: Recursively clone and assign the `random` node
        copy->random = copyRandomList(head->random);

        // Step 5: Return the cloned node
        return copy;
    }
};