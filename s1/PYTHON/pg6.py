# Write a python function that takes a list and returns a new list with unique elements.
# list = input("Enter numbers: ").split()
# print("Unique elements: ",set(list))

def unique_list(lst):
    return list(set(lst))

numbers = input("Enter numbers: ").split()
print("Unique elements:", unique_list(numbers))
