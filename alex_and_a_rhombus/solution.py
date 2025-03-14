num = int(input())

sums = 1
plus = 4

for i in range(1, num):
    sums += plus
    plus += 4
    
print(sums)