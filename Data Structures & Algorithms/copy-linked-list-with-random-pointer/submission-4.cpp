class Solution {
public:
    Node* copyRandomList(Node* head) {

        if (head == NULL)
            return NULL;

        // Step 1: Create copied nodes
        Node* curr = head;

        while (curr != NULL) {

            Node* copy = new Node(curr->val);

            copy->next = curr->next;
            curr->next = copy;

            curr = copy->next;
        }

        // Step 2: Assign random pointers
        curr = head;

        while (curr != NULL) {

            Node* copy = curr->next;

            if (curr->random != NULL) {
                copy->random = curr->random->next;
            }

            curr = copy->next;
        }

        // Step 3: Separate both linked lists
        curr = head;

        Node* dummy = new Node(0);
        Node* copyTail = dummy;

        while (curr != NULL) {

            Node* copy = curr->next;

            // Restore original list
            curr->next = copy->next;

            // Build copied list
            copyTail->next = copy;
            copyTail = copy;

            curr = curr->next;
        }

        Node* ans = dummy->next;

        delete dummy;

        return ans;
    }
};
