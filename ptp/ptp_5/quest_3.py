with open("data3.txt", "r") as f:
    data = [float(line) for line in f]

ERR = 0.1
data1=data[:int(len(data)/2)]
data2=data[int(len(data)/2):]
data2.reverse()
is_depend = False
for i in range(len(data1)):
    if abs(data1[i] - data2[i]) > ERR:
        is_depend = True
        break

if is_depend == False:
    print(1)
else:
    print(0)
