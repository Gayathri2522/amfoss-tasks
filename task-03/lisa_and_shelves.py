x=int(input())
y=0
for i in range(1,int(x**(0.5))+1):
  if x%i==0  :
    if x/i==i:
      y+=1
    else:
      y+=2
print(y)