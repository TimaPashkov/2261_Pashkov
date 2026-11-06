lst = ['hello', 'hell', 'bye', 'world', 'bybye']
lst.sort(key=lambda w: (len(w), w))
print(lst)