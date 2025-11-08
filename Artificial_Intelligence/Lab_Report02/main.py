import numpy as np
from collections import deque
import random

class Node:
    def __init__(self, x, y, level, move=None):
        self.x = x
        self.y = y
        self.level = level
        self.move = move

class BFS:
    def __init__(self, N):
        self.direction = [
            (1, 0, "Moving Down"),
            (-1, 0, "Moving Up"),
            (0, 1, "Moving Right"),
            (0, -1, "Moving Left")
        ]
        self.source = -1
        self.goal = np.inf
        self.goal_level = np.inf
        self.N = N
        self.found = False
        self.visited = []
        self.moves_log = []

    def init_graph(self):
        graph = [[random.randint(0, 1) for _ in range(self.N)] for _ in range(self.N)]

        print('Automatic Generated Graph:')
        self.print_graph(graph)
        print(f'Total Node: {N}x{N}')

        src_str = input('Enter Source Coordinate (Space Separated): ').split()
        goal_str = input('Enter Goal Coordinate (Space Separated): ').split()
        print()

        source_x, source_y = int(src_str[0]), int(src_str[1])
        goal_x, goal_y = int(goal_str[0]), int(goal_str[1])
        self.source = Node(source_x, source_y, 0)
        self.goal = Node(goal_x, goal_y, np.inf)
        return graph

    def calculate_bfs(self, graph):
        queue = deque()
        queue.append(self.source)

        graph[self.source.x][self.source.y] = 5
        self.visited.append(self.source)

        while queue:
            u = queue.popleft()

            for dx, dy, move_name in self.direction:
                v_x, v_y = u.x + dx, u.y + dy

                if 0 <= v_x < self.N and 0 <= v_y < self.N and graph[v_x][v_y] == 1:
                    v_level = u.level + 1
                    node_v = Node(v_x, v_y, v_level, move_name)
                    self.visited.append(node_v)

                    # record the move
                    self.moves_log.append((move_name, (v_x, v_y)))

                    if v_x == self.goal.x and v_y == self.goal.y:
                        self.found = True
                        self.goal_level = v_level
                        self.goal.level = v_level
                        return

                    graph[v_x][v_y] = 5
                    queue.append(node_v)

    def print_data(self):
        if self.found:
            print(f'Goal Found\nLevel: {self.goal_level}')
        else:
            print('Goal Not Found')

    def print_graph(self, graph):
        for row in graph:
            for col in row:
                print(f'{col} ', end="")
            print()
        print()

    def print_moves(self):
        print("Traversal Moves:")
        for move_name, (x, y) in self.moves_log:
            print(f"{move_name} -> ({x}, {y})")
        print()

if __name__ == "__main__":
    bfs = BFS(5)
    g = bfs.init_graph()
    bfs.calculate_bfs(g)
    bfs.print_data()
    bfs.print_graph(g)
    bfs.print_moves()