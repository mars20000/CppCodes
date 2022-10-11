class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        dc = {0:0, 1:0, 2:0}
        for i in nums:
            dc[i]+=1
        i = 0
        for key in dc:
            for j in range(dc[key]):
                nums[i] = key
                i+=1
        
