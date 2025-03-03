from collections import deque
from math import ceil
from random import randint

FIRST_TC_FILE = 11
LAST_TC_FILE = 20
N_UPPER = int(1e5)
M_UPPER = int(1e6)

gr = []
def get_comp(curr):
    global gr
    vis = [False] * len(gr)
    result = []

    queue = deque([curr])
    vis[curr] = True

    while queue:
        node = queue.popleft()
        result.append(node)

        for neighbor in gr[node]:
            if not vis[neighbor]:
                vis[neighbor] = True
                queue.append(neighbor)

    return result


for i in range(FIRST_TC_FILE, LAST_TC_FILE + 1):
    with open(f"./in/input{i}.txt", 'w') as file:
        n = randint(int(0.8 * N_UPPER), N_UPPER)
        m = randint(1, min(
                int(ceil(1 * (n * (n - 1)) / 2)), 
                int(0.8 * M_UPPER)
            ))
        gr = [list() for _ in range(n)]

        edges = set()
        while len(edges) != m:
            node1, node2 = randint(1, n), randint(1, n)
            while node1 == node2: node1, node2 = randint(1, n), randint(1, n)
            if (node1, node2) not in edges and \
                (node2, node1) not in edges: 
                edges.add((node1, node2))

        for node1, node2 in edges: 
            gr[node1 - 1].append(node2 - 1)
            gr[node2 - 1].append(node1 - 1)

        cmp1 = get_comp(0)
        if cmp1.count(n - 1) == 0:
            cmp2 = get_comp(n - 1)

            idx1 = randint(0, len(cmp1) - 1)
            idx2 = randint(0, len(cmp2) - 1)

            edges.add((cmp1[idx1], cmp2[idx2]))
            m += 1

        file.write(f"{n} {m}\n")
        for node1, node2 in edges: file.write(f"{node1} {node2}\n")