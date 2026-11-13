def toint(fun):
    def wrapper(*args):
        return fun(*map(int, args))
    return wrapper


@toint
def add(a, b):
    return a + b


@toint
def total(*nums):
    return sum(nums)


@toint
def average(a, b, c):
    return (a + b + c) / 3


@toint
def biggest(*nums):
    return max(nums)


print(add('2', '3'))              # 5
print(total('1', '2', '3', '4'))  # 10
print(average('3', '4', '8'))     # 5.0
print(biggest('5', '12', '7'))    # 12
