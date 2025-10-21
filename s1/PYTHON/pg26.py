def count_same_ends(lst):
    count = 0
    for s in lst:
        if len(s) >= 2 and s[0] == s[-1]:
            count += 1
    return count

# Example
lst = input("Enter strings: ").split()
print("Count:", count_same_ends(lst))
