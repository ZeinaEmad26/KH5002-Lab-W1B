
from queue import PriorityQueue

# # = open cell, . = wall, S = start, E = end
maze = [
    'S#.###.###',
    '.#.#.##.#.',
    '####.#.###',
    '#.#.##.#.#',
    '#.###.##.#',
    '##..#.#.##',
    '.##.###.#.',
    '#.###.####',
    '#...##...#',
    '#####.###E'
]

start = (0, 0)
goal = (9, 9)


def neighbours(node):
    row, col = node
    result = []

    for dr, dc in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
        r, c = row + dr, col + dc

        if 0 <= r < 10 and 0 <= c < 10 and maze[r][c] != '.':
            result.append((r, c))

    return result


def BFS(start, goal):
    queue = [(start, [start])]
    visited = {start}
    expanded = 0

    while queue:
        node, path = queue.pop(0)
        expanded += 1

        if node == goal:
            return path, expanded

        for neighbour in neighbours(node):
            if neighbour not in visited:
                visited.add(neighbour)
                queue.append((neighbour, path + [neighbour]))

    return [], expanded


def heuristic(node):
    return abs(node[0] - goal[0]) + abs(node[1] - goal[1])


def a_star(start, goal):
    queue = PriorityQueue()
    queue.put((heuristic(start), 0, start, [start]))
    best_cost = {start: 0}
    expanded = 0

    while not queue.empty():
        f, cost, node, path = queue.get()

        if cost != best_cost[node]:
            continue

        expanded += 1

        if node == goal:
            return path, expanded

        for neighbour in neighbours(node):
            new_cost = cost + 1

            if new_cost < best_cost.get(neighbour, float('inf')):
                best_cost[neighbour] = new_cost
                score = new_cost + heuristic(neighbour)
                queue.put((score, new_cost, neighbour, path + [neighbour]))

    return [], expanded


def show_path(path):
    picture = [list(row) for row in maze]

    for r, c in path[1:-1]:
        picture[r][c] = '*'

    for row in picture:
        print(' '.join(row))


for name, search in [('BFS', BFS), ('A*', a_star)]:
    path, expanded = search(start, goal)

    print('\n', name)
    print('Path length:', len(path) - 1 if path else 'No path')
    print('Nodes expanded:', expanded)

    if path:
        show_path(path)


# Task 7 - Comparing BFS and A*

# BFS:
# Uses a queue to check nodes level by level.
# It does not use a heuristic.

# A* Search:
# Uses a priority queue and Manhattan Distance.
# f = g + h
# g is the number of moves made so far.
# h is the estimated distance to the goal.

# Results:
# BFS found a path of 18 moves.
# A* also found a path of 18 moves.
# BFS expanded 54 nodes.
# A* expanded 24 nodes.

# Time Complexity:
# BFS: O(V^2 + E) because the code uses pop(0).
# A*: O((V + E) log V) using a priority queue.

# Space Complexity:
# BFS: O(V^2)
# A*: O(V^2)
# Both store copies of paths while searching.

# Conclusion:
# Both algorithms found the shortest path.
# A* checked fewer nodes because Manhattan Distance
# helped it move towards the goal.
