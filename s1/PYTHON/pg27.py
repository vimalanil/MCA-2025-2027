def count_odd_even(lst):
    even = odd = 0
    for n in lst:
        if int(n) % 2 == 0:
            even += 1
        else:
            odd += 1
    return even, odd

# Example
nums = input("Enter numbers: ").split()
even, odd = count_odd_even(nums)
print("Even:", even, "Odd:", odd)
