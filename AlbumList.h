#pragma once

#ifndef ALBUMLIST_H
#define ALBUMLIST_H

#include <vector>
#include <string>
#include "ArtistTree.h"

class AlbumList;

class ListNode {
	friend class AlbumList;
	int year;
	std::string title;
	ListNode *prev;
	ListNode *next;
public:
	ListNode(int, std::string);
};

class AlbumList {
	friend class MusicData;
	ListNode *head;
	// capability to return vector of album names for graphics interface
	void strings_inorder(std::vector<std::string>&);			
	std::vector<std::string> get_strings();
public:
	AlbumList();
	AlbumList(ListNode*);
	AlbumList(int, std::string);
	void add_end(ListNode*);
	void add_end(int, std::string);
	void print();
};

#endif