input_string = open("./input_file_3.txt").read()
input_string = input_string.split("\n")

line_1 = list(map(int,input_string[0].split()))
line_2 = list(map(int, input_string[1].split(" ")))
# line_1 = list(map(int, input().split()))
# line_2 = list(map(int, input().split(" ")))
# print(line_1, line_2)
amount = line_1[1]
pos = amount - 1
top_k = line_2[pos]
pos += 1

while pos < line_1[0]: 
    if line_2[pos] == top_k and line_2[pos] != 0:
        pos += 1
        amount += 1
    else:
        break

while pos > 0: 
    if line_2[pos] == top_k and line_2[pos] == 0:
        pos -= 1
        amount -= 1
    else:
        break

print(amount)




