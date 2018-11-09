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
 
    def dijkstra(self, src):
        dist = [sys.maxint] * self.vert
        dist[src] = 0
        Set = [False] * self.vert
 
        for cout in range(self.vert):
            u = self.miniDist(dist, Set)
            Set[u] = True
            for v in range(self.vert):
                if self.graph[u][v] > 0 and Set[v] == False and dist[v] > dist[u] + self.graph[u][v]:
                        dist[v] = dist[u] + self.graph[u][v]

# Optimal Meeting Point Algorithm
def find_meetup_city(adj_matrix, your_city, friend_city):
  distp = adj_matrix.dijkstra(your_city)
  distp = adj_matrix.dijkstra(friend_city)
  time = sys.maxint
  for ver in range(adj_matrix.vert):
    if time > max(adj_matrix.dijkstra(ver), adj_matrix.dijkstra(ver)):
      time = max(adj_matrix.dijkstra(ver), adj_matrix.dijkstra(ver))
      best = ver
      print best
  return best
 
# Test 
g  = Graph(4)
g.graph = [
           [0, 2, 0, 2],
           [2, 0, 3, 0],
           [0, 3, 0, 5],
           [2, 0, 5, 0]
          ];
 
find_meetup_city(g, 0, 2);



