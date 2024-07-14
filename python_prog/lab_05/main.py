import pygame
import sys
import os
from funcs import *
pygame.init()

screen = pygame.display.set_mode((1200, 800))
clock = pygame.time.Clock()

new_size = (80, 80)
background = pygame.image.load("./sprites/bg.png")
background = pygame.transform.scale(background, (1200, 800))
shashliki = [remove_white_background(pygame.transform.scale(pygame.image.load(f'./sprites/shash{i}.png').convert(), new_size)) for i in range(1,4)]

sprite_positions = [(345, 480), (445, 480), (545, 480)]
sprite_rects = [sprite.get_rect(center=position) for sprite, position in zip(shashliki, sprite_positions)]

human = remove_white_background((pygame.image.load("./sprites/man.png").convert()))
human = pygame.transform.scale(human, (400,400))

clouds_data = list()
clouds = [remove_white_background(pygame.transform.scale(pygame.image.load(f'./sprites/clouds/{i}.png').convert(), (250, 100))) for i in range(5,8)]
cloud, x_coord, y_coord, speed = generate_cloud_and_coords(screen, clouds)
clouds_data.append({'cloud': cloud, 'x': x_coord, 'y': y_coord, 'speed': speed})

angles = [0, 0, 0]

running = True
while running:
    dt = clock.tick(60) / 1000
    screen.blit(background, (0, 0))
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
    
    if pygame.time.get_ticks() % 10000 < 20:
        cloud, x_coord, y_coord, speed = generate_cloud_and_coords(screen, clouds)
        clouds_data.append({'cloud': cloud, 'x': x_coord, 'y': y_coord, 'speed': speed})


    for i, (sprite, rect) in enumerate(zip(shashliki, sprite_rects)):
        rotated_sprite = remove_white_background(rotate_sprite(sprite, angles[i]))
        rotated_rect = rotated_sprite.get_rect(center = rect.center)
        screen.blit(remove_white_background(rotated_sprite), rotated_rect.topleft)
        angles[i] += 1

    for cl in clouds_data:
        cl['x'] += cl['speed'] * dt
        screen.blit(cl['cloud'], (cl['x'], cl['y']))

    pygame.draw.line(screen, (128, 128, 128), [300, 800], [300, 600], 10)
    pygame.draw.line(screen, (128, 128, 128), [600, 800], [600, 600], 10)
    pygame.draw.rect(screen, (128, 128, 128), (280, 500, 340, 100))
    screen.blit(human, (640, 350))
    pygame.display.update()
    pygame.display.flip()


pygame.quit()
sys.exit() 