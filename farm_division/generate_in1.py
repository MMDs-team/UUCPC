from random import randint

FIRST_TC_FILE = 1
LAST_TC_FILE = 10
N_UPPER = M_UPPER = int(1e9)

for i in range(FIRST_TC_FILE, LAST_TC_FILE + 1):
    with open(f"./in/input{i}.txt", 'w') as file:
        n = randint(1, int(0.8 * N_UPPER))
        m = randint(1, int(0.8 * M_UPPER))
        file.write(f"{n} {m}\n")
