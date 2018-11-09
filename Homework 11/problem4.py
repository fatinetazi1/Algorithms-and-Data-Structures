from random import randint
import sys

class PuzzleBoard():
    def __init__(self, boardSize, fields):
        self.xpos = 0
        self.ypos = 0
        self.boardSize = boardSize
        self.graph = [[0 for column in range(boardSize)] 
                      for row in range(boardSize)]
        for x in range(boardSize):
            for y in range(boardSize):
                if fields[x][y] is None:
                    rand = randint(1, boardSize-1)
                    self.graph[x][y] = rand
                else:
                    self.graph[x][y] = fields[x][y]
        self.position = self.graph[self.xpos][self.ypos]
    
    def makeMove(self, direction):
        r = false
        if direction == 0:
            compare = xpos + self.graph[self.xpos][self.ypos]
            if compare > 0 and compare < boardSize:
                xpos = xpos + self.graph[self.xpos][self.ypos]
                r = true
        elif direction == 1:
            compare = ypos + self.graph[self.xpos][self.ypos]
            if compare > 0 and compare < boardSize:
                ypos = ypos + self.graph[self.xpos][self.ypos]
                r = true
        elif direction == 2:
            compare = xpos - self.graph[self.xpos][self.ypos]
            if compare > 0 and compare < boardSize:
                xpos = xpos - self.graph[self.xpos][self.ypos]
                r = true
        elif direction == 4:
            compare = ypos - self.graph[self.xpos][self.ypos]
            if compare > 0 and compare < boardSize:
                ypos = ypos - self.graph[self.xpos][self.ypos]
                r = true
        else: 
            print "Not a direction."

        return r

    def getResult(self):
        return self.graph[xpos][ypos] == self.graph[boardSize-1][boardSize-1]


    def __str__(self):
        return self.graph

    def solve(self):
        if self.graph[self.xpos][self.ypos] == self.graph[self.boardSize-1][self.boardSize-1]:
            return 0
        elif self.makeMove(0) and self.makeMove(1) and self.makeMove(2) and self.makeMove(3):
            up = 1
            right = 1
            down = 1
            left = 1
            for x in range(0, 3):
                r = self.makeMove(x)
                if r == false:
                    if x == 0:
                        up = 0
                    elif x == 1:
                        right = 0
                    elif x == 2:
                        down = 0
                    else:
                        left = 0
            mindist = sys.maxint
            moves = 0
            while(mindist != 0):
                if up:
                    self.makeMove(0)
                    compare = (boardSize - 1 - self.xpos) + (boardSize - 1 - self.ypos)
                    if mindist > compare:
                        mindist = compare 
                    self.makeMove(2)
                if right: 
                    self.makeMove(1)
                    compare = (boardSize - 1 - self.xpos) + (boardSize - 1 - self.ypos)
                    if mindist > compare:
                        mindist = compare 
                    self.makeMove(3)
                if down:
                    self.makeMove(2)
                    compare = (boardSize - 1 - self.xpos) + (boardSize - 1 - self.ypos)
                    if mindist > compare:
                        mindist = compare 
                    self.makeMove(0)
                if left:
                    self.makeMove(3)
                    compare = (boardSize - 1 - self.xpos) + (boardSize - 1 - self.ypos)
                    if mindist > compare:
                        mindist = compare 
                    self.makeMove(1)
                if up or right or down or left:
                    moves = moves + 1
            return moves
        else: 
            return -1

graph = [
           [0, 2, 0, 2],
           [2, 0, 3, 0],
           [0, 3, 0, 5],
           [2, 0, 5, 0]
          ];
g  = PuzzleBoard(4, graph)
 
g.solve();



