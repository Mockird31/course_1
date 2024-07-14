import os
import tkinter as tk
from tkinter import ttk
from tkinter import filedialog, messagebox
from PIL import Image, ImageTk

from defend_code import *

def browse_file_code(file_name, img_place1):
    file = filedialog.askopenfilename(filetypes=[("Image files", "*.bmp")])
    try:
        img = Image.open(file)
    except:
        return 1

    name_file = os.path.basename(file)
    file_name.config(text=name_file)
    draw_img(img, img_place1)


def draw_img(img, img_place):
    resized_image = img.resize((200,200))
    photo = ImageTk.PhotoImage(resized_image)
    img_place.config(image = photo)
    img_place.image = photo

def get_pillow_img(file):
    img = Image.open(file)
    return img

def save_image(file_name,text):
    text_func = text.get(1.0, tk.END)
    file_path = filedialog.asksaveasfilename(defaultextension=".bmp", filetypes=[("Image files", "*.bmp")])
    file_name_func = os.path.abspath(file_name.cget("text"))
    image = hide(file_name_func, text_func)
    if file_path:
        # Сохраняем изображение в выбранный файл
        image.save(file_path)