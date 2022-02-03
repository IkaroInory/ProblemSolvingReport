class Solution:
    def maxDepth(self, s: str) -> int:
        depth = 0
        top = 0
        for c in s:
            if c == '(':
                top += 1
            elif c == ')':
                top -= 1
            depth = max(top, depth)

        return depth
