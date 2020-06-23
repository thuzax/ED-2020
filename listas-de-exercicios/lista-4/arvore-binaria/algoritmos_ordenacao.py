def trocar(vetor, i, j):
    auxiliar = vetor[i]
    vetor[i] = vetor[j]
    vetor[j] = auxiliar

def bubble_sort(vetor):
    numer_de_passos = 0
    
    i = 0
    
    while (i < len(vetor)-1):
    
        for j in range(i, len(vetor)):
            numer_de_passos += 1
    
            if (vetor[i] > vetor[j]):
                trocar(vetor, i, j)
        i += 1
    
    return (vetor, numer_de_passos)



def merge(primeira_metade, segunda_metade):
    numero_de_passos = 0
    
    resultado = []

    i = 0
    j = 0


    while (i < len(primeira_metade) and j < len(segunda_metade)):
        numero_de_passos += 1
        
        if (primeira_metade[i] < segunda_metade[j]):
            resultado.append(primeira_metade[i])
            i += 1
        
        else:
            resultado.append(segunda_metade[j])
            j += 1

    while (i < len(primeira_metade)):
        numero_de_passos += 1
        
        resultado.append(primeira_metade[i])
        i += 1
    
    while (j < len(segunda_metade)):
        numero_de_passos += 1
        
        resultado.append(segunda_metade[j])
        j += 1

    return (resultado, numero_de_passos)

def merge_sort(vetor):
    if (len(vetor) == 1):
        return (vetor, 1)
    
    numero_de_passos = 0

    meio = int(len(vetor)/2)
    primeira_metade = vetor[:meio]
    segunda_metade = vetor[meio:]
    
    primeira_metade, num_de_passos_1 = merge_sort(primeira_metade)
    segunda_metade, num_de_passos_2 = merge_sort(segunda_metade)
    
    vetor, num_de_passos_merge = merge(primeira_metade, segunda_metade)
    
    numero_de_passos += num_de_passos_1 + num_de_passos_2 + num_de_passos_merge

    return (vetor, numero_de_passos)


def make_quick_sort(vetor, inicio, fim):
    numero_de_passos = 0

    i = inicio
    j = fim
    meio = int((inicio + fim) / 2)
    pivo = vetor[meio]

    while (i < j):

        while (i < fim and vetor[i] < pivo):
            numero_de_passos += 1
            
            i += 1
        
        while (j > inicio and vetor[j] > pivo):
            numero_de_passos += 1
            
            j -= 1

        if (i <= j):
            numero_de_passos += 1

            trocar(vetor, i, j)
            i += 1
            j -= 1


    num_passos_1 = 0
    num_passos_2 = 0
    if (inicio < j):
        vetor, num_passos_1 = make_quick_sort(vetor, inicio, j)

    if (fim > i):
        vetor, num_passos_2 = make_quick_sort(vetor, i, fim)
    
    numero_de_passos += num_passos_1 + num_passos_2

    return (vetor, numero_de_passos)


def quick_sort(vetor):
    return make_quick_sort(vetor, 0, len(vetor)-1)
