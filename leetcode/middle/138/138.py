from typing import Optional
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random


class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if not head:
            return None
        p = head
        while p :
            new_node = Node(p.val,None,None)
            new_node.next = p.next
            p = new_node.next
        p = head

        while p:
            if p.random:
                p.next.random = p.random.next
            p = p.next.next
        p = head
        dummy = Node(0,None,None)
        while p :
            cur.next = p.next
            cur = cur.next
            p.next = cur.next
            p = p.next
        return dummy.next