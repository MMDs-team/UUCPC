from random import randint

FIRST_TC_FILE = 1
LAST_TC_FILE = 10
N_UPPER = int(1e5)

for i in range(FIRST_TC_FILE, LAST_TC_FILE + 1):
    with open(f"./in/input{i}.txt", 'w') as file:
        n = randint(1, int(0.8 * N_UPPER))
        i = randint(1, 2 * n)
        j = randint(1, 2 * n)
        file.write(f"{n} {i} {j}\n")
