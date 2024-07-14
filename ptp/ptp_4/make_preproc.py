import math as m
import statistics as stat
import os


def find_quartile(data, p):
    n = len(data)
    k = (n + 1) * p
    if k % 1 == 0:
        return data[int(k) - 1]
    else:
        lower = data[int(k) - 1]
        upper = data[int(k)]
        return lower + (upper - lower) * (k % 1)


with open('config.txt') as config:
    names = config.readline().split()
    sizes = config.readline().split()

def calculate_rse(data):
    if sum(data) == 0:
        return 0
    aver = stat.mean(data)
    sumi = 0
    rse = 100
    for i in data:
        sumi += ((i - aver) * (i - aver))
    sumi /= (len(data) - 1)
    sumi = m.sqrt(sumi)
    stderr = sumi/m.sqrt(int(len(data)))
    if aver > 0:
        rse = stderr/aver * 100
    return rse


if os.path.exists("preproc_data"):
    os.system("rm -rf preproc_data")
os.system("mkdir preproc_data")


for name in names:
    for size in sizes:
        count = 3
        data = [int(i) for i in open(f"./data_set/{name}_{size}.txt").readlines()]
        while True:
            rse = calculate_rse(data)
            if rse <= 1:
                break
            os.system("./update_data.sh 1")
            count += 1
            data = [int(i) for i in open(f"./data_set/{name}_{size}.txt").readlines()]
        with open(f'./preproc_data/{name}_{size}.txt', "w") as out:
            out.write(f'{stat.mean(data)} ')  # average 0
            out.write(f'{stat.median(data)} ')  # mediana 1
            out.write(f'{max(data)} ')  #maximum 2
            out.write(f'{min(data)} ')  #minimum 3
            out.write(f'{find_quartile(data, 0.25)} ')  #first_quart 4
            out.write(f'{find_quartile(data, 0.75)} ')  #third_quart 5
            out.write(f'{calculate_rse(data)} ')  #rse
            out.write(f'{count} ')  #number of launches
            
