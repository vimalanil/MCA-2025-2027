# Wap to
# (a) Determine frequency of alphabets in a word.
word = input("Enter a word: ").lower()
freq = {}

for i in word:
    freq[i] = freq.get(i, 0) + 1

print("Frequency of each character in", word, "=", freq)

# (b) Create a list of first names.Count no of names that starts with 'a'
names = input("Enter a set of names: ").lower().split()
count = len([i for i in names if i.startswith('a')])
print("No of names starting with 'a':", count)
print("Total no of names:", len(names))
# (c) Each word in a line of text.

line = input("Enter a line of text: ")
words = line.split()
print("Words in the line:")
for w in words:
    print(w)
