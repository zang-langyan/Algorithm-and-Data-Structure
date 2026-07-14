
from collections import defaultdict
from heapq import heappop, heappush, heappushpop, heapify


class LazyHeap:
    def __init__(self):
        self.heap = []
        self.remove_cnt = defaultdict(int)  # 每个元素剩余需要删除的次数
        self.size = 0  # 实际大小

    # 删除
    def remove(self, x: int) -> None:
        self.remove_cnt[x] += 1  # 懒删除
        self.size -= 1

    # 正式执行删除操作
    def apply_remove(self) -> None:
        while self.heap and self.remove_cnt[self.heap[0]] > 0:
            self.remove_cnt[self.heap[0]] -= 1
            heappop(self.heap)

    # 查看堆顶
    def top(self) -> int:
        self.apply_remove()
        return self.heap[0]

    # 出堆
    def pop(self) -> int:
        self.apply_remove()
        self.size -= 1
        return heappop(self.heap)

    # 入堆
    def push(self, x: int) -> None:
        heappush(self.heap, x)
        self.size += 1

    # push(x) 然后 pop()
    def pushpop(self, x: int) -> int:
        self.apply_remove()
        return heappushpop(self.heap, x)

class Solution:
    def medianSlidingWindow(self, nums: list[int], k: int) -> list[float]:
        ans = [0] * (len(nums) - k + 1)
        left = LazyHeap()   # 最大堆（元素取反）
        right = LazyHeap()  # 最小堆

        for i, x in enumerate(nums):
            # 1. 进入窗口
            if left.size == right.size:
                left.push(-right.pushpop(x))
            else:
                right.push(-left.pushpop(-x))

            l = i + 1 - k
            if l < 0:  # 窗口大小不足 k
                continue

            # 2. 计算答案
            if k % 2:
                ans[l] = -left.top()
            else:
                ans[l] = (right.top() - left.top()) / 2

            # 3. 离开窗口
            x = nums[l]
            if x <= -left.top():
                left.remove(-x)
                if left.size < right.size:
                    left.push(-right.pop())  # 平衡两个堆的大小
            else:
                right.remove(x)
                if left.size > right.size + 1:
                    right.push(-left.pop())  # 平衡两个堆的大小

        return ans
