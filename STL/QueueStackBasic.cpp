#include <bits/stdc++.h> 

void QueueStackBasicTest()
{
    std::queue<int> q; 
    q.push(20); 
    q.push(10);
    q.push(30);

    std::cout<<"Last element in Queue: "<<q.back()<<"\n";
    std::cout<<"Queue elements: ";
    while(!q.empty())
    {
        std::cout<<q.front()<<" ";
        q.pop();
    }
    std::cout<<"\n";

    std::deque<int> dq; // double-ended queue
    dq.push_back(20);
    dq.push_front(10);

    // Order elements, larger first
    std::priority_queue<int> pq;
    // Priority_queue<int, cmp> pq; // pass cmp to sort them
    pq.push(20);
    pq.push(10);
    pq.push(30);

    std::cout<<"Priorty Queue elements: ";
    while(!pq.empty())
    {
        std::cout<<pq.top()<<" ";
        pq.pop(); 
    }
    std::cout<<"\n";

    std::stack<int> s; 
    s.push(20); 
    s.push(10);
    s.push(30);

    std::cout<<"Stack elements: ";
    while(!s.empty())
    {
        std::cout<<s.top()<<" ";
        s.pop();
    }
    std::cout<<"\n";
}

int main()
{
    QueueStackBasicTest();
}