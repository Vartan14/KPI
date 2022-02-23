# ІП-13 Карамян В.С.
# Варіант 15
# Створити текстовий файл. Переписати його компоненти до нового текстового файлу,
# вставляючи в кінець кожного рядка літеру, що є останнью в першому слові рядка.
# Вивести вміст вихідного і створеного файлів.

import funcs_file as ff

init_file_name = input("Please, enter init file name:")
ff.create_file(init_file_name)

edit_file_name = input("Please, enter edit file name:")
ff.edit_file(init_file_name, edit_file_name)

ff.output_file(init_file_name)
ff.output_file(edit_file_name)
