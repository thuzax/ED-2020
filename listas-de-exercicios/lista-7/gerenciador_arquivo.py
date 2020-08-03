
def ler_grafo(nome_arquvio):
    with open(nome_arquvio, "r") as arquivo:
        texto = arquivo.read().splitlines()

    num_vertices = int(texto[0])
    nomes_vertices = []

    arestas = []

    for i in range(0, num_vertices):
        lista_dados = texto[i+1].split()
        nomes_vertices.append(int(lista_dados[0]))

        for j in range(1, len(lista_dados)-1, 2):
            
            aresta =  (int(nomes_vertices[i]),
                       int(lista_dados[j]), 
                       int(lista_dados[j+1]))
            
            arestas.append(aresta)

    return (num_vertices, nomes_vertices, arestas)
