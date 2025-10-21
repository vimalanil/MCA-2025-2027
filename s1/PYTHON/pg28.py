def add_is(s):
    if s.startswith("Is"):
        return s
    return "Is" + s

# Example
s = input("Enter a string: ")
print("Result:", add_is(s))
