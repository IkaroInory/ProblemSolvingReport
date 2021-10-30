class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def BFS(tree: TreeNode) -> List:
    open = []
    close = []

    open.append(tree)
    while len(open) != 0:
        temp = open.pop(0)
        if temp is None:
            close.append("null")
        else:
            close.append(temp.val)
            open.append(temp.left)
            open.append(temp.right)
    return close

