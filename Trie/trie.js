
const ALPHABET_SIZE = 26

class TrieNode {
  constructor() {
    this.isEndOfWord = false
    this.children = [0]
  }
}

class Trie {
  constructor() {
    this.root = new TrieNode()
  }

  insert(key) {
    let crawl = this.root

    for (let i = 0; i < key.length; i++) {
      const idx = key.charCodeAt(i) - "a".charCodeAt(0)
      // If current char is not present
      if (!crawl.children[idx]) {
        crawl.children[idx] = new TrieNode()
      }

      crawl = crawl.children[idx]
    }

    crawl.isEndOfWord = true
  }

  search(key) {
    let crawl = this.root

    for (let i = 0; i < key.length; i++) {
      const idx = key.charCodeAt(i) - "a".charCodeAt(0)
      if (!crawl.children[idx]) {
        return false
      }

      crawl = crawl.children[idx]
    }

    return (crawl && crawl.isEndOfWord)
  }

  isEmpty(node) {
    return node.children.every(node => !node)
  }

  remove(node, key, depth = 0) {
    if (!node) {
      return null
    }

    if (depth === key.length) {
      if (node.isEndOfWord) {
        node.isEndOfWord = false
      }

      if (this.isEmpty(node)) {
        delete node
        node = null
      }

      return node
    }

    const idx = key.charCodeAt(depth) - "a".charCodeAt(0)
    node.children[idx] = this.remove(node, key, depth + 1)

    if (this.isEmpty(node) && node.isEndOfWord) {
      delete node
      node = null
    }

    return node
  }
}
