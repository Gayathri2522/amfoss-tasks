n,m = map(int, input().split())
developers = list(map(int, input().split()))
problem_solvers = list(map(int, input().split()))
developers.sort()
problem_solvers.sort()
minimum = 0
i = 0
for j in range(0, m):
    if(developers[i]<problem_solvers[j]):
        i +=1
        minimum += problem_solvers[j]
        if(i==n):
            break
if (i==n):
    print("YES")
    print(minimum)
else:
    print("NO")