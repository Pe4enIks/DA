#include <algorithm>
#include <new>
#include <iostream>
#include "TData.hpp"
#include "TAvl.hpp"

//Повороты
TAvlNode* TAvl::RotateLeft(TAvlNode* node)
{
	TAvlNode* new_node = node->r_;
	node->r_ = new_node->l_;
	new_node->l_ = node;
	ReHeight(node);
	ReHeight(new_node);
	return new_node;
}

TAvlNode* TAvl::RotateRight(TAvlNode* node)
{
	TAvlNode* new_node = node->l_;
	node->l_= new_node->r_;
	new_node->r_ = node;
	ReHeight(node);
	ReHeight(new_node);
	return new_node;
}

TAvlNode* TAvl::RotateRightLeft(TAvlNode* node)
{
	node->r_ = RotateRight(node->r_);
	return RotateLeft(node);
}

TAvlNode* TAvl::RotateLeftRight(TAvlNode* node)
{
	node->l_ = RotateLeft(node->l_);
	return RotateRight(node);
}

//Перебалансировка
TAvlNode* TAvl::ReBalance(TAvlNode* node)
{
	if (node == nullptr) { return nullptr; }
	ReHeight(node);
	uint64_t balance = Balance(node);
	if (balance == -2)
	{
		if (Balance(node->r_) == 1) { return RotateRightLeft(node); }
		return RotateLeft(node);
	}
	else if (balance == 2)
	{
		if (Balance(node->l_) == -1) { return RotateLeftRight(node); }
		return RotateRight(node);
	}
	return node;
}

//Вставка с печатью на экран
TAvlNode* TAvl::InsertPrint(TAvlNode* node, TData k, uint64_t v)
{
	if (node == nullptr)
	{
		try { node = new TAvlNode(k, v); }
		catch (std::exception& e)
		{
			std::cout << "ERROR: " << e.what() << "\n";
			return nullptr;
		}
		std::cout << "OK\n";
		return node;
	}
	if (k < node->key_) { node->l_ = InsertPrint(node->l_, k, v); }
	else if (k > node->key_) { node->r_ = InsertPrint(node->r_, k, v); }
	else { std::cout << "Exist\n"; }
	return ReBalance(node);
}

//Удаление минимального
TAvlNode* TAvl::RemoveMin(TAvlNode* node, TAvlNode* tmp)
{
	if (tmp->l_ != nullptr) { tmp->l_ = RemoveMin(node, tmp->l_); }
	else
	{
		TAvlNode* r = tmp->r_;
		node->key_ = std::move(tmp->key_);
		node->val_ = tmp->val_;
		delete tmp;
		tmp = r;
	}
	return ReBalance(tmp);
}

//Удаление с печатью
TAvlNode* TAvl::RemovePrint(TAvlNode* node, TData k)
{
	if (node == nullptr)
	{
		std::cout << "NoSuchWord\n";
		return nullptr;
	}
	if (k < node->key_) {node->l_ = RemovePrint(node->l_, k); }
	else if (k > node->key_) { node->r_ = RemovePrint(node->r_, k);	}
	else
	{
		TAvlNode* l = node->l_;
		TAvlNode* r = node->r_;
		if (l == nullptr && r == nullptr)
		{
			delete node;
			std::cout << "OK\n";
			return nullptr;
		}
		if (r == nullptr)
		{
			delete node;
			std::cout << "OK\n";
			return l;
		}
		if (l == nullptr)
		{
			delete node;
			std::cout << "OK\n";
			return r;
		}
		node->r_ = RemoveMin(node, r);
		std::cout << "OK\n";
	}
	return ReBalance(node);
}

//Поиск
TAvlNode* TAvl::Find(TAvlNode* node, TData k)
{
	if (node == nullptr) { return nullptr; }
	for (TAvlNode* iter = node; iter != nullptr; )
	{
		if (k < iter->key_) { iter = iter->l_; }
		else if (k > iter->key_) { iter = iter->r_;	}
		else { return iter;	}
	}
	return nullptr;
}

void TAvl::TreeDelete(TAvlNode* node)
{
	if (node != nullptr)
	{
		TreeDelete(node->l_);
		TreeDelete(node->r_);
		delete node;
	}
}
