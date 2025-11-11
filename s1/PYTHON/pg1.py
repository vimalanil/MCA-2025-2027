s = input("Enter a string")
ch = s[0]
new_s = s[0]+s[1:].replace(ch,"$")
print("new string ",new_s)

# (b) Create a string from given string where first and last characters exchanged.
exchanged = s[-1] + s[1:-1] + s[0]
print("String with first and last charaters exchanged:", exchanged)
