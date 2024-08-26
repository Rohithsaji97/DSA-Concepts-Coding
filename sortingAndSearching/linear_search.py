n = int(input('Enter the length of the array '))
arr = []

print('Enter the elemennts in the array')
for i in range (n):
    q = int(input())
    arr.append(q)
    
Flag = False
key = int(input('Enter the required element to be searched '))

for i in arr:
    if i == key:
        Flag = True
        index = arr.index(i)
        break

if Flag:
    print(arr[index],' is in ',index + 1, ' position')

if not Flag:
    print('Element not found')