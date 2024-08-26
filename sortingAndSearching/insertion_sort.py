n = int(input('Enter the length of the array '))
arr = []

print('Enter the elemennts in the array')
for i in range (n):
    q = int(input())
    arr.append(q)
    
for i in range (1,n):
    current = arr[i]
    j = i-1
    while (arr[j]>current and j >= 0):
        arr[j+1] = arr[j]
        j = j - 1
    arr[j+1] = current
    
print(arr)
        