def concat_numbers(num_list):
    return int(''.join(num_list))

# Example
nums = input("Enter single digit numbers (space separated): ").split()
print("Concatenated number:", concat_numbers(nums))
