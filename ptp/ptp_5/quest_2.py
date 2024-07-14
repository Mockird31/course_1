STEP = 10e-5
DIFF = 0.1

with open("data2.txt", "r") as f:
    data = list()
    for line in f:
        line = line.split()
        data.append([float(line[0]), float(line[1]), float(line[2])])


def f(x, y, a, b, c):
    return a*x + b*y + c


def error_func(a, b, c, data):
    sumi = 0
    for line in data:
        sumi += abs(f(line[0], line[1], a, b, c) - line[2])
    return sumi


def find_coef(data):
    aa, bb, cc = 0, 0, 0
    while (error_func(aa, bb, cc, data) > error_func(aa + STEP, bb, cc, data)) or (error_func(aa, bb, cc, data) > error_func(aa - STEP, bb, cc, data)) or \
            (error_func(aa, bb, cc, data) > error_func(aa, bb + STEP, cc, data)) or (error_func(aa, bb, cc, data) > error_func(aa, bb - STEP, cc, data)) or \
            (error_func(aa, bb, cc, data) > error_func(aa, bb, cc + STEP, data)) or (error_func(aa, bb, cc, data) > error_func(aa, bb, cc - STEP, data)):
        if (error_func(aa, bb, cc, data) > error_func(aa + STEP, bb, cc, data)):
            aa += STEP
        if (error_func(aa, bb, cc, data) > error_func(aa - STEP, bb, cc, data)):
            aa -= STEP
        if (error_func(aa, bb, cc, data) > error_func(aa, bb + STEP, cc, data)):
            bb += STEP
        if (error_func(aa, bb, cc, data) > error_func(aa, bb - STEP, cc, data)):
            bb -= STEP
        if (error_func(aa, bb, cc, data) > error_func(aa, bb, cc + STEP, data)):
            cc += STEP
        if (error_func(aa, bb, cc, data) > error_func(aa, bb, cc - STEP, data)):
            cc -= STEP
    return aa, bb, cc 

coefs = find_coef(data)
for line in data:
    if coefs[0]*line[0] + coefs[1]*line[1] + coefs[2] - line[2] > DIFF:
        print(0)
        break 
else:
    print(1)