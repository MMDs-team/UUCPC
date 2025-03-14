length, weight = list(map(int, input().split()))

arr = []

for i in range(length):
    val, we = list(map(int, input().split()))
    arr.append([val, we])

arr.sort(key=lambda x: x[0]/x[1], reverse=True)

maxi = 0

for i in range(length):
    if arr[i][1] <= weight:
        weight -= arr[i][1]
        maxi += arr[i][0]
    else:
        maxi += arr[i][0] / arr[i][1] * weight
        weight = 0
        break
    
print("{:.2f}".format(maxi)) 