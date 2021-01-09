# Complete project details at https://RandomNerdTutorials.com

from machine import Pin, I2C
import ssd1306
from time import sleep

def show_text(mtext,x,y):
    oled.text(mtext, x, y)
    oled.show()
    print(mtext)


i2c = I2C(-1, scl=Pin(22), sda=Pin(21))
oled_width = 128
oled_height = 64
oled = ssd1306.SSD1306_I2C(oled_width, oled_height, i2c)
show_text("Türkçe karakter:",0,0)
show_text("ĞÜŞİÖÇ -- ığüşöç",0,20)


        
