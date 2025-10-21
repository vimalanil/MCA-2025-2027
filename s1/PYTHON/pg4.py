# Enter 2 collections of integers check
# whether they are of the same length
# whether they sum to the same value
# whether any value occur in both

c1 = list(map(int,input("Enter numbers: ").split(",")))
c2 = list(map(int,input("Enter numbers: ").split(",")))
print("length is same: ",len(c1)==len(c2))
print("sum is same: ",sum(c1)==sum(c2))
print("value occur in both: ",[x for x in c1  if x in c2])