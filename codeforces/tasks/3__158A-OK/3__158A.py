# input_string = open("./input_file_1.txt").read()
# input_string = """5 5
# 3 2 1 0 0
# """
# input_string = input_string.split("\n")

# line_1 = list(map(int, input_string[0].split()))
# line_2 = list(map(int, input_string[1].split(" ")))
line_1 = list(map(int, input().split()))
line_2 = list(map(int, input().split(" ")))
# print(line_1, line_2)
answer = line_1[1]
pos_answer = answer - 1

if line_2[pos_answer] == 0:
    answer -= 1
    pos = pos_answer - 1
    while pos >= 0:
        if line_2[pos] != 0:
            break
        answer -= 1
        pos -= 1
else:
    pos = pos_answer + 1
    while pos < len(line_2):
        if line_2[pos] < line_2[pos_answer]:
            break
        pos += 1
        answer += 1

print(answer)
