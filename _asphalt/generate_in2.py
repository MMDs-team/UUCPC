from random import randint

FIRST_TC_FILE = 11
LAST_TC_FILE = 20
N_UPPER = int(1e5)
M_UPPER = int(1e6)

for i in range(FIRST_TC_FILE, LAST_TC_FILE + 1):
    with open(f"./in/input{i}.txt", 'w') as file:
        n = randint(1, int(0.8 * N_UPPER))
        m = randint(int(0.8 * M_UPPER), M_UPPER)
        file.write(f"{n} {m}\n")

        for _ in range(m):
            node1, node2 = randint(1, n), randint(1, n)
            while node1 == node2: node1, node2 = randint(1, n), randint(1, n)

            file.write(f"{node1} {node2}\n")