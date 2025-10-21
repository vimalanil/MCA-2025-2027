# Compare two list
list1 = list(map(int,input("Enter first list: ").split()))
list2 = list(map(int,input("Enter second list: ").split()))

if list1 == list2:
    print("Both list are equal")
else:
    print("Both are not equal")