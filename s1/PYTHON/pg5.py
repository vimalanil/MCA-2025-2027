# Write a program to check if a given key already exist in a dictionary 
dict1 = {1:1,2:4,3:9,4:16}
print(dict1)
k = int(input("Enter the key: "))
print("Key already exist: ",k in dict1.keys())
# Write python prgram to merge two dictionaries
d1 = {1:1,2:4,3:9,4:16}
d2 = {1:1,3:9,5:25}
print(d1,"\n",d2)
d1.update(d2)
print("new:",d1)
# Write a program to sort a dictionaries in ascending and descending order
dic1 = {9:81,3:9,7:49,4:16}
print(dic1)
print("ascending: ",dict(sorted(dic1.items())))
print("descending: ",dict(sorted(dic1.items(), reverse=True)))
# Write a program to create an inverted dictionary
dic1 = {1:1,2:2,3:1,4:2,5:1}
print(dic1)
print({v:k for k, v in dic1.items()})