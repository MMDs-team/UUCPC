from random import randint

first_tc_file = 1
last_tc_file = 5

for i in range(first_tc_file, last_tc_file + 1):
    with open(f"./in/input{i}.txt", 'w') as file:
        sum_n = 200000 if i != 1 else 5
        tc = randint(1, 20) if i != 1 else 1
        file.write(f"{tc}\n")
        smn = smq = 0

        for tcn in range(tc):
            n = randint(3, sum_n - 3*(tc - tcn)) if i != 1 else 5
            if tcn == tc - 1: n = sum_n
            sum_n -= n
            smn += n
            if smn > 200000 : print("The sum of n is not less than 200000.")
            file.write(f"{n}\n")

            nums = []
            last = 1
            for _ in range(n):
                x = last if randint(1, 20) < 19 else randint(1, 10**6)
                if i == 1: 
                    x = last if randint(1, 20) < 14 else randint(1, 10)
                    
                last = x
                file.write(f"{x} ")
            file.write("\n")

            q = randint(1, 2*10**5 // tc) if i != 1 else 10
            smq += q
            if smq > 200000 : print("The sum of q is not less than 200000.")
            file.write(f"{q}\n")

            for _ in range(q):
                l = randint(1, n - 1)
                r = randint(l + 1, n)
                file.write(f"{l} {r}\n")

    print(f"I/O generation completed for file{i}")
