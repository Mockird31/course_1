
# Выбрать три точки, чтобы площадь треугольника была максимальной

from tkinter import *
from funcs import *
app = Tk()     # создаем корневой объект - окно
app.title("Площадь треугольника")     # устанавливаем заголовок окна
app.geometry("800x600")    # устанавливаем размеры окна
 
# Поля ввода точки
enter_x = Label(text = "Введите x:")
enter_x.place(x = 0, y =0)
field_x = Entry(width=35)
field_x.place(x = 0, y = 21)

enter_y = Label(text = "Введите y:")
enter_y.place(x = 350, y = 0)
field_y = Entry(width=35)
field_y.place(x = 350, y = 21)

label_x = Label(text = "x", background="black", width = 5)
label_x.place(x = 25, y = 47)

label_y = Label(text = "y", background="black", width= 5)
label_y.place(x = 105, y = 47)

btn_add_point = Button(text = "Добавить", command=lambda:add_point(field_x, field_y, points_list, canvas))
btn_add_point.place(x = 700, y = 21)

# Список для точек
points_list = Listbox(height = 25)
points_list.place(x = 0, y = 70)

# Кнопка отчистки всего
clear_btn = Button(text = "Очистить всё", height=3, width=10, command=lambda:clear_canvas(canvas, points_list, square_label, p1, p2, p3, field_x, field_y))
clear_btn.place(x = 0, y = 510)

# Кнопка отчистки результата
clear_res_btn = Button(text = "Очистить результат", height=3, width=12, command=lambda:clear_result(canvas, square_label, p1, p2, p3))
clear_res_btn.place(x = 140, y = 510)

# Кнопка посчитать
count_btn = Button(text = "Посчитать", height = 3, width = 10, command=lambda:count_draw(canvas, points_list, square_label, p1, p2, p3))
count_btn.place(x = 295, y =510)

# Наибольшая площадь
square_label = Label(text = "Наибольшая площадь: 0", 
                     background="black", 
                     anchor = "w", 
                     justify= "left", 
                     height = 3, 
                     width = 40)
square_label.place(x = 490, y = 518)

# Точки
p1 = Label(text = "Точка 1: ", background="black", anchor="w", justify="left", width = 30)
p1.place(x = 0, y = 573)

p2 = Label(text = "Точка 2: ", background="black", anchor="w", justify="left", width = 30)
p2.place(x = 275, y = 573)

p3 = Label(text = "Точка 3: ", background="black", anchor="w", justify="left", width = 30)
p3.place(x = 550, y = 573)

# canvas
canvas = Canvas(bg="white", width=580, height=425)
canvas.bind('<Button-1>', lambda e: draw_point_by_mouse(e, canvas, points_list))
canvas.place(x=200,y=70)

app.mainloop()