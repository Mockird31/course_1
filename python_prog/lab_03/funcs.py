import os
import tkinter as tk
from tkinter import filedialog, messagebox
from PIL import Image, ImageTk
from code_decode import *


def error_msg(msg):
    messagebox.showerror("Error", msg)


def info():
    msg = "Стеганография\nРазработал Инякин Роман ИУ7-26Б"
    messagebox.showinfo("Info", msg)


def set_avaible_pixels(enable_chars, avaible_chars, data_len):
    enable_chars.config(text=f'Доступно символов = {(avaible_chars * 8 - data_len) // 8}')


def browse_file_code(file_name, img_place1, enable_chars):
    file = filedialog.askopenfilename(filetypes=[("Image files", "*.bmp")])
    try:
        img = Image.open(file)
    except:
        return 1

    name_file = os.path.basename(file)
    file_name.config(text=name_file)
    draw_img(img, img_place1)
    avaible_chars = (img.width * img.height * 3 - DATA_SIZE_LEN) // 8
    set_avaible_pixels(enable_chars, avaible_chars, 0)


def draw_img(img, img_place):
    resized_image = img.resize((250,250))
    photo = ImageTk.PhotoImage(resized_image)
    img_place.config(image = photo)
    img_place.image = photo


def get_pillow_img(file):
    img = Image.open(file)
    return img


def get_pixmap_from_pillow(img):
    photo = ImageTk.PhotoImage(img)
    return photo


def start_code(text, file_name_save, file_name):
    text_func = text.get(1.0, tk.END)
    for i in range(len(text_func)):
        if ord(text_func[i]) >= 127:
            error_msg("Введены неверные символы")
            return 1
    file_name = os.path.abspath(file_name.cget("text"))
    try:
        coded_img = code(get_pillow_img(file_name), text_func.encode('cp1251'))
    except Exception:
        error_msg("Что-то пошло не так при открытие/кодирование файла")
        return
    if coded_img is None:
        error_msg("Количество элементов превышает допустимое")
        return 1
    try:
        name = file_name_save.get().split('.')[0]
        coded_img.save(name + '.bmp')
        error_msg("Файл сохранен!")
    except:
        error_msg("Файл не может быть сохранен!")


def browse_file_decode(file_name_decode, img_place2):
    file = filedialog.askopenfilename(filetypes=[("Image files", "*.bmp")])
    try:
        img = Image.open(file)
    except:
        error_msg("Файл не корректен!")
        return 1

    name_file = os.path.basename(file)
    file_name_decode.config(text=name_file)
    draw_img(img, img_place2)


def start_decode(text_out, file_name_decode):
    text_out.configure(state= tk.NORMAL)
    if text_out.get(1.0, tk.END):
        text_out.delete(1.0, tk.END)
    file_name = os.path.abspath(file_name_decode.cget("text"))
    try:
        detext = decode_text(get_pillow_img(file_name))
    except:
        error_msg("Что-то пошло не так при открытие/кодирование файла")
        return 1
    text_out.insert(tk.END, detext)
    text_out.configure(state= tk.DISABLED)

