from copy import deepcopy

a = [[1,2,3],[4,5,6]]

b = deepcopy(a)

b[0][1] = 10


a = b

b[0][2] = 20


print(a, b)