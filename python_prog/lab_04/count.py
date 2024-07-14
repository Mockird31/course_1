
# Поиск максимальной площади
def max_triangle_area(x_coords, y_coords):
    counter = 0
    max_area = 0
    max_triangle = None
    
    for i in range(len(x_coords)):
        x_coords[i] = int(x_coords[i])

    for i in range(len(y_coords)):
        y_coords[i] = int(y_coords[i])

    points = list(zip(x_coords, y_coords))
    
    for i in range(len(points)):
        for j in range(i + 1, len(points)):
            for k in range(j + 1, len(points)):
                x1, y1 = points[i]
                x2, y2 = points[j]
                x3, y3 = points[k]
                if (y3 - y1) * (x2 - x1) == (x3 - x1) * (y2 - y1):
                    counter += 1
                area = 0.5 * abs((x2-x1)*(y3 - y1) - (x3-x1)*(y2 - y1))
                if area > max_area:
                    max_area = area
                    max_triangle = [x1,y1,x2,y2,x3,y3]
    if counter == len(points):
        return 0, None

    return max_area, max_triangle