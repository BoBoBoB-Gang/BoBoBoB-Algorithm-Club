r, c, k = map(int, input().split(' '))
a = [list(map(int, input().split(' '))) for _ in range(3)]

time = 0


def r_solve(row, col):
    max_len = 0
    for i in range(row):
        number_dict = dict()
        while a[i]:
            a_value = a[i].pop()
            if a_value == 0:
                continue
            if a_value in number_dict:
                number_dict[a_value] += 1
            else:
                number_dict[a_value] = 1

        sort_dict = sorted(number_dict.items(), key=lambda x: (-x[1], -x[0]))
        while sort_dict:
            a_value, a_count = sort_dict.pop()
            a[i].append(a_value)
            a[i].append(a_count)

        max_len = max(max_len, len(a[i]))

    for i in range(row):
        row_len = len(a[i])
        while row_len != max_len:
            a[i].append(0)
            row_len += 1


def c_solce(row, col):
    global a
    max_len = 0
    new_a = [list() for _ in range(col)]

    for j in range(col):
        number_dict = dict()
        for i in range(row):
            if a[i][j] == 0:
                continue
            else:
                if a[i][j] in number_dict:
                    number_dict[a[i][j]] += 1
                else:
                    number_dict[a[i][j]] = 1
        sort_dict = sorted(number_dict.items(), key=lambda x: (-x[1], -x[0]))
        while sort_dict:
            a_value, a_count = sort_dict.pop()
            new_a[j].append(a_value)
            new_a[j].append(a_count)

        max_len = max(max_len, len(new_a[j]))

    for i in range(col):
        row_len = len(new_a[i])
        while row_len != max_len:
            new_a[i].append(0)
            row_len += 1

    a = [[0] * len(new_a) for _ in range(len(new_a[0]))]

    for i in range(len(new_a)):
        for j in range(len(new_a[0])):
            a[j][i] = new_a[i][j]


def solve():
    global time, a
    while True:
        if time > 100:
            break
        if len(a) >= r and len(a[0]) >= c:
            if a[r-1][c-1] == k:
                break
        row = len(a)
        col = len(a[0])

        if row >= col:
            r_solve(row, col)
        else:
            c_solce(row, col)

        if len(a) > 100:
            a = a[:100]

        if len(a[0]) > 100:
            for i in range(len(a)):
                a[i] = a[i][:100]

        time += 1


solve()
if time > 100:
    print(-1)
else:
    print(time)

