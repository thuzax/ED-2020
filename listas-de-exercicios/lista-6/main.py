import sys

import gerenciador_arquivo
from grafo import Grafo


if __name__ == "__main__":
    if (len(sys.argv) < 4):
        print("Modo de Execução:")
        print("\t\t python3 main.py <arquivo-de-entrada> <arquivo-saida> <modo-de-representacao>")
        print()
        print("Modos de representação: ")
        print("\t MA - Matriz de Adjancência")
        print("\t LA - Lista de Adjancência")
        exit(0)
    
    arquivo_entrada = sys.argv[1]
    arquivo_saida = sys.argv[2]
    tipo_grafo = sys.argv[3]

    num_vertices, arestas = gerenciador_arquivo.ler_grafo(arquivo_entrada)
    grafo = Grafo(num_vertices, arestas, tipo_grafo)
    
    text = ""
    text += str(grafo.get_num_vertices()) + "\n"
    text += str(grafo.get_num_arestas()) + "\n"
    text += str(grafo.get_grau_medio()) + "\n"

    print(text)

    with open(arquivo_saida, "w") as saida:
        saida.write(text)

    