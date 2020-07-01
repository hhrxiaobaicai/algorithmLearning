import sys

if __name__ == '__main__':

    in_list =[]
    while True:
        try:
            num = input()
            if not num:
                break
            in_dict = {}
            for i in range(int(num)):
                A = input()
                if not in_dict.keys().__contains__(A):
                    in_dict[A] = int(A)

            in_list.append(in_dict)

        except:
            break

    for i in range(len(in_list)):
        dict = in_list[i]
        AA = sorted(dict.values())
        for k in AA:
            print(k)










