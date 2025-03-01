#pragma once
template <class T>
class Node
{
private:
    // ������
    T m_data;
    // ���� ��带 ����Ű�� ������
    Node<T>* m_ptrNext;

public:
    // ������
    Node() : m_ptrNext(nullptr)
    {
        printf("Create\n");
    }
    Node(T data, Node<T>* ptrNext = nullptr) : m_data(data), m_ptrNext(ptrNext)
    {
        printf("Create\n");
    }
    // �Ҹ���
    ~Node()
    {
        printf("Delete\n");
    }

    // �����͸� ��ȯ�ϴ� �Լ�
    T GetData()
    {
        return m_data;
    }
    // �����͸� �����ϴ� �Լ�
    void SetData(T data)
    {
        m_data = data;
    }
    // ���� ��带 ����Ű�� �����͸� �����ϴ� �Լ�
    void SetNext(Node<T>* ptr)
    {
        m_ptrNext = ptr;
    }
    // ���� ��带 ����Ű�� �����͸� ��ȯ�ϴ� �Լ�
    Node<T>* GetNext()
    {
        return m_ptrNext;
    }
};