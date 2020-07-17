import sys
import random

def gerar_aleatorio(num_vertices, num_arestas):
    aleatorios = set()

    while(num_arestas > 0):
        res = random.sample(range(num_vertices), 2)
        res = (res[0], res[1])
        if (res not in aleatorios):
            aleatorios.add(res)
            num_arestas -= 1
    
    return aleatorios


if __name__ == "__main__":
    if (len(sys.argv) < 4):
        print("Arquivo saida, numero de vertices e numero de arestas necessarios")
        exit(0)
    
    nome_arquivo = sys.argv[1]
    num_vertices = int(sys.argv[2])
    num_arestas = int(sys.argv[3])

    arestas = gerar_aleatorio(num_vertices, num_arestas)

    texto = ""
    texto += str(num_vertices) + "\n"
    for v1, v2 in arestas:
        texto += str(v1) + " " + str(v2) + "\n"


    with open(nome_arquivo, "w") as saida:
        saida.write(texto)
        