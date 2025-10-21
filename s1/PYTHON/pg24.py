def even_until_237(lst):
    for n in lst:
        n = int(n)
        if n == 237:
            break
        if n % 2 == 0:
            print(n, end=" ")

# Example
nums = input("Enter numbers: ").split()
even_until_237(nums)
