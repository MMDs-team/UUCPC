from random import randint

first_tc_file = 6
last_tc_file = 20 
n_upper = int(1e5)
w_upper = int(1e3)
pi_upper = int(1e3)
wi_upper = int(1e2)

for i in range(first_tc_file, last_tc_file + 1):
    with open(f"./in/input{i}.txt", 'w') as file:
        n = randint(1, n_upper)
        w = randint(1, w_upper)
        file.write(f"{n} {w}\n")
        for ii in range(1, n + 1):
            pi = randint(1, pi_upper)
            wi = randint(1, wi_upper)
            file.write(f"{pi} {wi}\n")
    print(f"I/O generation completed for file{i}")
