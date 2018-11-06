// The ArtistTree class is a binary search tree that stores artist names
//  based on alphabetical comparison.  TreeNodes hold a string containing
//  an artist name as well as a pointer to a doubly linked list that contains
//  that artist's albums.

#pragma once

#ifndef ARTISTTREE_H
#define ARTISTTREE_H

#include <iostream>
#include <string>
#include "AlbumList.h"
#include "MusicData.h"

class ArtistTree;

class TreeNode {
	friend class ArtistTree;
	std::string artist;
	TreeNode *left;
	TreeNode *right;
	TreeNode *par;
	//AlbumList *album;	// doubly linked list of an artist's albums; the pointer
						//  stored in the TreeNode is the head of the list
public:
	TreeNode(std::string);
};

class ArtistTree {
	friend class MusicData;
	TreeNode *root;
public:
	ArtistTree();
	ArtistTree(TreeNode*);
	ArtistTree(std::string);
	void insert(TreeNode*);			// insert new artist into the tree via TreeNode
	void insert(std::string);		// insert new artist via string
	TreeNode* find(std::string);	// find the TreeNode for a specified artist (if any)
	void print_inorder(TreeNode*);	// if printing the subtree with argument as its base
	void print_inorder();			// if printing the whole tree
};

#endif // !ARTISTTREE_H