"""
UNSOLVED

общее решение это нахождение количества секторов разделенных нулями
типа 0 1 2 3  323  43 0 2342 1234  4324 23  0 234  124  523 4
тут секторов 3
если мы заменим 2 нуля на 1, мы потратим 2 попытки на замену 2 нулей в перегородках
а потом просто занулим общий кусок

я тут подумал что это равноценно тому что мы занулим все сектора по отдельности

если совсем нет нулей, это можно сделать за 1 проход
"""

t = int(input())
for i in range(t):
    n = input()
    array = list(map(int, input().split()))
    # print(array)
    all_zeros = True
    trials = 0

    min_nums = {"pos": [], "value": []}
    max_value = 10**9
    min_value = int(max_value)
    min_value_pos = -1
    zeros_amount = 0
    for j, num in enumerate(array):
        if num != 0:
            all_zeros = False

        if num == 0:
            zeros_amount += 1
            if min_value_pos > -1 and min_value != max_value:
                min_nums["pos"].append(min_value_pos)
                min_nums["value"].append(min_value)

            # min_nums["pos"].append(j)
            # min_nums["value"].append(0)
            min_value = int(max_value)
            min_value_pos = -1
        else:
            if min_value > num:
                min_value = num
                min_value_pos = j
    # print(min_nums)
    if zeros_amount > 1:
        trials = len(min_nums["value"])
    if all_zeros:
        print(0)
    elif zeros_amount >= 0 and zeros_amount <= 1:
        print(1)
    else:
        print(trials)
