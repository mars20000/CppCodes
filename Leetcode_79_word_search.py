class Solution(object):
    
    
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        def dfs(visited, board, word, i, j, k):
            if word[k] != board[i][j]:
                return False
            if len(word)-1==k and board[i][j]==word[k]:
                return True
            if board[i][j] == word[k]:
                visited[i][j] = True
            result = False
            if i!=0 and not visited[i-1][j]:
                result = result or dfs(visited, board, word, i-1, j, k+1)
            if j!=0 and not visited[i][j-1]:
                result = result or dfs(visited, board, word, i, j-1, k+1)
            if i!=len(board)-1 and not visited[i+1][j]:
                result = result or dfs(visited, board, word, i+1, j, k+1)
            if j!=len(board[0])-1 and not visited[i][j+1]:
                result = result or dfs(visited, board, word, i, j+1, k+1)
            visited[i][j] = False
            
            return result
        
        m = len(board)
        n = len(board[0])
        visited = [[False]*n for i in range(m)]
        for i in range(m):
            for j in range(n):
                if dfs(visited, board, word, i,j, 0):
                    return True
        return False
