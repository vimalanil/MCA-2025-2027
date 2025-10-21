# Wap to
# (a) print out all colors from color-list 1 not containing in colour list 2.
clr1 = input("Enter color list 1 (comma separated): ").split(",")
clr2 = input("Enter color list 2 (comma separated): ").split(",")
diff = [x for x in clr1 if x not in clr2]

print("Colors in list 1 but not in list 2:", diff)

# (b) Write a program to remove duplicates from list
s=list(map(int,input("Enter numbers: ").split(",")))
print(set(s))
# (c) Write a program to check whether a list is empty or not.
lst = input("Enter list elements (press Enter for empty list): ").split(",")

if lst == [''] or len(lst) == 0:
    print("The list is empty.")
else:
    print("The list is not empty.")

