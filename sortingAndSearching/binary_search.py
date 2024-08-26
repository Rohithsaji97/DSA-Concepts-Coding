n = int(input('Enter the length of the array '))
arr = []

print('Enter the elemennts in the array')
for i in range (n):
    q = int(input())
    arr.append(q)
    
Flag = False
key = int(input('Enter the required element to be searched '))
    
left = 0
right = n-1

while (left <= right):
    mid = left +(right-left)//2
    
    if arr[mid] == key:
        Flag = True
        break
    
    if arr[mid] > key:
        right = mid - 1
    else:
        left = mid + 1
        
if Flag:
    print(arr[mid],' is in ',mid + 1, ' position')

if not Flag:
    print('Element not found')