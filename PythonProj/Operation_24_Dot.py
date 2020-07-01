import itertools
from itertools import permutations, combinations


def cal(num1, num2, num3, num4, d1, d2, d3):
    ret_sum = 0
    if '+' == d1:
        ret_sum = num1 + num2
    if '-' == d1:
        ret_sum = num1 - num2
    if '*' == d1:
        ret_sum = num1 * num2
    if '/' == d1:
        if num1 % num2 == 0:
            ret_sum = num1 // num2
        else:
            return 0
    if d2 == '+':
        ret_sum = ret_sum + num3
    if d2 == '-':
        ret_sum = ret_sum - num3
    if d2 == '*':
        ret_sum = ret_sum * num3
    if d2 == '/':
        if ret_sum % num3 == 0:
            ret_sum = ret_sum // num3
        else:
            return 0
    if d3 == '+':
        ret_sum = ret_sum + num4
    if d3 == '-':
        ret_sum = ret_sum - num4
    if d3 == '*':
        ret_sum = ret_sum * num4
    if d3 == '/':
        if ret_sum % num4 == 0:
            ret_sum = ret_sum // num4
        else:
            return 0

    return ret_sum


if __name__ == '__main__':

    op = ['+', '-', '*', '/']

    while True:
        try:
            instr = input()
            if not instr:
                break
            instr = instr.upper()
            if "JOKER" in instr:
                print('ERROR')
                continue

            list_in = instr.split()
            list_trans = []
            # 转换JQKA
            for i in list_in:
                if i == "J":
                    list_trans.append("11")
                elif i == "Q":
                    list_trans.append("12")
                elif i == "K":
                    list_trans.append("13")
                elif i == "A":
                    list_trans.append("1")
                else:
                    list_trans.append(i)

            in_list_conbi = list(permutations(list_trans))
            # print(in_list_conbi)
            b24dot = False
            result = ''
            for conbi in in_list_conbi:
                num1 = int(conbi[0])
                num2 = int(conbi[1])
                num3 = int(conbi[2])
                num4 = int(conbi[3])
                for d1 in op:
                    for d2 in op:
                        for d3 in op:
                            if cal(num1, num2, num3, num4, d1, d2, d3) == 24:
                                result = str(num1) + d1 + str(num2) + d2 + str(num3) + d3 + str(num4)
                                b24dot = True

                                if "11" in result:
                                    result = result.replace("11", "J")
                                if "12" in result:
                                    result = result.replace("12", "Q")
                                if "13" in result:
                                    result = result.replace("13", "K")
                                if "10" in result:
                                    result = result.replace("10", "Z")
                                if "1" in result:
                                    result = result.replace("1", "A")
                                if "Z" in result:
                                    result = result.replace("Z", "10")

                                break
                        if b24dot:
                            break
                    if b24dot:
                        break
                if b24dot:
                    break

            if b24dot:
                print(result)
                continue
            else:
                print('NONE')

        except:
            break
