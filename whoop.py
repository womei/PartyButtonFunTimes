#this is the python script to run, 
#it captures serial data from the arduino (requires pyserial)
#then it plays an mp3 (requires pygame)

import serial
import pygame as pg

ser = serial.Serial(PORT NUMBER, 57600)

pg.init()
pg.mixer.music.load("sound.mp3")

while True:
	#run this loop ad infinitum

	#read a line
	line = ser.readline()
	#make sure that there are no errors, convert the serial to ints
	try:
		line = int(line)
	except (RuntimeError, TypeError, NameError, ValueError):
		pass

	print line
	if line == 2:
	# this means that the button has just been pushed, start playing the music
		print "Play that music!"
		pg.mixer.music.play()
	elif line ==3:
	#the button is still pushed in, keep that song going
		pass
	else:
	#the button is not pushed, stop the music
		pg.mixer.music.stop()
