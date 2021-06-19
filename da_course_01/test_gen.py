import random
import string

N = 1000
with open("test.txt", "w") as f:
    for _ in range(N):
        f.write(random.choice(string.ascii_lowercase))
