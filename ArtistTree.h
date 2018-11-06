// The ArtistTree class is a binary search tree that stores artist names
//  based on alphabetical comparison.  TreeNodes hold a string containing
//  an artist name as well as a pointer to a doubly linked list that contains
//  that artist's albums.

#pragma once

#ifndef ARTISTTREE_H
#define ARTISTTREE_H

#include <iostream>
#include <string>

class ArtistTree;

class TreeNode {
	friend class ArtistTree;
	std::string artist;
	TreeNode *left;
	TreeNode *right;
	TreeNode *par;
	//ListNode *album;	// doubly linked list of an artist's albums
public:
	TreeNode(std::string);
};

class ArtistTree {
	TreeNode *root;
public:
	ArtistTree();
	ArtistTree(TreeNode*);
	void insert(TreeNode*);			// insert new artist into the tree
	void print_inorder(TreeNode*);	// if printing the subtree with argument as its base
	void print_inorder();			// if printing the whole tree
};

#endif // !ARTISTTREE_H