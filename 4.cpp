#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

class ListNode{
   public: 
    int val;
    ListNode* next;
    ListNode(int val){
        this->val=val;
        this->next=nullptr;
    }
};
 void reverseArray(vector<int>& v){
        int i=0;
        int j=v.size()-1;
        while(i<j){
            swap(v[i],v[j]);
            i++;
            j--;
        }
    }
ListNode* reverseLL(ListNode* head){
        ListNode *prev=nullptr,*curr=head,*Next=nullptr;
        while(curr){
            Next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=Next;
        }
        return prev;
    }

vector<int> nextLargerNodes(ListNode* head) {
        if(head->next==nullptr) return {0};
        ListNode* temp=reverseLL(head);
        stack<int> st;
        vector<int> ans;
        ans.push_back(0);
        st.push(temp->val);
        temp=temp->next;
        while(temp){
            while(st.size()>0&&st.top()<=temp->val) st.pop();
            if(st.size()==0) ans.push_back(0);
            else ans.push_back(st.top());
            st.push(temp->val);
            temp=temp->next;
        }
        reverseArray(ans);
        return ans; 
    }  

