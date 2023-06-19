class TreeAncestor:
    def __init__(self, n: int, parent: List[int]):
        self.fa = [[0]*20 for _ in range(n+1)]
        for i in range(1,n+1):
            self.fa[i][0] = parent[i-1] + 1
        for j in range(1, 20):
            for i in range(1,n+1):
                self.fa[i][j] = self.fa[self.fa[i][j-1]][j-1]



    def getKthAncestor(self, node: int, k: int) -> int:
        node+=1
        for i in range(20):
            if k & 1:
                node = self.fa[node][i]
            k >>= 1
            if node == 0:
                break
        return node - 1
