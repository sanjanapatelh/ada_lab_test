median=0
i=0
j=0
def find_median(a,n,b,m):
    global median,i,j
    min_index=0
    max_index=n
    while min_index<=max_index:
        i=int((min_index+max_index)/2)
        j=int(((n+m+1)/2)-i)
        if i<n and j>0 and b[j-1]>a[i]:
            min_index=i
        elif i>0 and j<m and b[j]<a[i-1]:
            min_index=i-1
        else:
            if i==0:
                median=b[j-1]
            elif j==0:
                median=a[i-1]
            else:
                median=max(a[i-1],b[j-1])
            break
    if (n+m)%2==1:
        return median
    if i==n:
        return ((median+b[j])/2)
    if j==m:
        return ((median+a[i])/2.0)
    return ((median+min(a[i],b[j]))/2.0)
a=[900]
b=[10,13,14]
n=len(a)
m=len(b)

if(n<m):
    print(find_median(a,n,b,m))
else:
    print(find_median(b,m,a,n))
