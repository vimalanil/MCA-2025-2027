# Wap to
# (a) Create a single string separated with space from two string by swapping the character at position 1.
s1 = input("Enter string 1: ")
s2 = input("Enter string 2: ")

new_string = s2[0] + s1[1:] + " " + s1[0] + s2[1:]

print("New string:", new_string)


# (b) Create a list of colours from comma separated list of colour names entered by user.Print alternate colours.

colors = input("Enter colours separated by commas: ")

color_list = colors.split(",")

print("Alternate colours are:", color_list[::2])
