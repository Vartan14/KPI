def create_file(file_name):
    print(
        "Please, select the write mode.To create a new file, type 'w'.To append to an already existing file, type 'a'.")
    while True:
        mode = input()
        if mode == 'w' or mode == 'a':
            file_out = open(file_name, mode)
            break
        else:
            print("Error. Please type 'w' or 'a'.")

    print("Enter the text. To finish press Ctrl+X:")
    while True:
        line = input()
        if line == chr(24):
            break
        file_out.write(line + '\n')

    file_out.close()


def output_file(file_name):
    print(file_name + ":")
    with open(file_name, 'r') as file_in:
        text = file_in.read()
    print(text)


def edit_file(file_name, edit_file_name):
    file_in = open(file_name, 'r')
    file_out = open(edit_file_name, 'w')

    edit_text = ''
    text = file_in.readlines()

    for i in range(len(text)):
        text[i] = text[i].rstrip()
        if text[i] == '':
            edit_text += '\n'
            continue
        j = 0
        while text[i][j] == ' ':
            j += 1
        pos = text[i].find(' ', j)
        if pos == -1:
            pos = len(text[i])
        line = text[i] + text[i][pos - 1]
        edit_text += line + '\n'
    file_out.write(edit_text)

    file_in.close()
    file_out.close()