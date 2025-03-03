from random import randint

first_tc_file = 1
last_tc_file = 5

n_upper = int(1e1)
k_upper = int(1e1)

for i in range(first_tc_file, last_tc_file + 1):
    with open(f"./in/input{i}.txt", 'w') as file:

        n = randint(1, n_upper)
        file.write(f"{n}\n")

        for kk in range(1, n + 1):
            k = randint(0, min(n - 1, k_upper))
            file.write(f"{k} ")
            
            rand_nums = set()
            while k:
                num = randint(1, n)
                if num != kk and num not in rand_nums:
                    rand_nums.add(num)
                    k -= 1

            for num in rand_nums: 
                file.write(f"{num} ")
            
            file.write("\n")

    print(f"I/O generation completed for file{i}")