// Created by Malena Lodi on 3/25/24.

#include "sortLinkedLists.h"

NodePtr sortBookList(NodePtr& head) //sortBookList: takes the head of a 'Book' class linked list and sorts it in order of a book's code
{
    NodePtr returnHead, returnIterator, search, prevNode, maxNode;
    maxNode = head;

    for (search = head; search->link != nullptr; search = search->link)
    {
        if (search->link->data->getCode() < maxNode->data->getCode())
        {
            maxNode = search->link;
            prevNode = search;
        }
    }
    if (maxNode == head) { head = head->link;}
    else {prevNode->link = maxNode->link;}

    maxNode->link = nullptr;
    returnHead = maxNode;
    returnIterator = returnHead;
    while (head != nullptr)
    {
        maxNode = head;
        for (search = head; search->link != nullptr; search = search->link)
        {
            if (search->link->data->getCode() < maxNode->data->getCode())
            {
                maxNode = search->link;
                prevNode = search;
            }
        }
        if (maxNode == head) {head = head->link;}
        else {prevNode->link = maxNode->link;}

        maxNode->link = nullptr;
        returnIterator->link = maxNode;
        returnIterator = returnIterator->link;
    }
    return returnHead;
}
NodePtr2 sortPersonList(NodePtr2& head) //sortPersonList: takes the head of a 'Person' class linked list and sorts it in order of id value
{
    NodePtr2 returnHead, returnIterator, search, prevNode, maxNode;
    maxNode = head;

    for (search = head; search->link2 != nullptr; search = search->link2)
    {
        if (search->link2->data2->getId() < maxNode->data2->getId())
        {
            maxNode = search->link2;
            prevNode = search;
        }
    }
    if (maxNode == head) {head = head->link2;}
    else {prevNode->link2 = maxNode->link2;}

    maxNode->link2 = nullptr;
    returnHead = maxNode;
    returnIterator = returnHead;

    while (head != nullptr)
    {
        maxNode = head;
        for (search = head; search->link2 != nullptr; search = search->link2)
        {
            if (search->link2->data2->getId() < maxNode->data2->getId())
            {
                maxNode = search->link2;
                prevNode = search;
            }
        }
        if (maxNode == head) {head = head->link2;}
        else {prevNode->link2 = maxNode->link2;}

        maxNode->link2 = nullptr;
        returnIterator->link2 = maxNode;
        returnIterator = returnIterator->link2;
    }
    return returnHead;
}


