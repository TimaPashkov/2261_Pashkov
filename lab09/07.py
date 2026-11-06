def every_other(seq):
    it = iter(seq)
    e = next(it, None)
    while e!=None:
        yield e
        next(it, None)
        e = next(it, None)


print(*every_other([10, 20, 30, 40, 50]))
print(*every_other(range(10)))
print(*every_other(iter(range(10))))
print(sum(every_other(map(int, input().split()))))
