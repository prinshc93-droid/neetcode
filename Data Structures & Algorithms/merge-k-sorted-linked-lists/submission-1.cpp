class Solution {
public:

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (l1 != nullptr && l2 != nullptr) {

            if (l1->val <= l2->val) {
                tail->next = l1;
                l1 = l1->next;
            }
            else {
                tail->next = l2;
                l2 = l2->next;
            }

            tail = tail->next;
        }

        if (l1 != nullptr) {
            tail->next = l1;
        }
        else {
            tail->next = l2;
        }

        return dummy.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        int k = lists.size();

        if (k == 0) {
            return nullptr;
        }

        int interval = 1;

        while (interval < k) {

            for (int i = 0; i + interval < k; i += interval * 2) {

                lists[i] = mergeTwoLists(
                    lists[i],
                    lists[i + interval]
                );
            }

            interval *= 2;
        }

        return lists[0];
    }
};