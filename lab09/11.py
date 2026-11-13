def toint(fun):
    def wrapper(*args):
        return fun(*map(int, args))
    return wrapper


def add(a, b):
    return a + b


print(add('2', '3'))              # 23, строки просто склеились
add_int = toint(add)
print(add_int('2', '3'))          # 5

print(max('5', '12', '7'))        # 7, строки сравниваются по символам
print(toint(max)('5', '12', '7')) # 12

print(toint(pow)('2', '10'))      # 1024
