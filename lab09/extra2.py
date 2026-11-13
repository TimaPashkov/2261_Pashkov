words = ['pear', 'apple', 'banana', 'cherry', 'fig', 'banane']
print(min(words, key=lambda w: (-len(w), w)))
