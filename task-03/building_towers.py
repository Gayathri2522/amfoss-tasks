n =input() 
#taking multiple input in same line 
list1 = input().split()

#number of maximum repititions 
def tallest_tower(list1):
    count2 = 0
    for i in list1:
        frequency = list1.count(i)
        if(frequency> count2):
            count2 = frequency
    return count2
print(tallest_tower(list1),end=" ")
#number of unique elements
list2 = []
count = 0
for item in list1:
    if item not in list2:
        count += 1
    list2.append(item)
print(count)
