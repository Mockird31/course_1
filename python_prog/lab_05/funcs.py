import time
import pygame
import numpy as np
import random

def rotate_sprite(image, angle):
    image = image.convert_alpha()
    width, height = image.get_size()
    radians = np.deg2rad(angle)
    
    center_x, center_y = width // 2, height // 2

    rotated_surface = pygame.Surface((width, height), pygame.SRCALPHA)
    rotated_surface.fill((0, 0, 0, 0))

    cos_angle = np.cos(radians)
    sin_angle = np.sin(radians)

    for x in range(width):
        for y in range(height):
            rel_x = x - center_x
            rel_y = y - center_y

            new_x = int(center_x + rel_x * cos_angle - rel_y * sin_angle)
            new_y = int(center_y + rel_x * sin_angle + rel_y * cos_angle)

            if 0 <= new_x < width and 0 <= new_y < height:
                pixel = image.get_at((x, y))
                rotated_surface.set_at((new_x, new_y), pixel)

    return rotated_surface


def remove_white_background(image):
    image = image.convert_alpha()  
    width, height = image.get_size()

    for x in range(width):
        for y in range(height):
            if image.get_at((x, y))[:3] == (255, 255, 255):
                image.set_at((x, y), (255, 255, 255, 0))

    return image


def generate_cloud_and_coords(screen, clouds):
    cloud = random.choice(clouds)
    x_coord = -220
    y_coord = random.randint(0, 230)
    speed = 50
    return cloud, x_coord, y_coord, speed