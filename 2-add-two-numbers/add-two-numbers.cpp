class Solution {
public:
    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
        ListNode* temp1 = head1;
        ListNode* temp2 = head2;
        int carry = 0;

        // Traverse both lists while both nodes exist
        while (temp1 && temp2) {
            temp1->val += temp2->val + carry;
            carry = temp1->val / 10;
            temp1->val %= 10;

            // If both nexts exist, move forward
            if (temp1->next && temp2->next) {
                temp1 = temp1->next;
                temp2 = temp2->next;
            } else {
                break;
            }
        }

        // If list2 is shorter, continue with list1
        if (!temp2->next) {
            while (temp1->next) {
                temp1 = temp1->next;
                temp1->val += carry;
                carry = temp1->val / 10;
                temp1->val %= 10;
                if (!carry) break;
            }
            if (carry) {
                temp1->next = new ListNode(carry);
            }
        }
        // If list1 is shorter, attach list2 and continue
        else if (!temp1->next) {
            temp1->next = temp2->next;
            temp1 = temp1->next;
            while (temp1) {
                temp1->val += carry;
                carry = temp1->val / 10;
                temp1->val %= 10;
                if (!carry || !temp1->next) break;
                temp1 = temp1->next;
            }
            if (carry) {
                temp1->next = new ListNode(carry);
            }
        }

        return head1;
    }
};
;