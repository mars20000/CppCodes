class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        m = len(matrix)
        n = len(matrix[0])

        if target<matrix[0][0] or target>matrix[-1][-1]:
            return False
        
        u,d = 0, m-1
        i = 0
        while(u<d):
            m =  u+(d-u)/2
            print(u,d)
            if matrix[m][0] == target:
                return True
            elif matrix[m][0]>target:
                d = m-1
            else:
                u = m
                if target<=matrix[m][n-1]:
                    break
                else:
                    u+=1
        print(u,d)
        i = u
        j = 0
        l,r = 0, n-1
        while(l<r):
            m = l+(r-l)/2
            if matrix[i][m] == target:
                return True
            elif matrix[i][m]>target:
                r = m-1
            else:
                l = m+1
        return matrix[i][l] == target
