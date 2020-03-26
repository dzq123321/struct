1、string类的中 npos,c_str函数

npos是无符号int的最大值，在系统中被静态定义为-1

```c++
static const size_t npos = -1;
```

c_str函数，将string类转换为字符串类，这样就可以调用字符串函数

2、https://leetcode-cn.com/problems/remove-linked-list-elements/submissions/

删除链表中等于给定值 **val** 的所有节点。

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        //借助一个辅助的头节点
        if(head==nullptr)
        return head;
        ListNode* helpNode=new ListNode(-1);//借助一个辅助节点，防止要删除的节点时包括头节点的几个节点
        helpNode->next=head;
        ListNode* cur=helpNode;
        ListNode* prev=head;
        while(cur!=nullptr){
            if(cur->val==val){
                prev->next=cur->next;
                delete cur;
                cur=prev;
            }
            prev=cur;
            cur=cur->next;
        }
        ListNode* ret=helpNode->next;
        delete helpNode;//这里不能直接return head,因为有可能head存放的val正好是t要被删除的，只能                                //return helpNode->next;
      return ret;
    }
};
```

