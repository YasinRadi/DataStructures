
const parent = i => Math.floor((i - 1) / 2)
const left = i => 2 * i + 1
const right = i => 2 * i + 2

class MinHeap {
  constructor(maxCap) {
    this.size = 0
    this.capacity = maxCap
    this.A = new Array(maxCap)
  }

  getMin() {
    return this.A[0]
  }

  fixHeapProperty(i) {
    while (i !== 0 && this.A[parent(i)] > this.A[i]) {
      [this.A[i], this.A[parent(i)]] = [this.A[parent(i)], this.A[i]]
      i = parent(i)
    }
  }

  insert(key) {
    if (this.size === this.capacity) {
      console.log(`\nOverflow: could not insert key.`)
      return
    }

    const i = this.size++
    this.A[i] = key

    this.fixHeapProperty(i)
  }

  setKey(i, newVal) {
    this.A[i] = newVal
    this.fixHeapProperty(i)
  }

  extractMin() {
    if (this.size <= 0) {
      return Number.MIN_SAFE_INTEGER
    }

    if (this.size === 1) {
      this.size--
      return this.A[0]
    }

    const root = this.A[0]
    this.A[0] = this.A[--this.size]
    this.minHeapify(0)

    return root
  }

  deleteKey(i) {
    this.setKey(i, Number.MIN_SAFE_INTEGER)
    this.extractMin()
  }

  minHeapify(i) {
    const l = left(i)
    const r = right(i)
    let max = i

    if (l < this.size && this.A[l] < this.A[i]) {
      max = l
    }

    if (r < this.size && this.A[r] < this.A[m]) {
      max = r
    }

    if (max !== i) {
      [this.A[i], this.A[m]] = [this.A[m], this.A[i]]
      this.minHeapify(max)
    }
  }

  display() {
    this.A.forEach(element => console.log(`${element} `))
    console.log()
  }
}