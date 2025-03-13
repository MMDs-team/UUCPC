from random import randint

first_tc_file = 6
last_tc_file = 20 
t_upper = int(2e2)
n_upper = int(1e4)
a_upper = int(1e3)

for i in range(first_tc_file, last_tc_file + 1):
    with open(f"./in/input{i}.txt", 'w') as file:
        t = randint(1, t_upper)
        file.write(f"{t}\n")
        for tt in range(1, t + 1):
            n = randint(5, n_upper)
            file.write(f"{n}\n")
            for nn in range(1, n + 1):
                j = randint(-1 * a_upper, a_upper)
                file.write(f"{j} ")
            file.write("\n")

    print(f"I/O generation completed for file{i}")
