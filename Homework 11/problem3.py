import sys

# Graph Implementation with Dijksta's Algorithm
class Graph():
 
    def __init__(self, vertices):
        self.vert = vertices
        self.graph = [[0 for column in range(vertices)] 
                      for row in range(vertices)]

    def miniDist(self, dist, Set):
        mini = sys.maxint
        for ver in range(self.vert):
            if dist[ver] < mini and Set[ver] == False:
                mini = dist[ver]
                minindex = ver
        return minindex

def picking_order(adj_matrix):
    lst = [0 for x in range(adj_matrix.vert)]
    count = 0
    for x in range(adj_matrix.vert):
        for y in range(adj_matrix.vert):
            if adj_matrix.graph[x][y] == 1:
                if x == 0:
                    lst[count] = x
                    count = count + 1
                    lst[count] = y
                    count = count + 1
                else: 
                    lst[count] = y
                    count = count + 1
    for x in range(adj_matrix.vert):
        print lst[x] , " "

# Test 
g  = Graph(4)
g.graph = [
           [0, 0, 0, 0],
           [0, 1, 0, 0],
           [0, 0, 0, 1],
           [0, 0, 1, 0]
          ];
 
picking_order(g);