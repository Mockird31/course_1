import os
import tkinter as tk
from tkinter import ttk
from tkinter import filedialog, messagebox
from PIL import Image, ImageTk

DATA_SIZE_LEN =128

def bin_num(num):
    return bin(num)[2:].zfill(8)


def bin_text(text):
    result = ''
    for i in text:
        result += bin_num(i)
    return result


# def hide(image_path, text):
#     text_func = text.get(1.0, tk.END).encode('cp1251')
#     bin_text_func = bin_text(text_func)
#     len_bin_text = len(bin_text_func)
#     data = str(len_bin_text) + str(bin_text_func)
#     image = Image.open(image_path)
#     pixels = image.load()

#     for i 
#     r,g,b = pixels[x,y]
#     b = data[i]


#     return image


def extract_string_from_image(image_path):
    """Извлекает скрытую строку из изображения."""
    image = Image.open(image_path)
    pixels = image.load()
    width, height = image.size
    
    # Получаем длину скрытой строки
    length_bytes = bytes([pixels[x, y][2] for x in range(4)])
    length = int.from_bytes(length_bytes, 'big')
    
    # Извлекаем байты скрытой строки
    data = bytes([pixels[x, y][2] for x in range(4, 4 + length)])
    
    # Декодируем байты в строку
    text = data.decode('utf-8')
    
    return text