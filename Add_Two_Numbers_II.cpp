//QUESTION LINK : https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/564/week-1-november-1st-november-7th/3522/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		stack<int> st1;
		stack<int> st2;
		ListNode* temp = l1;
		while (temp) {
			st1.push(temp -> val);
			temp = temp -> next;
		}
		temp = l2;
		while (temp) {
			st2.push(temp -> val);
			temp = temp -> next;
		}
		ListNode* res = NULL;
		int carry = 0;
		while (!st1.empty() || !st2.empty()) {
			int v1 = 0, v2 = 0;

			if (!st1.empty()) {
				v1 = st1.top();
				st1.pop();
			}
			if (!st2.empty()) {
				v2 = st2.top();
				st2.pop();
			}

			int ans = v1 + v2 + carry;
			ListNode* newNode = new ListNode(ans % 10);
			newNode -> next = res;
			res = newNode;
			carry = ans / 10;
		}
		if (carry != 0) {
			ListNode* newNode = new ListNode(carry);
			newNode -> next = res;
			res = newNode;
		}
		return res;
	}
};