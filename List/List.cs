
namespace list
{
    public class List<T>
    {
        // Number of items in list
        private int len;

        // Capacity of the list
        private int capacity;

        // Array that holds the list items
        private T[] items;

        public List() {
            len = 0;
            capacity = 1;
            items = new T[capacity];
        }

        public void Add(T v) {
            // Increase size and check that new size fits capacity
            if (++len > capacity) capacity *= 2;
            
            // If capacity changed; resize array
            if (capacity > items.Length)
            {
                T[] tmp = new T[capacity];
                for (int i = 0; i < len - 1; i++)
                    tmp[i] = items[i];
                items = tmp;
            }

            // Assign new element
            items[len - 1] = v;
        }   

        public void Display() {
            System.Text.StringBuilder sb = new System.Text.StringBuilder();
            for (int i = 0; i < len; i++)
                sb.Append(items[i]).Append(" ");
            System.Console.WriteLine(sb.ToString());
        }

        public int Size() {
            return len;
        }

        public int Capacity() {
            return capacity;
        }

        public T Get(int idx) {
            return idx <= len ? items[idx] : default(T);
        }

        public int IndexOf(T t) {
            for (int i = 0; i < len; i++)
                if (t.Equals(items[i]))
                    return i;
            
            return -1;
        }
    
        public void Remove(int idx) {
            if (0 <= idx && idx <= len)
            {
                for (int i = 0;  i < len; i++)
                    items[i] = items[i + 1];

                items[--len] = items[capacity - 1];
            }
        }

        public void Remove(T t) {
            int idx = IndexOf(t);
            if (idx != -1) Remove(idx);
        }

        public bool IsEmpty() {
            return len == 0;
        }

        public bool Contains(T t) {
            return IndexOf(t) != -1;
        }

        public T First() {
            return IsEmpty() ? default(T) : items[0];
        }

        public T Last() {
            return IsEmpty() ? default(T) : items[len - 1];
        }

        public void Set(int idx, T t) {
            if (0 <= idx && idx < len)
                items[idx] = t;
        }
    }
}