import sys

import gerenciador_arquivo
from grafo import Grafo


if __name__ == "__main__":
    if (len(sys.argv) < 3):
        print("Modo de Execução:")
        print("\t\t python3 main.py <arquivo-de-entrada> <arquivo-saida>")
        print()
        exit(0)
    
    arquivo_entrada = sys.argv[1]
    arquivo_saida = sys.argv[2]

    dados_grafo = gerenciador_arquivo.ler_grafo(arquivo_entrada)
    num_vertices, nomes_vertices, arestas = dados_grafo
    
    print(num_vertices)
    print(nomes_vertices)
    print(arestas)
    
    grafo = Grafo(num_vertices, nomes_vertices, arestas)

    print(grafo.get_string())

    origem = 1
    grafo.bellman_ford(origem)


    exit(0)


    tamanho_grafo = grafo.get_espaco_alocado()

    text = ""
    text += "Número de vértices: "
    text += str(grafo.get_num_vertices()) + "\n"
    text += "Número de arestas: "
    text += str(grafo.get_num_arestas()) + "\n"
    text += "Grau médio: "
    text += str(grafo.get_grau_medio()) + "\n"
    text += "Espaço ocupado: "
    text += str(tamanho_grafo) 
    text += "B" + "\n"
    print(text)

    with open(arquivo_saida, "w") as saida:
        saida.write(text)

    