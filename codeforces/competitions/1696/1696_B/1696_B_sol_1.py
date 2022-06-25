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

            min_nums["pos"].append(j)
            min_nums["value"].append(0)
            min_value = int(max_value)
            min_value_pos = -1
        else:
            if min_value > num:
                min_value = num
                min_value_pos = j
    # print(min_nums)
    if all_zeros:
        print(0)
    elif zeros_amount >= 0 and zeros_amount <= 1:
        print(1)
    else:
        set_nums = set(min_nums["value"])
        trials = len(set_nums) - 1
        print(trials)
