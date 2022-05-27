#include <vector>

template <typename T>
class Node {
    public:
        T item;
        Node* next;
};

template <typename T>
class Stack {
    private:
    Node<T>* head;

    public:
        void push(T item)
        {
            Node<T>* newHead;

            newHead->item = item;
            newHead->next = head;

            head = newHead;
        }

        int pop()
        {
            int toReturn = head->item;

            Node<T>* newHead = head->next;

            head = newHead;

            return toReturn;
        }
};

template <typename T>
class ResizableStack {
    private:
        const int RESIZE_GROWTH = 10;

        T* items;
        int index;
        int capacity;

        void resizeStack()
        {
            T* newItems = new T[capacity + RESIZE_GROWTH];

            for(int i = 0; i <= capacity; i++)
            {
                newItems[i] = items[i];
            }

            delete items;

            items = newItems;
        }

    public:
        ResizableStack(int capacity)
        {
            this->items = new T[capacity];
            this->index = 0;
            this->capacity = capacity;
        }

        ~ResizableStack()
        {
            delete this->items;
        }

        void push(T item)
        {
            this->items[this->index++] = item;
            
            if(this->index >= this->index)
            {
                resizeStack();
            }
        }

        int pop()
        {
            return this->items[this->index--];
        }
};