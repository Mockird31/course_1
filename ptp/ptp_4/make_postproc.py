import matplotlib.pyplot as plt
import collections as col
import os
import numpy as np
DPI = 1000

if os.path.exists("postproc_data"):
    os.system("rm -rf postproc_data")
os.system("mkdir postproc_data")

STYLES = [
    ('red', 'x'),
    ('blue', 'o'),
    ('green', 'v')
]


def get_boxplot(filename):
    data = list()
    with open(filename, 'r') as f:
        for line in f:
            line = line.split()
            data.append([float(line[0]), float(line[1]), float(line[2]), float(line[3]), float(line[4])])
    return data

def get_low_and_high(filename):
    low, high = [], []
    with open(filename, 'r') as f:
        for line in f:
            line = line.split()
            low.append(float(line[0]))
            high.append(float(line[1]))
    return low, high


def read_all_data(filename):
    data = list()
    with open(filename, 'r') as f:
        data = [float(row.strip()) for row in f]
    return data


with open('config.txt') as config:
    names = config.readline().split()
    sizes = config.readline().split()


sizes_int = [int(i) for i in sizes]
# average graph
if os.path.exists("postproc_data/graph_1"):
    os.system("rm -rf postproc_data/graph_1")
os.system("mkdir postproc_data/graph_1")
for name in names:
    for size in sizes:
        with open(f'./preproc_data/{name}_{size}.txt', "r") as info:
            file = info.readline().split()
            with open(f'./postproc_data/graph_1/{name}.txt', "a") as gr1:
                gr1.write(f'{file[0]}\n')

# error graph
if os.path.exists("postproc_data/graph_2"):
    os.system("rm -rf postproc_data/graph_2")
os.system("mkdir postproc_data/graph_2")
for name in names:
    for size in sizes:
        with open(f'./preproc_data/{name}_{size}.txt', "r") as info:
            file = info.readline().split()
            with open(f'./postproc_data/graph_2/{name}.txt', "a") as gr2:
                gr2.write(f'{float(file[0]) - float(file[3])} {float(file[2]) - float(file[0])}\n')

# moustache graph
if os.path.exists("postproc_data/graph_3"):
    os.system("rm -rf postproc_data/graph_3")
os.system("mkdir postproc_data/graph_3")
for name in names:
    for size in sizes:
        with open(f'./preproc_data/{name}_{size}.txt', "r") as info:
            file = info.readline().split()
            with open(f'./postproc_data/graph_3/{name}.txt', "a") as gr3:
                gr3.write(f'{file[1]} {file[4]} {file[5]} {file[3]} {file[2]}\n')

# average graphic
plt.subplots(figsize=(12, 6))

plt.title("Графики зависимостей времени от размера", fontsize=14)
plt.xlabel("Размер массива", fontsize=14)
plt.ylabel("Время", fontsize=14)
plt.grid(which="major", linewidth=1.2)
plt.grid(which="minor", linestyle="--", color="gray", linewidth=0.5)
i = 0
for name in names:
    data = read_all_data(f"./postproc_data/graph_1/{name}.txt")
    plt.plot(sizes, data, color=STYLES[i][0], marker=STYLES[i][1], label=name)
    i += 1
plt.legend()
plt.xticks(sizes, sizes, rotation=45, ha='right')
plt.tick_params(which='major', length=10, width=2)
plt.tick_params(which='minor', length=5, width=1)

plt.savefig("aver_graph.svg", dpi=DPI)

plt.close()


# error graphic
for name in names:
    plt.subplots(figsize=(12, 6))

    plt.title(f"Графики с ошибкой ({name})", fontsize=14)
    plt.xlabel("Размер массива", fontsize=14)
    plt.ylabel("Время", fontsize=14)
    plt.grid(which="major", linewidth=1.2)
    plt.grid(which="minor", linestyle="--", color="gray", linewidth=0.5)
    i = 0
    data = read_all_data(f"./postproc_data/graph_1/{name}.txt")
    plt.plot(sizes, data, color=STYLES[i][0], marker=STYLES[i][1], label=name)
    low, high = get_low_and_high(f"./postproc_data/graph_2/{name}.txt")
    plt.errorbar(sizes, data, [low, high], fmt=STYLES[i][0], linewidth=2, capsize=6)
    i += 1
    plt.xticks(sizes, sizes, rotation=45, ha='right')
    plt.tick_params(which='major', length=10, width=2)
    plt.tick_params(which='minor', length=5, width=1)

    plt.savefig(f"error_graph ({name}).svg", dpi=DPI)

plt.close()

# moustache graph
for name in names:
    plt.subplots(figsize=(12, 6))

    plt.xlabel("Размер массива", fontsize=14)
    plt.ylabel("Время", fontsize=14)
    plt.grid(which="major", linewidth=1.2)
    plt.grid(which="minor", linestyle="--", color="gray", linewidth=0.5)
    plt.title(f"Графики с усами ({name})", fontsize=14)
    bp = get_boxplot(f'./postproc_data/graph_3/{name}.txt')
    plt.boxplot(bp, patch_artist=True, medianprops=dict(color='orange'), capprops=dict(color='black'), whiskerprops=dict(color='black'), showfliers=False)

    plt.tick_params(which='major', length=10, width=2)
    plt.tick_params(which='minor', length=5, width=1)

    plt.savefig(f"moustache_{name}_graph.svg", dpi=DPI)

plt.close() 
