class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def DFS(tree: TreeNode) -> List:
    open = []
    close = []

    open.append(tree)
    while len(open) != 0:
        temp = open.pop()
        if temp is None:
            close.append("null")
        else:
            close.append(temp.val)
            open.append(temp.right)
            open.append(temp.left)
    return close

