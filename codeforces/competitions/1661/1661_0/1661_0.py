input_string = open("./data_1").read().split("\n")
sets_amount = int(input_string[0])
input_string.pop(0)

for i in range(sets_amount):
    array_1 = list(map(int, input_string[i*3+1].split()))
    array_2 = list(map(int, input_string[i*3+2].split()))
    
    # array_dif_1 = []
    # array_dif_2 = []

    array_sum = []

    for k in range(len(array_1)-1):
        num_1 = abs(array_1[k] - array_1[k+1])
        num_2 = abs(array_2[k] - array_2[k+1])
        array_sum.append(num_1+num_2)

    print(array_sum)
            

    min_sum = sum([abs(array_1[j] - array_1[j+1]) + abs(array_2[j] - array_2[j+1]) for j in range(len(array_1)-1)])
    # print(min_sum)