from random import randint

first_tc_file = 1
last_tc_file = 5

for i in range(first_tc_file, last_tc_file + 1):
    with open(f"./in/input{i}.txt", 'w') as file:
        A = randint(1, 3)
        B = 0
        while B == 0 or B == A: B = randint(1, 3)
        file.write(f'{A} {B}\n')


    print(f"I/O generation completed for file{i}")
