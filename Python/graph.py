#!/usr/bin/env python3

import matplotlib as mpl
import matplotlib.pyplot as plt
import matplotlib.dates as mdates
import datetime as dt
import csv
import matplotlib.ticker
import os

from matplotlib.ticker import (MultipleLocator, FormatStrFormatter,AutoMinorLocator)

filtred_temp = {}
raw_temp = {}

maxindex=0
base_time=0
time=0
first_raw=1

def plot_graf(filename):
    first_raw=1
    maxindex=0
    with open(filename, newline = '') as f:
        for row in csv.reader(f, delimiter = ':', quotechar = '"'):
            if first_raw == 1:
                first_raw = 0
                time = 0
            else:
                time = time + 0.2
            filtred_temp[time] = int(row[0])/100
            raw_temp[time] = int(row[1])/100
            maxindex = time

    dpi = 80
    fig = plt.figure(dpi = dpi, figsize = (1024 / dpi, 768 / dpi) )
    mpl.rcParams.update({'font.size': 10})

    x = []
    y = []

    x2 = []
    y2 = []

    liq_x = [0,800]
    liq_y = [217,217]

    plt.title("MAX6675 Graph") # заголовок
    plt.xlabel("Time, sec") # ось абсцисс
    plt.ylabel("Temp, C") # ось ординат

    plt.axis([0, maxindex, 18, 30])

    ax = plt.gca()
    ax.yaxis.grid(True)
    ax.xaxis.grid(True)

    ax.xaxis.set_minor_locator(AutoMinorLocator())
    ax.yaxis.set_minor_locator(AutoMinorLocator())
    ax.tick_params(which='major', length=10, width=2)
    ax.tick_params(which='minor', length=5, width=1)

    for reg in filtred_temp.keys():
        x.append(reg) 
        y.append(filtred_temp[reg])


    for reg in raw_temp.keys():
        x2.append(reg) 
        y2.append(raw_temp[reg])


    # Создаем экземпляр класса, который будет отвечать за расположение меток
    locatory = matplotlib.ticker.MultipleLocator (base=0.1)
    locatorx = matplotlib.ticker.MultipleLocator (base=1)

    # Установим локатор для главных меток
    #ax.xaxis.set_major_locator (locatorx)
    #ax.yaxis.set_major_locator (locatory)
    plt.plot(x, y,label = 'LP Filter')  # построение графика
    plt.plot(x2,y2,label = 'Raw data',linestyle = 'dashed')

    #plt.plot(liq_x,liq_y,color='red',label = 'liquidus',linestyle = 'dashed')

    plt.legend(loc = 'upper right')

    pre, ext = os.path.splitext(filename)
    imgfilename = pre + ".png"
    
    fig.savefig(imgfilename)
