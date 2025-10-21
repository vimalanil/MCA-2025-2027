def search_item(lst, item):
    return lst.count(item)

# Example
lst = input("Enter list elements: ").split()
item = input("Enter item to search: ")
print("Occurrences:", search_item(lst, item))
