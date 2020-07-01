
if __name__ == '__main__':

    in_list = []
    while True:
        try:
            instr = input()
            if not instr:
                break
            sub = "00000000"
            len_str = len(instr)
            if len_str == 8:
                in_list.append(instr)
            elif len_str < 8:
                instr = instr + sub[:(8-len_str)]
                in_list.append(instr)
            else:
                start=0
                while start+8 < len_str:
                    in_list.append(instr[start:start+8])
                    start = start+8
                sub1 =instr[start:]
                sub1 =sub1 + sub[:8-(len_str-start)]
                in_list.append(sub1)

        except :
            break

    for i in range(len(in_list)):
        print(in_list[i])