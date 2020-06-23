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
    

    
    
    vetor_desordenado = random.sample(range(0, 100), 100)
    vetor_ordenado, numero_de_passos = quick_sort(copy.copy(vetor_desordenado))
    
    texto_saida = ""
    texto_saida += "Vetor de teste aleatorio:\n"
    texto_saida += str(vetor_desordenado) + "\n"
    texto_saida += "Vetor de teste ordenado:\n"
    texto_saida += str(vetor_ordenado) + "\n"

    texto_saida += "\n\n"

    #-------------------------------Inserções-----------------------------------


    texto_saida += "+++++++++++++++++++++++++++++++++++"
    texto_saida += "Inserções"
    texto_saida += "+++++++++++++++++++++++++++++++++++\n"

    texto_saida += "\n\n"

    texto_saida += "---------------------------------------------------------\n"
    texto_saida += "******************Arvore Binária de Busca****************\n"
    texto_saida += "---------------------------------------------------------\n"
    texto_saida += "\n\n"

    #------------------------Arvore com vetor desordenado-----------------------
    abb_vetor_desordenado = ArvoreBinariaBusca()

    for i in vetor_desordenado:
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

    for i in vetor_desordenado:
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

    #---------------------------------Buscas------------------------------------


    texto_saida += "+++++++++++++++++++++++++++++++++++++"
    texto_saida += "Buscas"
    texto_saida += "+++++++++++++++++++++++++++++++++++++\n"



    texto_saida += "Árvore de Busca Binária (vetor desordenado):\n"
    resultado, passos = abb_vetor_desordenado.busca(vetor_desordenado[-1])
    texto_saida += str(resultado) + "\n"
    texto_saida += str(passos) + "\n"
    
    texto_saida += "Árvore de Busca Binária (vetor ordenado):\n"
    resultado, passos = abb_vetor_ordenado.busca(vetor_ordenado[-1])
    texto_saida += str(resultado) + "\n"
    texto_saida += str(passos) + "\n"
    
    texto_saida += "AVL (vetor desordenado):\n"
    resultado, passos = avl_desordenada.busca(vetor_desordenado[-1])
    texto_saida += str(resultado) + "\n"
    texto_saida += str(passos) + "\n"
    
    texto_saida += "AVL (vetor ordenado):\n"
    resultado, passos = avl_ordenada.busca(vetor_ordenado[-1])
    texto_saida += str(resultado) + "\n"
    texto_saida += str(passos) + "\n"

    #-------------------------Escrita dos resultados----------------------------
    
    
    print(texto_saida)

    if (arquivo_saida != None):
        arquivo_saida.write(texto_saida)
        arquivo_saida.close()