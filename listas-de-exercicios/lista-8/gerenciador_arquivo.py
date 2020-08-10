def ler_grafo(nome_arquvio):
    with open(nome_arquvio, "r") as arquivo:
        texto = arquivo.read().splitlines()

    num_vertices = int(texto[0])
    dados = texto[1].split()
    origem = int(dados[0])
    destino = int(dados[1])
    num_arestas = int(dados[2])
    arestas = []

    inicio_arestas = 2
    for i in range(inicio_arestas, num_arestas + inicio_arestas):
        aresta_txt = texto[i].split()
        aresta = (int(aresta_txt[0]), int(aresta_txt[1]), int(aresta_txt[2]))
        arestas.append(aresta)

    return (num_vertices, arestas, origem, destino)
