
class GraphBFS {
  constructor(numVertex) {
    this.numVertex = numVertex
    this.adj = Array.from({ length: numVertex }, () => [])
  }

  addEdge(nodeIndex, nodeValue) {
    this.adj[nodeIndex].push(nodeValue)
  }

  BFS(intialNode) {
    const visited = Array.from({ length: this.numVertex}, () => false)
    const queue = []

    visited[intialNode] = true
    queue.push(intialNode)

    while (queue.length > 0) {
      const node = queue.shift()
      console.log(`${node}` )

      this.adj[node].forEach(element => {
        if (!visited[element]) {
          visited[element] = true
          queue.push(element)
        }
      })
    }

    console.log()
  }
}