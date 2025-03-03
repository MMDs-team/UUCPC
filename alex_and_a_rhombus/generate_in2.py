from random import randint

first_tc_file = 6
last_tc_file = 20 
n_upper = int(1e3)

for i in range(first_tc_file, last_tc_file + 1):
    with open(f"./in/input{i}.txt", 'w') as file:
        n = randint(1, n_upper)
        file.write(f"{n}\n")
    print(f"I/O generation completed for file{i}")
