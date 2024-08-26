n = int(input('Enter the length of the array '))
arr = []

print('Enter the elemennts in the array')
for i in range (n):
    q = int(input())
    arr.append(q)
    
for i in range (n-1):
    min = i
    for j in range (i+1,n):
        if arr[j] < arr[min]:
            min = j
    temp = arr[i]
    arr[i] = arr[min]
    arr[min] = temp

print(arr)