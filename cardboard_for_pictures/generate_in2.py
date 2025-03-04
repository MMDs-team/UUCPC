from random import randint
from math import sqrt

first_tc_file = 6
last_tc_file = 10

for i in range(first_tc_file, last_tc_file + 1):
    with open(f"./in/input{i}.txt", 'w') as file:
        with open(f"./realout/output{i}.txt", 'w') as real_out:

            sum_n = 200000
            tc = randint(1, 3)
            file.write(f"{tc}\n")

            for tcn in range(tc):
                n = 0
                smn = 0
                
                n = randint(1, sum_n - (tc - tcn))
                if tcn == tc - 1: n = sum_n
                sum_n -= n
                smn += n
                if smn > 200000 : print("The sum of n is not less than 200000.")

                nums = []
                value = int(sqrt(10**18 // n))
                w = randint(1, value)    
                real_out.write(f"{w}\n")
                c = 0
                for _ in range(n):
                    x = randint(max(1, min(10**4, value) // 20), min(10**4, value))
                    nums.append(x)

                    c += (x + 2*w )**2


                
                file.write(f"{n} {c}\n")

                for num in nums:
                    file.write(f"{num} ")
                file.write("\n")

    print(f"I/O generation completed for file{i}")
