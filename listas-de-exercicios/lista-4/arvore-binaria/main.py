import random
import time
import sys
import copy

from algoritmos_ordenacao import quick_sort
from arvore_binaria_busca import ArvoreBinariaBusca
from avl import AVL


if __name__=="__main__":

    arquivo_saida = None
    if (len(sys.argv) > 1):
        arquivo_saida = open(sys.argv[1], "w")
    

    
    
    vetor_teste = random.sample(range(0, 100), 100)
    # vetor_teste = [9,8,7,6,5,4,3,2,1,0]
    # random.shuffle(vetor_teste)
    vetor_ordenado, numero_de_passos = quick_sort(copy.copy(vetor_teste))
    
    texto_saida = ""
    texto_saida += "Vetor de teste aleatorio:\n"
    texto_saida += str(vetor_teste) + "\n"
    texto_saida += "Vetor de teste ordenado:\n"
    texto_saida += str(vetor_ordenado) + "\n"


    texto_saida += "---------------------------------------------------------\n"
    texto_saida += "******************Arvore Binária de Busca****************\n"
    texto_saida += "---------------------------------------------------------\n"
    texto_saida += "\n\n"

    #------------------------Arvore com vetor desordenado-----------------------
    abb_vetor_desordenado = ArvoreBinariaBusca()

    for i in vetor_teste:
        abb_vetor_desordenado.adiciona(i)


    texto_saida += "--------------ARVORE COM VETOR DESORDENADO---------------\n"
    # texto_saida += "Árvore a partir da raiz:\n"
    # texto_saida += abb_vetor_desordenado.get_texto_itens_descendo() 
    texto_saida += "\n"
    texto_saida += "Árvore em ordem:\n"
    texto_saida += abb_vetor_desordenado.get_texto_itens_em_ordem()
    texto_saida += "\n"

    #------------------------Arvore com vetor ordenado--------------------------

    abb_vetor_ordenado = ArvoreBinariaBusca()

    for i in vetor_ordenado:
        abb_vetor_ordenado.adiciona(i)

    texto_saida += "--------------ARVORE COM VETOR ORDENADO------------------\n"
    # texto_saida += "Árvore a partir da raiz:\n"
    # texto_saida += abb_vetor_ordenado.get_texto_itens_descendo() 
    # texto_saida += "\n"
    texto_saida += "Árvore em ordem:\n"
    texto_saida += abb_vetor_ordenado.get_texto_itens_em_ordem()
    texto_saida += "\n"

    texto_saida += "\n\n"

    #------------------------------------AVL------------------------------------
    texto_saida += "---------------------------------------------------------\n"
    texto_saida += "***************************AVL***************************\n"
    texto_saida += "---------------------------------------------------------\n"
    
    texto_saida += "\n\n"

    #------------------------Arvore com vetor desordenado-----------------------
    avl_desordenada = AVL()

    for i in vetor_teste:
        avl_desordenada.adiciona(i)


    texto_saida += "--------------ARVORE COM VETOR DESORDENADO---------------\n"
    # texto_saida += "Árvore a partir da raiz:\n"
    # texto_saida += abb_vetor_desordenado.get_texto_itens_descendo() 
    texto_saida += "\n"
    texto_saida += "Árvore em ordem:\n"
    texto_saida += avl_desordenada.get_texto_itens_em_ordem()
    texto_saida += "\n"

    #------------------------Arvore com vetor ordenado--------------------------

    avl_ordenada = AVL()

    for i in vetor_ordenado:
        avl_ordenada.adiciona(i)

    texto_saida += "--------------ARVORE COM VETOR ORDENADO------------------\n"
    # texto_saida += "Árvore a partir da raiz:\n"
    # texto_saida += abb_vetor_ordenado.get_texto_itens_descendo() 
    # texto_saida += "\n"
    texto_saida += "Árvore em ordem:\n"
    texto_saida += avl_ordenada.get_texto_itens_em_ordem()
    texto_saida += "\n"

    texto_saida += "\n\n"

    #-------------------------Escrita dos resultados----------------------------
    
    
    print(texto_saida)

    if (arquivo_saida != None):
        arquivo_saida.write(texto_saida)
        arquivo_saida.close()