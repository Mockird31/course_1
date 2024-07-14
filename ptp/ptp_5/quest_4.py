import math as m

with open("data4.txt", "r") as f:
    data = [float(line) for line in f]

print(m.ceil(min(data)), int(max(data)))