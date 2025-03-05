from random import randint

first_tc_file = 6
last_tc_file = 10

cube = []

def dfs(x, y, z, r):
    if x < 0 or y < 0 or z < 0 or x == len(cube) or y == len(cube) or z == len(cube): return
    if cube[x][y][z] >= r: return

    cube[x][y][z] = r

    dfs(x + 1, y, z, r - 1)
    dfs(x - 1, y, z, r - 1)
    dfs(x, y + 1, z, r - 1)
    dfs(x, y - 1, z, r - 1)
    dfs(x, y, z + 1, r - 1)
    dfs(x, y, z - 1, r - 1)
    




for i in range(first_tc_file, last_tc_file + 1):
    with open(f"./in/input{i}.txt", 'w') as file:
        a = randint(40, 50)
        file.write(f"{a}\n")
        cube = [[[0 for _ in range(a)] for _ in range(a)] for _ in range(a)]

        cnt = randint(20, max(23, a*a//2))
        for _ in range(cnt):
            x = randint(0, a)
            y = randint(0, a)
            z = randint(0, a)
            r = randint(1, max(3, a//10))

            dfs(x, y, z, r)
        for layer in cube:
            for line in layer:
                for point in line:
                    file.write(f"{'.'if point == 0 else 'X'}")
                file.write('\n')

    print(f"I/O generation completed for file{i}")
