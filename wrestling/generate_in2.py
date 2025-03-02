from random import randint

FIRST_TC_FILE = 11
LAST_TC_FILE = 20
N_UPPER = 18
P_UPPER = int(1e9)

for i in range(FIRST_TC_FILE, LAST_TC_FILE + 1):
    with open(f"./in/input{i}.txt", 'w') as file:
        n = randint(int(0.8 * N_UPPER), N_UPPER)
        k = randint(1, n)
        file.write(f"{n} {k}\n")

        for _ in range(1 << n): file.write(f"{randint(1, P_UPPER)} ")
        file.write("\n")
