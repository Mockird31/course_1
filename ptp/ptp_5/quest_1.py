import statistics as stat

# DEPEND OR NOT
ERR = 0.01
with open("data1.txt", "r") as f:
    data = [float(line) for line in f]

aver = stat.mean(data)
is_depend = False
for i in data:
    if abs(i - aver) > ERR:
        is_depend = True
        break

if is_depend == True:
    print(0)
else:
    print(1)
