from random import randint

first_tc_file = 6
last_tc_file = 10


for i in range(first_tc_file, last_tc_file + 1):
    with open(f"./in/input{i}.txt", 'w') as file:
        with open(f"./realout/out{i}.txt", 'w') as out:
            n = randint(10*4, 10**6)
            file.write(f"{n}")

            while True:
                out.write(f"{n}\n")

                if n == 1: break
                if n > 10**12: print("Large number.........")

                if n % 2 == 0:
                    n //= 2
                else:
                    n *= 3
                    n += 1
            
            out.write("1\n")

    print(f"I/O generation completed for file{i}")
