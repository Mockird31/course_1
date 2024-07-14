from tkinter import *
from tkinter.messagebox import showerror, showinfo
from count import *

need_to_del = False
line1, line2, line3 = None, None, None
# Добавить точку
def add_point(field_x, field_y, points_list, canvas):
    x_coord = field_x.get()
    y_coord = field_y.get()
    if x_coord[0] == '0' and len(x_coord) > 1:
        x_coord = x_coord[1:]
    if y_coord[0] == '0' and len(y_coord) > 1:
        y_coord = y_coord[1:]
    if (not(x_coord.isdigit())) or (not(y_coord.isdigit())) or (not(0 <= int(x_coord) <= 580)) or (not(0 <= int(y_coord) <= 425)):
        showerror("Ошибка", "Неверный ввод")
        return 
    arr_x, arr_y = from_lb_to_arrs(points_list)
    if (x_coord in arr_x) and (y_coord in arr_y):
        showerror("Ошибка", "Такая точка уже отмечена")
        return 
    max_width_x = 26
    max_width_y = 40
    padding_x = (max_width_x - len(str(x_coord))) // 2
    padding_y = (max_width_y - len(str(y_coord))) // 2
    points_list.insert(END, " "*padding_x + str(x_coord) + " "*padding_y + str(y_coord))
    draw_point(int(x_coord), int(y_coord), canvas)

# Отрисовать точку
def draw_point(x, y, canvas):
    radius = 5
    canvas.create_oval(x - radius, y - radius, x + radius, y + radius, fill="black")

# Очистить результат
def clear_result(canvas, square_label, p1, p2, p3):
    global line1, line2, line3
    canvas.delete(line1)
    canvas.delete(line2)
    canvas.delete(line3)
    square_label.config(text = "Наибольшая площадь: 0")
    p1.config(text = "Точка 1: ")
    p2.config(text = "Точка 2: ")
    p3.config(text = "Точка 3: ")

# Отрисовать точку с помощью мышки
def draw_point_by_mouse(event, canvas, points_list):
    radius = 5
    canvas.create_oval(event.x - radius, event.y - radius, event.x + radius, event.y + radius, fill="black")
    max_width_x = 26
    max_width_y = 40
    padding_x = (max_width_x - len(str(event.x))) // 2
    padding_y = (max_width_y - len(str(event.y))) // 2
    points_list.insert(END, " "*padding_x + str(event.x) + " "*padding_y + str(event.y))

# Из listbox в списки
def from_lb_to_arrs(listbox):
    arr_x = []
    arr_y = []
    for i in range(listbox.size()):
        arr = listbox.get(i).split()
        arr_x.append(arr[0])
        arr_y.append(arr[1])
    return arr_x, arr_y

# Очистить всё
def clear_canvas(canvas, points_list, square_label, p1, p2, p3, ent1, ent2):
    canvas.delete('all')
    points_list.delete(0, END)
    square_label.config(text = "Наибольшая площадь: 0")
    p1.config(text = "Точка 1: ")
    p2.config(text = "Точка 2: ")
    p3.config(text = "Точка 3: ")
    ent1.delete(0, END)
    ent2.delete(0, END)

# Отрисовать прямые и вывести результат
def count_draw(canvas, listbox, square_label, p1, p2, p3):
    global need_to_del
    arr_x, arr_y = from_lb_to_arrs(listbox)
    area, data = max_triangle_area(arr_x, arr_y)
    if data is None:
        showinfo("Оповещение", "Треугольник с такими координатами нельзя построить")
        return
    x1,y1,x2,y2,x3,y3 = data
    global line1, line2, line3
    if need_to_del == False:
        line1 = canvas.create_line(x1,y1,x2,y2, fill="red")
        line2 = canvas.create_line(x2,y2,x3,y3, fill="red")
        line3 = canvas.create_line(x1,y1,x3,y3, fill="red")
        need_to_del = True
    else:
        canvas.delete(line1)
        canvas.delete(line2)
        canvas.delete(line3)
        line1 = canvas.create_line(x1,y1,x2,y2, fill="red")
        line2 = canvas.create_line(x2,y2,x3,y3, fill="red")
        line3 = canvas.create_line(x1,y1,x3,y3, fill="red")
    square_label.config(text = f'Наибольшая площадь: {area}')
    p1.config(text = f'Точка 1:  x = {x1}  y = {y1}')
    p2.config(text = f'Точка 2:  x = {x2}  y = {y2}')
    p3.config(text = f'Точка 3:  x = {x3}  y = {y3}')