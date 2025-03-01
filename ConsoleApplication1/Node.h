#pragma once
template <class T>
class Node
{
private:
    // 데이터
    T m_data;
    // 다음 노드를 가리키는 포인터
    Node<T>* m_ptrNext;

public:
    // 생성자
    Node() : m_ptrNext(nullptr)
    {
        printf("Create\n");
    }
    Node(T data, Node<T>* ptrNext = nullptr) : m_data(data), m_ptrNext(ptrNext)
    {
        printf("Create\n");
    }
    // 소멸자
    ~Node()
    {
        printf("Delete\n");
    }

    // 데이터를 반환하는 함수
    T GetData()
    {
        return m_data;
    }
    // 데이터를 설정하는 함수
    void SetData(T data)
    {
        m_data = data;
    }
    // 다음 노드를 가리키는 포인터를 설정하는 함수
    void SetNext(Node<T>* ptr)
    {
        m_ptrNext = ptr;
    }
    // 다음 노드를 가리키는 포인터를 반환하는 함수
    Node<T>* GetNext()
    {
        return m_ptrNext;
    }
};