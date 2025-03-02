from random import randint

FIRST_TC_FILE = 11
LAST_TC_FILE = 20
N_UPPER = int(1e5)

for i in range(FIRST_TC_FILE, LAST_TC_FILE + 1):
    with open(f"./in/input{i}.txt", 'w') as file:
        n = randint(int(0.8 * N_UPPER), N_UPPER)
        i = randint(1, 2 * n)
        j = randint(1, 2 * n)
        file.write(f"{n} {i} {j}\n")
