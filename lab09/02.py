def sublist(lst, *positions):
    result = []
    for i in positions:
        result.append(lst[i])
    return result


lst = ['Anna', 'Barbara', 'Clara', 'Diana', 'Eva', 'Flora']
print(sublist(lst, 0, 2, 5))
print(sublist(lst))
print(sublist(lst, 0, 1, 2, 3, 4, 5))
