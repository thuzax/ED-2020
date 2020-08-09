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
    

    grafo = Grafo(num_vertices, nomes_vertices, arestas)

    origem = 1
    caminhos_custos, contador = grafo.get_caminhos_bellman_ford(origem)

    text = ""

    if (caminhos_custos is None):
        text = "Tem ciclo negativo"
    else:
        for i in range(len(caminhos_custos)):
            text += "Menor caminho para "
            text += str(caminhos_custos[i][0]) + ": "
            for v in caminhos_custos[i][1]:
                text += str(v) + " "
            text += ": "
            text += "custo = "
            text += str(caminhos_custos[i][2])
            text += "\n"

    print(text)
    print("numero de relaxacoes: ", contador)

    with open(arquivo_saida, "w") as saida:
        saida.write(text)

    