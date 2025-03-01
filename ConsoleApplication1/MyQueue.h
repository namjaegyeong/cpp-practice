#pragma once
#include "Node.h"
template <class T>
class MyQueue
{
private:
    // ���� ��� ������
    Node<T>* m_pStart;
    // �� ��� ������
    Node<T>* m_pEnd;
    // ť�� ��ü ũ��
    int m_nSize;

public:
    // ������
    MyQueue() : m_pStart(nullptr), m_pEnd(nullptr), m_nSize(0) {}
    // �Ҹ���
    ~MyQueue() { Clear(); }

    int GetSize() const { return m_nSize; }

    T GetFront() const { return m_pStart ? m_pStart->GetData() : NULL; }
    T GetEnd() const { return m_pEnd ? m_pEnd->GetData() : NULL; }

    // �����͸� Queue�� �״� �Լ�
    void EnQueue(T data)
    {
        Node<T>* pData = new Node<T>(data);

        // ������ null�� ���� ó�� ������ ���̽�
        // (������ null�� ���� ���� null)
        if (m_pStart == nullptr)
        {
            m_pStart = pData;
            m_pEnd = pData;
        }
        // �����Ͱ� �ִ� ���
        else
        {
            // �� ������ ���� ������ �������� �����͸� ��ġ�� ��
            // ���ο� �����͸� �� �����ͷ� ����
            m_pEnd->SetNext(pData);
            m_pEnd = m_pEnd->GetNext();
        }

        m_nSize++;
    }

    // Queue�� �ִ� �����͸� ���� �Լ�
    T DeQueue()
    {
        if (m_pStart != nullptr)
        {
            // ���� ��ġ�� ������ �����͸� �ӽ÷� ���
            Node<T>* pData = m_pStart;
            // ���� ��ġ�� �����͸� ����
            T data = m_pStart->GetData();

            // ���� �������� ���� �����Ͱ� �ִٸ�
            if (m_pStart->GetNext() != nullptr)
            {
                // ���� ������ �����͸� ���� ������ ����Ʈ�� �̵�
                m_pStart = m_pStart->GetNext();
                // ������ ���� ������ �����͸� ����
                delete pData;
                pData = nullptr;
            }
            // ���� �����Ͱ� ������ �����Ͷ��
            else
            {
                delete m_pStart;
                m_pStart = nullptr;
                m_pEnd = nullptr;
            }

            m_nSize--;
            return data;
        }
        else
        {
            return NULL;
        }
    }

    // ��ü ������ Ŭ����
    void Clear()
    {
        while (m_pStart != nullptr)
        {
            if (m_pStart->GetNext() != nullptr)
            {
                Node<T>* pData = m_pStart;

                m_pStart = m_pStart->GetNext();
                delete pData;
                pData = nullptr;
            }

            if (m_pStart->GetNext() == nullptr)
            {
                delete m_pStart;
                m_pStart = nullptr;
                m_pEnd = nullptr;
            }
        }

        m_pEnd = nullptr;

        m_nSize = 0;
    }
};