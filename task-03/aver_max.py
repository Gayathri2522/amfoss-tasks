x = int(input())
for i in range(x):
    n,k = map(int, input().split())
    l = [float(i) for i in input().split()]
    l.sort()
    if k != 0:
        #if sign changes are allowed, it is the maximum of absolute(first) or absolute(last) element
        print(max(abs(l[0]),abs(l[-1])))
    else:
        print(l[-1])