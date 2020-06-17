import random

from algoritmos_ordenacao import bubble_sort
from algoritmos_ordenacao import merge_sort
from algoritmos_ordenacao import quick_sort


if __name__=="__main__":
    vetor_desordenado = [random.randint(0,100) for i in range(20)]
    
    print(vetor_desordenado)

    vetor_teste = vetor_desordenado
    
    vetor_teste = bubble_sort(vetor_teste)
    print(vetor_teste)

    vetor_teste = vetor_desordenado
    vetor_teste = merge_sort(vetor_teste)
    print(vetor_teste)

    vetor_teste = vetor_desordenado
    vetor_teste = quick_sort(vetor_teste)
    print(vetor_teste)