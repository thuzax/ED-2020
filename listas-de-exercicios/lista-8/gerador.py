import sys
import random

def gerar_arestas_aleatorias(num_vertices, num_arestas, cap_minima, cap_maxima):
    aleatorios = set()

    dict_arestas = {}
    while(num_arestas > 0):
        res = random.sample(range(0, num_vertices), 2)
        peso = random.randint(cap_minima, cap_maxima)
        key = (res[0], res[1], peso)
        invert_key = (res[1], res[0], peso)
        if (key not in dict_arestas and invert_key not in dict_arestas):
            dict_arestas[key] = peso
            aresta = (res[0], res[1], peso)
            aleatorios.add(aresta)
            num_arestas -= 1
    
    return aleatorios


if __name__ == "__main__":
    if (len(sys.argv) < 6):
        print("Arquivo saida, numero de vertices, numero de arestas necessarios, capacidade minima, capacidade maxima")
        exit(0)
    
    nome_arquivo = sys.argv[1]
    num_vertices = int(sys.argv[2])
    num_arestas = int(sys.argv[3])
    capacidade_minima = int(sys.argv[4])
    capacidade_maxima = int(sys.argv[5])

    arestas = gerar_arestas_aleatorias(
                num_vertices, num_arestas, 
                capacidade_minima, capacidade_maxima
            )

    s = str(random.randint(0, num_vertices-1))
    t = str(random.randint(0, num_vertices-1))
    while (s == t):
        t = str(random.randint(0, num_vertices-1))

    texto = ""
    texto += str(num_vertices)
    texto += '\n'
    texto += str(s)
    texto += " "
    texto += str(t)
    texto += " "
    texto += str(len(arestas))
    texto += "\n"

    for v1, v2, peso in arestas:
        texto += str(v1) 
        texto += " " 
        texto += str(v2) 
        texto += " " 
        texto += str(peso) 
        texto += "\n"

    texto += "0"

    with open(nome_arquivo, "w") as saida:
        saida.write(texto)