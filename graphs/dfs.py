graph = {
    'a' : ['b', 'c', 'e'],
    'c' : ['a', 'e'],
    'e' : ['a', 'c', 'd'],
    'b' : ['a', 'd', 'f'],
    'd' : ['b', 'e', 'f'],
    'f' : ['b', 'd']
}

def dfs_visit(s, graph):
    parent = {s : None}
    def dfs_visit_recurr(s, graph):
        for v in graph[s]:
            if v not in parent:
                parent[v] = s
                dfs_visit_recurr(v, graph)
        return parent

    return dfs_visit_recurr(s, graph)


def dfs(vertex_list, graph):
    parent = {}
    paths = []
    for v in vertex_list:
        if v not in parent:
            parent[v] = None
            paths.append(dfs_visit(v, graph))
    return paths


print(dfs(['a', 'c'], graph))