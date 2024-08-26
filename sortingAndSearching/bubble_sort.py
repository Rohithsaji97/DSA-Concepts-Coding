n = int(input('Enter the length of the array '))
arr = []

print('Enter the elemennts in the array')
for i in range (n):
    q = int(input())
    arr.append(q)

for i in range (n-1):
    for j in range (n-i-1):
        if arr[j] > arr[j+1]:
            temp = arr[j]
            arr[j] = arr[j+1]
            arr[j+1] = temp

print(arr)