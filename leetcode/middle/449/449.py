# Definition for a binary tree node.
from typing import Optional
class TreeNode:
     def __init__(self, x):
         self.val = x
         self.left = None
         self.right = None

class Codec:

    def serialize(self, root: Optional[TreeNode]) -> str:
        """Encodes a tree to a single string.
        """
        if root is None:
            return ""
        return str(root.val) + "," + self.serialize(root.left) + "," + self.serialize(root.right)

    def deserialize(self, data: str) -> Optional[TreeNode]:
        """Decodes your encoded data to tree.
        """
        if data == "":
            return None
        data = data.split(",")
        def buildTree(data):
            if data[0] == "":
                data.pop(0)
                return None
            root = TreeNode(data[0])
            data.pop(0)
            root.left = buildTree(data)
            root.right = buildTree(data)
            return root
        return buildTree(data)


# Your Codec object will be instantiated and called as such:
# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# tree = ser.serialize(root)
# ans = deser.deserialize(tree)
# return ans