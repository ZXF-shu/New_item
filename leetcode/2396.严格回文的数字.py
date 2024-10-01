#
# @lc app=leetcode.cn id=2396 lang=python3
#
# [2396] 严格回文的数字
#

# @lc code=start
class Solution:
    def isStrictlyPalindromic(self, n: int) -> bool:
        return False
# @lc code=end
#关键在于数学分析
#任何大于5的数的n-2进制都是12
#所以直接就将范围缩小在了有限个
