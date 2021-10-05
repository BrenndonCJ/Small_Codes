def likes(names):
    #recebe o tamanho da lista
    n = len(names)
    #retorna de um dicionario a chave equivalente ao tamanho da lista
    return {
        0: 'no one likes this',
        1: '{} likes this', 
        2: '{} and {} like this', 
        3: '{}, {} and {} like this', 
        4: '{}, {} and {others} others like this'
    #formata a string de acondo com a chave retornada
    }[min(4, n)].format(*names[:3], others=n-2)


name0 = []
name1 = ["Alex"]
name2 = ["Alex", "Jacob"]
name3 = ["Alex", "Jacob", "Mark"]
namen = ["Alex", "Jacob", "Mark", "Max", "James", "Jacob", "Mark", "Max", "James"]

print(likes(namen))