# Инякин Роман защита

import os
import tkinter as tk
from tkinter import ttk
from tkinter import filedialog, messagebox
from PIL import Image, ImageTk

from defend_funcs import *

app = tk.Tk()
app.title("Стеганография")
app.geometry("650x480")

choose_btn = tk.Button(text = 'Выбрать изображение', command = lambda:browse_file_code(file_name, img_place))
choose_btn.place(x=10, y = 10)

file_name = tk.Label()
file_name.place(x=300,y=10)

img_place = tk.Label()
img_place.place(x=300, y=30)

text_in = tk.Label(text = 'Введите текст для шифрования:')
text_in.place(x=10, y=80)

text = tk.Text(width=30, height=10)
text.place(x=10, y=100)

code_btn = tk.Button(text = 'Зашифровать и сохранить', command = lambda:save_image(file_name, text))
code_btn.place(x=10, y=300)

app.mainloop()