file1 = "ans_sum.txt"
file2 = "fake_ans_sum.txt"
file3 = "ans_sub.txt"
file4 = "fake_ans_sub.txt"
file5 = "ans_mult.txt"
file6 = "fake_ans_mult.txt"
file7 = "ans_div.txt"
file8 = "fake_ans_div.txt"
file9 = "ans_power.txt"
file10 = "fake_ans_power.txt"

def check(file1, file2):
    ans_lst = []
    fake_ans_lst = []
    with open(file1, "r") as f1:
        for line in f1:
            ans_lst.append(int(line))
    with open(file2, "r") as f2:
        for line in f2:
            fake_ans_lst.append(int(line))
    for i in range(len(ans_lst)):
        if ans_lst[i] != fake_ans_lst[i]:
            print(f"Wrong anser on line {i+1}")


print("------------------SUM-------------------")
check(file1, file2)
print("-----------------ENDSUM-----------------\n")

print("------------------SUB-------------------")
check(file3, file4)
print("-----------------ENDSUB-----------------\n")

print("------------------MULT------------------")
check(file5, file6)
print("-----------------ENDMULT----------------\n")

print("------------------DIV-------------------")
check(file7, file8)
print("-----------------ENDDIV-----------------\n")

print("------------------POW-------------------")
check(file9, file10)
print("-----------------ENDPOW-----------------\n")
