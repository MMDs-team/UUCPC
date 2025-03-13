from collections import deque
from math import ceil
from random import randint

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


def generate_inputs(
    first_tc_no,
    last_tc_no,
    n_lower,
    n_upper,
    m_lower,
    m_upper,
):
    global gr
    gr = []

    for i in range(first_tc_no, last_tc_no + 1):
        with open(f"./in/input{i}.txt", 'w') as file:
            n = randint(n_lower, n_upper)
            m = randint(m_lower, min(
                    int(ceil(1 * (n * (n - 1)) / 2)), 
                    m_upper
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

                edges.add((cmp1[idx1] + 1, cmp2[idx2] + 1))
                m += 1

            file.write(f"{n} {m}\n")
            for node1, node2 in edges: file.write(f"{node1} {node2}\n")


def main():
    generate_inputs(
        first_tc_no = 1,
        last_tc_no = 4,
        n_lower = 2,
        n_upper = int(0.8 * N_UPPER),
        m_lower = 1,
        m_upper = int(0.8 * M_UPPER)
    )

    generate_inputs(
        first_tc_no = 5,
        last_tc_no = 8,
        n_lower = int(0.8 * N_UPPER),
        n_upper = N_UPPER,
        m_lower = int(0.8 * M_UPPER),
        m_upper = M_UPPER
    )

    generate_inputs(
        first_tc_no = 9,
        last_tc_no = 14,
        n_lower = N_UPPER,
        n_upper = N_UPPER,
        m_lower = M_UPPER - 1,
        m_upper = M_UPPER - 1
    )


if __name__ == "__main__": main()

