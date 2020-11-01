import random
import string
N = 100000

with open("input.txt", "w") as f:
    for i in range(N):
        k = random.randint(1, 3)
        if(k == 1):
            f.write("".join(random.choice(string.ascii_lowercase) for i in range(random.randint(1, 4))))
            f.write("\n")
        elif(k == 2):
            f.write("- ")
            f.write("".join(random.choice(string.ascii_lowercase) for i in range(random.randint(1, 4))))
            f.write("\n")
        elif(k == 3):
            f.write("+ ")
            f.write("".join(random.choice(string.ascii_lowercase) for i in range(random.randint(1, 4))))
            f.write(" ")
            f.write(str(random.randint(0, 100000)))
            f.write("\n")
        elif(k == 4):
            f.write("! Save C:\\Users\\SuperPC\\Downloads\\VSC\\DA\\da_exercise_02\\build\\Debug\\trash\\")
            f.write("".join(random.choice(string.ascii_lowercase) for i in range(random.randint(1, 4))))
            f.write(".txt\n")
        elif(k == 5):
            f.write("! Load C:\\Users\\SuperPC\\Downloads\\VSC\\DA\\da_exercise_02\\build\\Debug\\trash\\")
            f.write("".join(random.choice(string.ascii_lowercase) for i in range(random.randint(1, 4))))
            f.write(".txt\n")
