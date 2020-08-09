import sys


import gerenciador_arquivo

if __name__=="__main__":
    if (len(sys.argv) < 2):
        print("Nome do arquivo de entrada")
        exit(0)
    
    nome_arquivo = sys.argv[1]
    
    a = gerenciador_arquivo.ler_grafo(nome_arquivo)