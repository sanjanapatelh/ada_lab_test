def quicksort(a,low,high):
    if low<high:
        pivot=partition(a,low,high)
        quicksort(a,low,pivot)
        quicksort(a,pivot+1,high)
def partition(a,low,high):
    pivot=a[low]
    i=low+1
    j=high
    while 1:
        while  i<=high and a[i]<=pivot:
            i+=1
        while  j>=low and a[j]>pivot :
            j-=1
        if i<j:
            temp=a[i]
            a[i]=a[j]
            a[j]=temp
        else:
            a[low]=a[j]
            a[j]=pivot
            return j
a=[3,2,5,1,8,9]
start=1-1
end=6-1
k=4
quicksort(a,start,end)
print(a)
print(a[start+k-1])
    
