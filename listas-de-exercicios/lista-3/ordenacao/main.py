import random
import time
import sys
import copy

from algoritmos_ordenacao import bubble_sort
from algoritmos_ordenacao import merge_sort
from algoritmos_ordenacao import quick_sort

def executa_teste(vetor):
    vetor_teste = copy.copy(vetor)
    
    if (len(vetor) > 10000):
        resultado_bubble = (None, None)
        tempo_bubble = -1
    else:
        tempo_ini = time.time()
        resultado_bubble = bubble_sort(vetor_teste)
        tempo_fim = time.time()
        tempo_bubble = tempo_fim - tempo_ini

    vetor_teste = copy.copy(vetor)
    
    tempo_ini = time.time()
    resultado_merge = merge_sort(vetor_teste)
    tempo_fim = time.time()
    tempo_merge = tempo_fim - tempo_ini
    
    vetor_teste = copy.copy(vetor)
    
    tempo_ini = time.time()
    resultado_quick = quick_sort(vetor_teste)
    tempo_fim = time.time()
    tempo_quick = tempo_fim - tempo_ini
    
    tempos = (tempo_bubble, tempo_merge, tempo_quick)

    return (resultado_bubble, resultado_merge, resultado_quick, tempos)




if __name__=="__main__":

    arquivo_saida = None
    if (len(sys.argv) > 1):
        arquivo_saida = open(sys.argv[1], "w")
    
    tamanho_testes = [100, 1000, 1000000]

    vets_desordenado = []
    
    vets_bubble = []
    vets_merge = []
    vets_quick = []
    
    vet_passos_bubble = []
    vet_passos_merge = []
    vet_passos_quick = []
    
    vet_tempos_bubble = []
    vet_tempos_merge = []
    vet_tempos_quick = []
    
    for i in tamanho_testes:
        print("Criando vetor tamanho " + str(i) + "\n")
        vetor = random.sample(range(0, i*100), i)
        vets_desordenado.append(vetor)

        print("Iniciando testes")
        res_bubble, res_merge, res_quick, tempos = executa_teste(vetor)
        

        vet_bubble, passos_bubble = res_bubble
        vet_merge, passos_merge = res_merge
        vet_quick, passos_quick = res_quick
        tempo_bubble, tempo_merge, tempo_quick = tempos

        vets_bubble.append(vet_bubble)
        vets_merge.append(vet_merge)
        vets_quick.append(vet_quick)

        vet_passos_bubble.append(passos_bubble)
        vet_passos_merge.append(passos_merge)
        vet_passos_quick.append(passos_quick)

        vet_tempos_bubble.append(tempo_bubble)
        vet_tempos_merge.append(tempo_merge)
        vet_tempos_quick.append(tempo_quick)


    # ----------------------------- Resultados ---------------------------------
    print("Vetor desordenado (100)")
    print(vets_desordenado[0])

    print("Resultado bubble sort (100)")
    print(vets_bubble[0])

    print("Resultado merge sort (100)")
    print(vets_merge[0])

    print("Resultado quick sort (100)")
    print(vets_quick[0])
    
    print()

    print("Vetor desordenado (1000)")
    print(vets_desordenado[1])
    
    print("Resultado bubble sort (1000)")
    print(vets_bubble[1])

    print("Resultado merge sort (1000)")
    print(vets_merge[1])

    print("Resultado quick sort (1000)")
    print(vets_quick[1])

    print()

    print("Vetor desordenado (1000000)")
    print(vets_desordenado[2])

    print("Resultado bubble sort (1000000)")
    print(vets_bubble[2])
    
    print("Resultado merge sort (1000000)")
    print(vets_merge[2])

    print("Resultado quick sort (1000000)")
    print(vets_quick[2])

    print()

    # ----------------------------- Estatisticas -------------------------------

    print("Passos bubble sort (100)")
    print(vet_passos_bubble[0])
    print("Tempo: " + str(vet_tempos_bubble[0]) + "\n")

    print("Passos merge sort (100)")
    print(vet_passos_merge[0])
    print("Tempo: " + str(vet_tempos_merge[0]) + "\n")

    print("Passos quick sort (100)")
    print(vet_passos_quick[0])
    print("Tempo: " + str(vet_tempos_quick[0]) + "\n")

    print()

    print("Passos bubble sort (1000)")
    print(vet_passos_bubble[1])
    print("Tempo: " + str(vet_tempos_bubble[1]) + "\n")

    print("Passos merge sort (1000)")
    print(vet_passos_merge[1])
    print("Tempo: " + str(vet_tempos_merge[1]) + "\n")

    print("Passos quick sort (1000)")
    print(vet_passos_quick[1])
    print("Tempo: " + str(vet_tempos_quick[1]) + "\n")

    print()

    print("Passos bubble sort (100000)")
    print(vet_passos_bubble[2])
    print("Tempo: " + str(vet_tempos_bubble[2]) + "\n")

    print("Passos merge sort (100000)")
    print(vet_passos_merge[2])
    print("Tempo: " + str(vet_tempos_merge[2]) + "\n")

    print("Passos quick sort (100000)")
    print(vet_passos_quick[2])
    print("Tempo: " + str(vet_tempos_quick[2]) + "\n")

    print()

    #-------------------Escrita dos resultados em arquivo-----------------------

    if (arquivo_saida != None):
        texto = ""

        texto += "-----------------------Resultados----------------------------"
        texto += "\n"

        texto += "Vetor desordenado (100) \n"
        texto += str(vets_desordenado[0]) + "\n"

        texto += "Resultado bubble sort (100) \n"
        texto += str(vets_bubble[0]) + "\n"

        texto += "Resultado merge sort (100) \n"
        texto += str(vets_merge[0]) + "\n"

        texto += "Resultado quick sort (100) \n"
        texto += str(vets_quick[0]) + "\n"
        
        texto += "\n"

        texto += "Vetor desordenado (1000) \n"
        texto += str(vets_desordenado[1]) + "\n"
        
        texto += "Resultado bubble sort (1000) \n"
        texto += str(vets_bubble[1]) + "\n"

        texto += "Resultado merge sort (1000) \n"
        texto += str(vets_merge[1]) + "\n"

        texto += "Resultado quick sort (1000) \n"
        texto += str(vets_quick[1]) + "\n"

        texto += "\n"

        texto += "Vetor desordenado (1000000) \n"
        texto += str(vets_desordenado[2]) + "\n"

        texto += "Resultado bubble sort (1000000) \n"
        texto += str(vets_bubble[2]) + "\n"
        
        texto += "Resultado merge sort (1000000) \n"
        texto += str(vets_merge[2]) + "\n"

        texto += "Resultado quick sort (1000000) \n"
        texto += str(vets_quick[2]) + "\n"

        texto += "\n"

        texto += "---------------------Estatisticas----------------------------"
        texto += "\n"

        texto += "Passos bubble sort (100) \n"
        texto += str(vet_passos_bubble[0]) + "\n"
        texto += "Tempo: " + str(vet_tempos_bubble[0]) + "\n"

        texto += "Passos merge sort (100) \n"
        texto += str(vet_passos_merge[0]) + "\n"
        texto += "Tempo: " + str(vet_tempos_merge[0]) + "\n"

        texto += "Passos quick sort (100) \n"
        texto += str(vet_passos_quick[0]) + "\n"
        texto += "Tempo: " + str(vet_tempos_quick[0]) + "\n"

        texto += "\n"

        texto += "Passos bubble sort (1000) \n"
        texto += str(vet_passos_bubble[1]) + "\n"
        texto += "Tempo: " + str(vet_tempos_bubble[1]) + "\n"

        texto += "Passos merge sort (1000) \n"
        texto += str(vet_passos_merge[1]) + "\n"
        texto += "Tempo: " + str(vet_tempos_merge[1]) + "\n"

        texto += "Passos quick sort (1000) \n"
        texto += str(vet_passos_quick[1]) + "\n"
        texto += "Tempo: " + str(vet_tempos_quick[1]) + "\n"

        texto += "\n"

        texto += "Passos bubble sort (100000) \n"
        texto += str(vet_passos_bubble[2]) + "\n"
        texto += "Tempo: " + str(vet_tempos_bubble[2]) + "\n"

        texto += "Passos merge sort (100000) \n"
        texto += str(vet_passos_merge[2]) + "\n"
        texto += "Tempo: " + str(vet_tempos_merge[2]) + "\n"

        texto += "Passos quick sort (100000) \n"
        texto += str(vet_passos_quick[2]) + "\n"
        texto += "Tempo: " + str(vet_tempos_quick[2]) + "\n"

        texto += "\n"
        
        arquivo_saida.write(texto)
        arquivo_saida.close()