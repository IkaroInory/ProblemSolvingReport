class graph:
    edge: Dict[str, Dict[str, int]]

    def __init__(self):
        self.edge = {}
        self.edge.clear()

    def addpoint(self, point: str):
        if point not in self.edge:
            self.edge.setdefault(point, {})

    def addedge(self, p1: str, p2: str, weight: int):
        if p1 in self.edge and p2 in self.edge:
            self.edge[p1][p2] = weight
            self.edge[p2][p1] = weight

    def getedge(self, point: str) -> Dict[str, int]:
        return self.edge[point]

    def getweight(self, p_from: str, p_to: str):
        if p_to in self.edge[p_from]:
            return self.edge[p_from][p_to]
        return -1


def astar(g: graph, h: Dict[str, int], begin: str, end: str) -> tuple:
    if begin == end:
        return 0, (begin, end)

    length: int = 0
    road: tuple = (begin,)

    cur: str = begin
    while cur != end:
        f: List[tuple] = []
        temp: Dict[str, int] = g.getedge(cur)
        for k, v in temp.items():
            f += [(k, length + v + h[k])]
        newf: List[tuple] = sorted(f, key=lambda a: a[1])
        length += g.getweight(cur, newf[0][0])
        road += (newf[0][0],)
        cur = newf[0][0]
    return length, road
