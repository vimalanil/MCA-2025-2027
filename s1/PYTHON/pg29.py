# (a)
largest = lambda a, b: a if a > b else b
print("Largest:", largest(10, 20))

# (b)
divisible_by_5 = lambda x: x % 5 == 0
print("Divisible by 5:", divisible_by_5(25))

# (c)
remove_short = lambda lst: [s for s in lst if len(s) >= 5]
print("Filtered list:", remove_short(["apple", "bat", "mango", "hi"]))

# (d)
increment = lambda lst: [x * 1.10 if x > 1000 else x * 1.05 for x in lst]
print("Incremented list:", increment([500, 1200, 3000]))
