def trocar(vetor, i, j):
    auxiliar = vetor[i]
    vetor[i] = vetor[j]
    vetor[j] = auxiliar

def bubble_sort(vetor):
    i = 0
    while (i < len(vetor)-1):
        for j in range(i, len(vetor)):
            if (vetor[i] > vetor[j]):
                trocar(vetor, i, j)
        i += 1
    
    return vetor



def merge(primeira_metade, segunda_metade):
    resultado = []

    i = 0
    j = 0

    while (i < len(primeira_metade) and j < len(segunda_metade)):
        if (primeira_metade[i] < segunda_metade[j]):
            resultado.append(primeira_metade[i])
            i += 1
        else:
            resultado.append(segunda_metade[j])
            j += 1

    while (i < len(primeira_metade)):
        resultado.append(primeira_metade[i])
        i += 1
    
    while (j < len(segunda_metade)):
        resultado.append(segunda_metade[j])
        j += 1

    return resultado

def merge_sort(vetor):
    if (len(vetor) == 1):
        return vetor
    
    meio = int(len(vetor)/2)
    primeira_metade = vetor[:meio]
    segunda_metade = vetor[meio:]
    
    primeira_metade = merge_sort(primeira_metade)
    segunda_metade = merge_sort(segunda_metade)
    
    vetor = merge(primeira_metade, segunda_metade)
    
    return vetor


def make_quick_sort(vetor, inicio, fim):
    i = inicio
    j = fim
    meio = int((inicio + fim) / 2)
    pivo = vetor[meio]

    while (i < j):

        while (i < fim and vetor[i] < pivo):
            i += 1
        
        while (j > inicio and vetor[j] > pivo):
            j -= 1

        if (i <= j):
            trocar(vetor, i, j)
            i += 1
            j -= 1


    if (inicio < j):
        vetor = make_quick_sort(vetor, inicio, j)

    if (fim > i):
        vetor = make_quick_sort(vetor, i, fim)

    return vetor


def quick_sort(vetor):
    return make_quick_sort(vetor, 0, len(vetor)-1)
