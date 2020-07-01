if __name__ == '__main__':
    while True:
        try:
            instr = input()
            word = ''
            words = []
            for i in range(len(instr)):
                if 'A' <= instr[i] <= 'Z' or 'a' <= instr[i] <= 'z':
                    word = word + instr[i]
                    continue
                else:
                    if len(word) > 0:
                        words.append(word)
                        word = ''

            if len(word) > 0:
                words.append(word)

            count = len(words)
            for a in range(count).__reversed__():
                print(words[a], end='')
                if a != 0:
                    print(" ", end='')


        except:
            break




