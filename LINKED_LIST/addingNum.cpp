struct ListNode {
    int val;
    ListNode *next;
     ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
void insert(struct ListNode* head, int val) {
    struct ListNode* temp = new ListNode(val);
    if (head == nullptr) {
        head = temp;
    } else {
        struct ListNode* temp2 = head;
        while (temp2->next != nullptr) {
            temp2 = temp2->next;
        }
        temp2->next = temp;
    }
}
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        struct ListNode* head = new ListNode();
        int carry = 0;
        while (l1 && l2) {

            int a = l1->val;
            int b = l2->val;
            l1 = l1->next;
            l2 = l2->next;

            if (carry + a + b >= 10) {

                insert(head, carry + a + b - 10);
                carry = 1;
            } else {
                insert(head, carry + a + b);
                carry = 0;
            }
        }
        while (l1 || l2) {
            if (l1) {
                if (l1->val + carry >= 10) {
                    insert(head, l1->val + carry - 10);
                    l1 = l1->next;
                    carry = 1;
                } else{
                    insert(head,l1->val+carry);
                     l1 = l1->next;
                    carry = 0;

                }
            }
            if (l2) {
               if (l2->val + carry >= 10) {
                    insert(head, l2->val + carry - 10);
                    l2 = l2->next;
                    carry = 1;
                } else{
                    insert(head,l2->val+carry);
                     l2 = l2->next;
                    carry = 0;

                }
            }

        }
        if(carry==1){
            insert(head,carry);
        }
        head = head->next;
        return head;
    }
};

int main(){




    return 0;
}