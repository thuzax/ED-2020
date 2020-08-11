import sys

import gerenciador_arquivo

from grafo import Grafo

if __name__=="__main__":
    if (len(sys.argv) < 2):
        print("Nome do arquivo de entrada")
        exit(0)
    
    nome_arquivo = sys.argv[1]
    
    dados_arquivo = gerenciador_arquivo.ler_grafo(nome_arquivo)
    num_vertices, arestas, origem, destino = dados_arquivo
    
    grafo = Grafo(num_vertices, arestas)

    texto = ""

    texto += "origem:"
    texto += str(origem)
    texto += "\n"
    texto += "destino:"
    texto += str(destino)
    texto += "\n"
    texto += "-------------------------------\n"
    texto += "Fluxo Total: "
    texto += str(grafo.ford_fulkerson(origem, destino))
    texto += "\n"
    texto += "Número Comparações: "
    texto += str(grafo.num_comparacoes)
    texto += "\n"
    

    # Para imprimir o fluxo em cada aresta, descomente as linhas abaixo 
    # texto += "Fluxo em cada aresta: \n"
    # texto += str(grafo.get_string_arestas())
    # texto += "\n"

    print(texto)
