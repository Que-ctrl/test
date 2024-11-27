#include <iostream>
#include <queue>

template<typename T>
class Queue
{
    public:
    std::queue<T> the_queue;


    void pushQueue(T item)
    {
        the_queue.push(item);
        T pushed_value = the_queue.back();
        std::cout << "Pushed value: " << pushed_value << std::endl;
    }
    void popQueue()
    {
        if(!the_queue.empty())
        {
            T popped_value = the_queue.front();
            the_queue.pop();
            std::cout << "Popped value: " << popped_value << std::endl;
        }
        else
        {
            std::cout << "The queue is empty!" << std::endl;
        }
    }
    
    T backQueue()
    {
        if(!the_queue.empty())
        {
            std::cout << "back: " << the_queue.back() << std::endl;
            return the_queue.back();
        }
        else
        {
            std::cout << "The queue is empty!" << std::endl;
            return T();
        }
        
    }

    T frontQueue()
    {
        if(!the_queue.empty())
        {
            std::cout << "front: " << the_queue.front() << std::endl;
            return the_queue.front();
        }
        else
        {
            std::cout << "The queue is empty!" << std::endl;
            return T();
        }
    }

    int sizeQueue()
    {
        std::cout << "The size of the queue is: " << the_queue.size() << std::endl;
        return the_queue.size();
        
    }
    bool emptyQueue()
    {
        if(the_queue.empty())
        {
            std::cout << "The queue is empty!" << std::endl;
        }
        else if(!the_queue.empty())
        {
            std::cout << "The queue is not empty!" << std::endl;
        }
        return the_queue.empty();
    }

    void showQueue()
    {
        std::queue<T> temp_queue = the_queue;
        std::cout << "The contents of the queue: ";
        while(!temp_queue.empty())
        {
            std::cout << temp_queue.front() << ", ";
            temp_queue.pop();
            
        }
        std::cout << std::endl;
    }
};

int main()
{
    Queue<int> que;
    que.pushQueue(10);
    que.popQueue(); // finns inget att ta bort då kön är tom
    que.emptyQueue();
    que.pushQueue(10);
    que.pushQueue(4);
    que.pushQueue(2);
    que.showQueue();
    que.frontQueue();
    que.backQueue();
    que.sizeQueue(); 
    std::cout << std::endl;
    Queue<std::string> que1;
    que1.pushQueue("nummer 1");
    que1.popQueue(); // finns inget att ta bort då kön är tom
    que1.emptyQueue();
    que1.pushQueue("nummer 2");
    que1.pushQueue("nummer 3");
    que1.pushQueue("nummer 4");
    que1.showQueue();
    que1.frontQueue();
    que1.backQueue();
    que1.sizeQueue(); 
    std::cout << std::endl;
    Queue<double> que2;
    que2.pushQueue(2.5);
    que2.popQueue(); // finns inget att ta bort då kön är tom
    que2.emptyQueue();
    que2.pushQueue(3.8);
    que2.pushQueue(1.5);
    que2.pushQueue(4.6);
    que2.showQueue();
    que2.backQueue();
    que2.frontQueue();
    que2.sizeQueue(); 

    



    return 0;
}