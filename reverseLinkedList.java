// This code reverses linked list in java. 
// time:  O(n)
// space: O(1)


// In this solution we have to use 3 pointers curr,next and prev

class Solution {
    public ListNode reverseList(ListNode head) {
        if(head == null || head.next == null) return  head;
        return utilFunc(head,head,null);
    }
    public ListNode utilFunc(ListNode curr,ListNode next,ListNode prev) {
        if(curr == null) return prev;
        
        next = next.next;
        curr.next = prev;
        prev = curr;
        curr = next;
        
        return utilFunc(curr,next,prev);
    }
}
