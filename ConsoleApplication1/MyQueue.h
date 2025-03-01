#pragma once
#include "Node.h"
template <class T>
class MyQueue
{
private:
    // 시작 노드 포인터
    Node<T>* m_pStart;
    // 끝 노드 포인터
    Node<T>* m_pEnd;
    // 큐의 전체 크기
    int m_nSize;

public:
    // 생성자
    MyQueue() : m_pStart(nullptr), m_pEnd(nullptr), m_nSize(0) {}
    // 소멸자
    ~MyQueue() { Clear(); }

    int GetSize() const { return m_nSize; }

    T GetFront() const { return m_pStart ? m_pStart->GetData() : NULL; }
    T GetEnd() const { return m_pEnd ? m_pEnd->GetData() : NULL; }

    // 데이터를 Queue에 쌓는 함수
    void EnQueue(T data)
    {
        Node<T>* pData = new Node<T>(data);

        // 시작이 null인 경우는 처음 생성한 케이스
        // (시작이 null인 경우는 끝도 null)
        if (m_pStart == nullptr)
        {
            m_pStart = pData;
            m_pEnd = pData;
        }
        // 데이터가 있는 경우
        else
        {
            // 끝 다음에 현재 생성한 데이터의 포인터를 위치한 후
            // 새로운 데이터를 끝 포인터로 지정
            m_pEnd->SetNext(pData);
            m_pEnd = m_pEnd->GetNext();
        }

        m_nSize++;
    }

    // Queue에 있는 데이터를 빼는 함수
    T DeQueue()
    {
        if (m_pStart != nullptr)
        {
            // 시작 위치의 데이터 포인터를 임시로 기록
            Node<T>* pData = m_pStart;
            // 시작 위치의 데이터를 저장
            T data = m_pStart->GetData();

            // 시작 데이터의 다음 데이터가 있다면
            if (m_pStart->GetNext() != nullptr)
            {
                // 시작 데이터 포인터를 다음 데이터 포인트로 이동
                m_pStart = m_pStart->GetNext();
                // 이전의 시작 데이터 포인터를 삭제
                delete pData;
                pData = nullptr;
            }
            // 시작 데이터가 마지막 데이터라면
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

    // 전체 데이터 클리어
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