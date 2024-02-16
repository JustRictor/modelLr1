import pandas as pd
import matplotlib.pyplot as plt
from copy import deepcopy

def printFoo(arr: list[list[float]]) -> None:
    fig, axs = plt.subplots(3, 3)
    fig.suptitle('Эмперическая функция распределения')
    for i in range(9):
        axs[i // 3, i % 3].hist(arr[i], histtype='step', cumulative=True, bins=len(arr[i]))
    
    axs[0,0].set_title('1000')
    axs[0,1].set_title('5000')
    axs[0,2].set_title('10000')

    axs[0,0].set(ylabel='Конгурентный')
    axs[1,0].set(ylabel='Фибоначчи')
    axs[2,0].set(ylabel='Мерсенн')
    plt.show()



def planGraph(arr: list[list[float]]) -> None:
    arr_ = deepcopy(arr)
    for i in range(len(arr_)):
        arr_[i].insert(0,2**(-52))
        arr_[i].pop()

    fig, axs = plt.subplots(3, 3)
    fig.suptitle('Распределение на плоскости')
    for i in range(9):
        axs[i // 3, i % 3].scatter(arr[i],arr_[i], s = 0.5)

    axs[0,0].set_title('1000')
    axs[0,1].set_title('5000')
    axs[0,2].set_title('10000')

    axs[0,0].set(ylabel='Конгурентный')
    axs[1,0].set(ylabel='Фибоначчи')
    axs[2,0].set(ylabel='Мерсенн')
    plt.show()


def kde(arr: list[list[float]])->None:
    for i in range(len(arr)):
        plt.subplot(3,3,i+1)
        if(i == 0):
            plt.title('1000')
            plt.ylabel('Конгурентный')
        if(i == 1):
            plt.title('5000')
        if(i == 2):
            plt.title('10000')
        if(i == 3):
            plt.ylabel('Фибоначчи')
        if(i == 6):
            plt.ylabel('Мерсенн')
        s = pd.Series(arr[i])
        s.plot.kde()
    plt.show()


def main() -> None:
    arr = []
    with open('out.csv') as file:
        samp = [i.split(', ')[:-1] for i in file.read().splitlines()]
        for line in samp:
            arr.append([float(i) for i in line])
    #printFoo(arr)
    #planGraph(arr)
    kde(arr)
    
if __name__ == "__main__":
    main()