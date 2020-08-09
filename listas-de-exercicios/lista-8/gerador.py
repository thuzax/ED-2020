import sys
import random

def gerar_arestas_aleatorias(num_vertices, num_arestas):
    aleatorios = set()

    dict_arestas = {}
    while(num_arestas > 0):
        res = random.sample(range(num_vertices), 2)
        key = (res[0], res[1])
        peso = random.randint(1, 100)
        if (key not in dict_arestas):
            dict_arestas[key] = peso
            aresta = (res[0], res[1], peso)
            aleatorios.add(aresta)
            num_arestas -= 1
    
    return aleatorios


if __name__ == "__main__":
    if (len(sys.argv) < 4):
        print("Arquivo saida, numero de vertices, numero de arestas necessarios")
        exit(0)
    
    nome_arquivo = sys.argv[1]
    num_vertices = int(sys.argv[2])
    num_arestas = int(sys.argv[3])

    arestas = gerar_arestas_aleatorias(num_vertices, num_arestas)

    s = str(random.randint(0, num_vertices))
    t = str(random.randint(0, num_vertices))
    while (s == t):
        t = str(random.randint(0, num_vertices))

    texto = ""
    texto += str(num_vertices)
    texto += '\n'
    texto += str(s)
    texto += " "
    texto += str(t)
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