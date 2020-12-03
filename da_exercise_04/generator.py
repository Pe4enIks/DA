import random
N = 100000
M = 50

with open("banchmark_bad.txt", "w") as f:
    f.write(str(50))
    f.write("\n")
    for i in range(N):
        for j in range(M):
            f.write(str(50))
            f.write(" ")
        f.write("\n")

with open("banchmark_normal.txt", "w") as f:
    f.write(str(random.randint(0, 2)))
    f.write(" ")
    f.write(str(random.randint(0, 2)))
    f.write(" ")
    f.write(str(random.randint(0, 2)))
    f.write("\n")
    for i in range(N):
        for j in range(M):
            f.write(str(random.randint(0, 2)))
            f.write(" ")
        f.write("\n")
