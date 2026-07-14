class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:

        n = len(board)
        m = len(board[0])

        for i in range(n):
            check = []
            for x in board[i]:
                if x == ".":
                    continue
                if x in check:
                    return False
                else:
                    check.append(x)
        
        for i in range(n):
            check = []
            for j in range(n):
                if board[j][i] == ".":
                    continue
                if board[j][i] in check:
                    return False
                else:
                    check.append(board[j][i])
        for i in range(0,9,3):
            for j in range(0,9,3):
                check = []
                for k in range(i, i+3):
                    for p in range(j, j+3):
                        if board[k][p] == ".":
                            continue
                        if board[k][p] in check:
                            return False
                        else:
                            check.append(board[k][p])
        
        return True
                         