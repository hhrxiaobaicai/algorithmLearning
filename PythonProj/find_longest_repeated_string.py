


def find_longest_repeated_string(in_str):
    sub_list = []
    for i in range(len(in_str)):
        sub_list.append(in_str[i:])

    sub_list.sort()
    out_list =[]
    for i in range(len(sub_list)-1):
        str1 = sub_list[i]
        str2 = sub_list[i+1]
        length = 0
        for j in range(min(len(str1), len(str2))):
            if str1[j] != str2[j]:
                break
            else:
                length = length+1

        out_list.append(str1[:length])

    max_len = 0
    idx_no = 0
    for i in range(len(out_list)):
        len_tmp = len(out_list[i])
        if len_tmp > max_len:
            max_len = len_tmp
            idx_no = i

    return out_list[idx_no]

if __name__ == '__main__':

    in_str = "abcabcabcabc"
    out_str = find_longest_repeated_string(in_str)
    print(out_str)