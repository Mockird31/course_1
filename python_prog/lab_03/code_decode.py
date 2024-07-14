import os
import tkinter as tk
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

# шифрование
def code(img, text):
    bin_text_func = bin_text(text)
    len_bin_text = len(bin_text_func)
    if ((img.width * img.height * 3 - DATA_SIZE_LEN - len_bin_text) // 8) < 0:
        return 
    bin_len_bin_text = bin(len_bin_text)[2:].zfill(DATA_SIZE_LEN)
    i = 0
    k = 0
    is_text_coded = False
    is_len_in_image = True
    for y in range(img.height):
        for x in range(img.width):
            c = list(img.getpixel((x, y)))
            for j in range(len(c)):
                if is_len_in_image:
                    if k < DATA_SIZE_LEN:
                        c[j] = int(bin_num(c[j])[:-1] + bin_len_bin_text[k], 2)
                        k += 1
                    else:
                        is_len_in_image = False
                else:
                    if i < len_bin_text:
                        c[j] = int(bin_num(c[j])[:-1] + bin_text_func[i], 2)
                        i += 1
                    else:
                        is_text_coded = True
                        break
            img.putpixel((x, y), tuple(c))
            if is_text_coded:
                break
        if is_text_coded:
            break
    return img


def decode_text(img):
    try:
        bin_text = ''
        i = 0
        k = 0
        bin_size = ''
        size = 0
        is_decoded_image = True
        is_decoded_text = False
        for y in range(img.height):
            for x in range(img.width):
                c = list(img.getpixel((x, y)))
                for j in range(len(c)):
                    if is_decoded_image:
                        if k < DATA_SIZE_LEN:
                            bin_size += bin_num(c[j])[-1]
                            k += 1
                        else:
                            size = int(bin_size, 2)
                            is_decoded_image = False
                    else:
                        if i < size:
                            bin_text += bin_num(c[j])[-1]
                            i += 1
                        else:
                            is_decoded_text = True
                            break

            if is_decoded_text:
                break
        text = ''
        for i in range(0, len(bin_text), 8):
            text += int(bin_text[i:i + 8], 2).to_bytes(1,'big').decode('cp1251')

        return text
    except Exception as e:
        print(e)
