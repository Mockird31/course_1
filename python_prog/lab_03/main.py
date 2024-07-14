# Инякин Роман ИУ7-26Б 
# Программа для стеганографии

import os
import tkinter as tk
from tkinter import ttk
from tkinter import filedialog, messagebox
from PIL import Image, ImageTk

from funcs import *

app = tk.Tk()
app.title("Стеганография")
app.geometry("650x480")

# меню
menu = tk.Menu()
file_menu = tk.Menu(menu, tearoff=0)
file_menu1 = tk.Menu(menu, tearoff=0)
file_menu1.add_command(label = "Инфо", command=info)
file_menu.add_command(label = "Файл для шифровки", command=lambda:browse_file_code(file_name, img_place1, enable_chars))
file_menu.add_command(label = "Файл для расшифровки", command=lambda:browse_file_decode(file_name_decode, img_place2))

menu.add_cascade(label="Инфо", menu=file_menu1)
menu.add_cascade(label="Файл", menu=file_menu)
app.config(menu=menu)

# создание вкладок
notebook = ttk.Notebook()
notebook.pack(expand=True, fill = tk.BOTH)

frame1 = ttk.Frame(notebook)
frame2 = ttk.Frame(notebook)
 
frame1.pack(fill=tk.BOTH, expand=True)
frame2.pack(fill=tk.BOTH, expand=True)

notebook.add(frame1, text="Зашифровать")
notebook.add(frame2, text="Расшифровать")

# создание виджетов
browse_file = tk.Button(frame1, text="Файл для шифровки", command=lambda:browse_file_code(file_name, img_place1, enable_chars))
browse_file.place(x=10, y=20)

code_btn = tk.Button(frame1, text="Зашифровать и сохранить", command=lambda:start_code(text, file_name_save, file_name))
code_btn.place(x=10, y=320)

enable_chars = tk.Label(frame1, text="")
enable_chars.place(x=10, y=50)

browse_file_decode_btn = tk.Button(frame2, text="Файл для расшифровки", command= lambda:browse_file_decode(file_name_decode, img_place2))
browse_file_decode_btn.place(x=10, y=20)

decode_btn = tk.Button(frame2, text="Расшифровать", command= lambda:start_decode(text_out, file_name_decode))
decode_btn.place(x=10, y=60)

file_name = tk.Label(frame1, text='')
file_name.place(x=300, y=20)

img_place1 = tk.Label(frame1)
img_place1.place(x=300, y=70)

text_in = tk.Label(frame1, text = 'Введите текст для шифрования:')
text_in.place(x=10, y=80)

text = tk.Text(frame1, width=30, height=10)
text.place(x=10, y=100)

img_place2 = tk.Label(frame2)
img_place2.place(x=300, y=50)

fine_name_name = tk.Label(frame1, text="Введите имя файла")
fine_name_name.place(x=10, y=260)

file_name_save = tk.Entry(frame1)
file_name_save.place(x=10, y=280)

file_name_decode = tk.Label(frame2)
file_name_decode.place(x=300, y=20)

label_out = tk.Label(frame2, text='Расшифрованный текст:')
label_out.place(x=10, y= 100)

text_out = tk.Text(frame2, width=30, height=10, state = tk.DISABLED)
text_out.place(x=10, y=120)


app.mainloop()