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
        if(head==NULL)
        return head;
        ListNode* help=new ListNode(-1);//借助一个辅助节点，防止要删除的节点时包括头节点的几个节点
        help->next=head;
        ListNode *prev=help;
        ListNode  *cur=head;
        while(cur!=NULL){
            if(cur->val==val){
                prev->next=cur->next;
                delete cur;
                cur=prev;
            }
            prev=cur;
            cur=cur->next;
        }
        ListNode *t=help->next;//这里不能直接return head,因为有可能head存放的val正好是t要被删除的，
        delete help; //只能return helpNode->next;
        help=nullptr;
        return t;
    }
};
```

3、[206. 反转链表](https://leetcode-cn.com/problems/reverse-linked-list/)

你可以迭代或递归地反转链表。你能否用两种方法解决这道题？

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {    //从新建立一个链表，将原来的链表的值进行头插
public:
   ListNode* _buynode(int x)
    {
        ListNode* node=new ListNode(x);
        return node;
    }
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)
        return head;
        ListNode* p=head->next;;
       ListNode* head2=_buynode(head->val);
        while(p!=NULL){
            ListNode* q=_buynode(p->val);
            q->next=head2;
            head2=q;
            p=p->next;
        }
        return head2;
    }
};
    ListNode* reverseList(ListNode* head) {
        //利用两个指针实现反转
        if(head==NULL)
        return head;
        ListNode *cur=NULL;
        ListNode *pnext=head;
        while(pnext!=NULL){
            ListNode *t=pnext->next;
            pnext->next=cur;
            cur=pnext;
            pnext=t;
        }
        return cur;
    }
     ListNode* reverseList(ListNode* head) {
         //递归
         if(head==NULL||head->next==NULL){
             return head;
         }
         ListNode *cur=reverseList(head->next);
         head->next->next=head;
         head->next=NULL;
         return cur;
     }
```

4、https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a?tpId=13&&tqId=11167&rp=2&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking

输入一个链表，输出该链表中倒数第k个结点。

```c++
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead==NULL)
            return pListHead;
        ListNode* fast=pListHead;
        ListNode* slow=pListHead;
        while(fast!=NULL&&k)
        {
            fast=fast->next;
            k--;
        }
        if(fast==NULL&&k>0)  //k>所有的节点数，返回NULL
            return NULL;
        else if(fast==NULL&&k==0)//k==所有的节点数，返回pListHead;
            return pListHead;
        while(fast!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};
```

https://leetcode-cn.com/problems/merge-two-sorted-lists/submissions/

#### 5、将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

**输入：**1->2->4, 1->3->4 **输出：**1->1->2->3->4->4

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *///可以试试快排
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
        return l2;
         if(l2==NULL)
        return l1;
        ListNode* l3=new ListNode(-1);
        ListNode* p=l3;
        while((l1!=NULL)&&(l2!=NULL)){

            if((l1->val)<=(l2->val)){
               ListNode* tmp=new ListNode(l1->val);
                l1=l1->next;
               p->next=tmp;
               p=tmp;
            }
              else{
               ListNode* tmp=new ListNode(l2->val);
               l2=l2->next;
               p->next=tmp;
               p=tmp;
              }
        }
        ListNode* head=l3->next;
        delete l3;
        l3=nullptr;
        if(l1==NULL&&l2!=NULL){
            p->next=l2;
            return head;
        }
        if(l2==NULL&&l1!=NULL){
            p->next=l1;
            return head;
        }
        return head;
    }
};

//递归
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
        return l2;
         if(l2==NULL)
        return l1;
        if(l1->val<=l2->val)
           {
               l1->next=mergeTwoLists(l1->next, l2);
               return l1;
           }
           else{
               l2->next=mergeTwoLists(l1, l2->next);
               return l2;
           }
     }
```

https://www.nowcoder.com/practice/0e27e0b064de4eacac178676ef9c9d70?tpId=8&&tqId=11004&rp=2&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking

##### 6、链表分割   编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前

##### 给定一个链表的头指针 ListNode* **pHead**，请返回重新排列后的链表的头指针。注意：分割以后保持原来的数据顺序不变。

```c++
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {//借助于两个大小链表
public:
    ListNode* partition(ListNode* pHead, int x) {
        if(pHead==NULL)
            return pHead;
        ListNode* big =new ListNode(-1);
        ListNode* small =new ListNode(-1);
        ListNode* cur =pHead;
        ListNode* left =small;
        ListNode* right =big;
        while(cur)
        {
            if(cur->val<x)
            {
                left->next=cur;
                left=cur;
            }
            if(cur->val>=x)
            {
                right->next=cur;
                right=cur;
            }
            cur=cur->next;
        }
        right->next=NULL;
        left->next=big->next;
        ListNode* tmp=small->next;
        delete big;
        big=nullptr;
        delete small;
        small=nullptr;
        return tmp;
    }
};
```

https://www.nowcoder.com/practice/fc533c45b73a41b0b44ccba763f866ef?tpId=13&&tqId=11209&rp=1&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking

7、删除链表中重复的结点

在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5

```c++
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead==NULL)
            return pHead;
        ListNode *helpNode=new ListNode(-1);
        helpNode->next=pHead;
        ListNode* prev=helpNode;
        ListNode* cur=pHead;
        while(cur)
        {
            if(cur->next!=NULL && cur->val==cur->next->val)
            {
               while(cur->next!=NULL && cur->val==cur->next->val)
               {
                    cur=cur->next;
                }
                     prev->next=cur->next;
                     cur=prev->next;
            }
            else
            {
                prev=cur;
                cur=cur->next;
            }
        }
        ListNode* tmp=helpNode->next;
        delete helpNode;
        helpNode=NULL;
        return tmp;
    }
};
```

https://www.nowcoder.com/practice/d281619e4b3e4a60a2cc66ea32855bfa?tpId=49&&tqId=29370&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking

##### 8、链表的回文结构        对于一个链表，请设计一个时间复杂度为O(n),额外空间复杂度为O(1)的算法，判断其是否为回文结构。给定一个链表的头指针**A**，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900。 测试样例： 

//先找到中间节点（快慢指针），在反转中间节点以后的链表，最后在左右同时进行比较

```c++
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class PalindromeList {
public:
    bool chkPalindrome(ListNode* A) {
        ListNode* fast=A;
        ListNode* slow=A;
        while(fast&&fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        //反转前面那部分的链表 利用两个指针反转链表
        ListNode* cur=slow;
        ListNode* pnext=slow->next;
        while(pnext)
        {
            ListNode* tmp=pnext->next;
            pnext->next=cur;
            cur=pnext;
            pnext=tmp;
        }
        while(cur!=slow)//这是slow就是中间节点
        {
            if(A->val==cur->val)
            {
                A=A->next;
                cur=cur->next;
            }
            else
            {
                return false;
            }
        }
            return true;
    }
};
```

https://leetcode-cn.com/problems/intersection-of-two-linked-lists/submissions/

9、[160. 相交链表]编写一个程序，找到两个单链表相交的起始节点。

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr) 
            return nullptr;
        ListNode* cur_a=headA;
        ListNode* cur_b=headB;
        while(cur_a!=cur_b)
        {
            cur_a=(cur_a==NULL ? headB:cur_a->next);
            cur_b=(cur_b==NULL ? headA:cur_b->next);
        }
        return cur_a;
    }
};
```

