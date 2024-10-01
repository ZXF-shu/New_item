#
# @lc app=leetcode.cn id=2651 lang=python3
#
# [2651] 计算列车到站时间
#

# @lc code=start
class Solution:
    def findDelayedArrivalTime(self, arrivalTime: int, delayedTime: int) -> int:
        return (arrivalTime + delayedTime) % 24
    #取模运算符的效率比减法低
# @lc code=end

