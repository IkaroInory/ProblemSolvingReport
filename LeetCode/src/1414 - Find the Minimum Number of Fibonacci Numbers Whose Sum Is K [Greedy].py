class Solution:
    def findMinFibonacciNumbers(self, k: int) -> int:
        list = [1, 1]
        while k > list[-1]:
            list.append(list[-1] + list[-2])

        ans = 0
        index = len(list) - 1
        while k > 0:
            if k >= list[index]:
                k -= list[index]
                ans += 1
            else:
                index -= 1

        return ans
