
class HashNode {
  constructor(k, v) {
    this.key = k
    this.value = v
  }
}

class HashTable {
  static TABLE_SIZE = 128

  constructor() {
    this.m = new Array(TABLE_SIZE)
    this.size = 0
  }

  _hashFunction(k) {
    return k % TABLE_SIZE
  }

  getHashFromTable(k) {
    let hash_ = this._hashFunction(k)

    while (this.m[hash_]) {
      if (this.m[hash_].key !== k) {
        hash_ = this._hashFunction(hash_ + 1)
        continue
      }
      
      return hash_
    }

    return null
  }

  insert(k, v) {
    this.size++
    this.m[this.getHashFromTable(k)] = new HashNode(k, v)
  }

  get(k) {
    const hash_ = this.getHashFromTable(k)
    return this.m[hash_] ? this.m[hash_].value : -1
  }
 
  contains(k) {
    return this.get(k) !== -1
  }

  display() {
    this.m
      .filter(node => !!node)
      .forEach(node => console.log(`{K: ${node.key}, V: ${node.value}}`))
  }

  remove(k) {
    const hash_ = this.getHashFromTable(k)

    if (!this.m[hash_]) {
      return
    }

    this.size--
    this.m[hash_] = null
  }
}
