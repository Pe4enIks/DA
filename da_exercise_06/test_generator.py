import random

def numberToBase(n, b):
    if n == 0:
        return [0]
    digits = []
    while n:
        digits.append(int(n % b))
        n //= b
    my_str = ""
    digits = digits[::-1]
    for el in digits:
        my_str += f"{el:02}"
    return my_str

N = 3
num_lst = []
sum_lst = []
sub_lst = []
mult_lst = []
power_lst = []
div_lst = []
while N > 0:
    num1 = 0
    num2 = 0
    k = random.randint(1, 4)
    for i in range(k):
        num1 += random.randint(0, 2000000)
        num2 += random.randint(0, 1000000)
    num3 = num2 + random.randint(0, 2000000)
    num4 = random.randint(1, 1000)
    num6 = random.randint(1, 100)
    num5 = random.randint(1, 7)
    mult_str = numberToBase(num1 * num2, 16)
    div_str = numberToBase(num1 / num4, 16)
    power_str = numberToBase(num6**num5, 16)
    num1_str = numberToBase(num1, 16)
    num2_str = numberToBase(num2, 16)
    num3_str = numberToBase(num3, 16)
    num4_str = numberToBase(num4, 16)
    num5_str = numberToBase(num5, 16)
    num6_str = numberToBase(num6, 16)
    sum_str = numberToBase(num1 + num2, 16)
    sub_str = numberToBase(num3 - num2, 16)
    num_lst.append((num1_str, num2_str, num3_str, num4_str, num5_str, num6_str))
    sum_lst.append(sum_str)
    sub_lst.append(sub_str)
    mult_lst.append(mult_str)
    power_lst.append(power_str)
    div_lst.append(div_str)
    N -= 1

with open('test_sum.txt', "w") as f:
    for el in num_lst:
        f.write(str(el[0]) + "\n")
        f.write(str(el[1]) + "\n")
        f.write("+\n")

with open('ans_sum.txt', "w") as f:
    for el in sum_lst:
        f.write(str(el) + "\n")

with open('test_sub.txt', "w") as f:
    for el in num_lst:
        f.write(str(el[2]) + "\n")
        f.write(str(el[1]) + "\n")
        f.write("-\n")

with open('ans_sub.txt', "w") as f:
    for el in sub_lst:
        f.write(str(el) + "\n")

with open('test_mult.txt', "w") as f:
    for el in num_lst:
        f.write(str(el[0]) + "\n")
        f.write(str(el[1]) + "\n")
        f.write("*\n")

with open('ans_mult.txt', "w") as f:
    for el in mult_lst:
        f.write(str(el) + "\n")

with open('test_div.txt', "w") as f:
    for el in num_lst:
        f.write(str(el[0]) + "\n")
        f.write(str(el[3]) + "\n")
        f.write("/\n")

with open('ans_div.txt', "w") as f:
    for el in div_lst:
        f.write(str(el) + "\n")

with open('test_power.txt', "w") as f:
    for el in num_lst:
        f.write(str(el[5]) + "\n")
        f.write(str(el[4]) + "\n")
        f.write("^\n")

with open('ans_power.txt', "w") as f:
    for el in power_lst:
        f.write(str(el) + "\n")
