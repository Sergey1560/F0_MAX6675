#!/usr/bin/env python3
      
import serial
import time
import sys
import graph

ser = serial.Serial(            
    port='/dev/ttyACM0',
    baudrate = 115200,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
    bytesize=serial.EIGHTBITS,
    timeout=1
)


try:
    print("Start listen UART")

    timestr = time.strftime("%Y%m%d-%H%M%S")
    timestr = timestr + '.log'
    print("File: ", timestr)

    f = open(timestr, 'w+b')
    
    c=0
    while 1:
        if ser.in_waiting > 0:
            data = ser.read()
            c=c+1
            f.write(data)
            print(c, end="\r")


except KeyboardInterrupt:
    f.close()
    graph.plot_graf(timestr)
    print("\n")
    sys.exit()

