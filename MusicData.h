// This class provides functions for adding artists to an ArtistTree, as 
//  well as adding AlbumLists to TreeNodes of the ArtistTree.

#pragma once

#ifndef MUSICDATA_H
#define MUSICDATA_H

#include <iostream>
#include <string>
#include "ArtistTree.h"
#include "AlbumList.h"

class MusicData {
	ArtistTree *artists;
public:
	MusicData();
	MusicData(std::string);	// allow constuction from just an artist's name
	MusicData(ArtistTree*);

	// adds the argument string to artists as a new TreeNode*
	void add_artist(std::string);		

	// searches artists for a TreeNode with the argument string;
	//  returns nullptr if not found
	TreeNode *get_artist(std::string);	

	// searches artists for TreeNode *T with artist art; if found, checks if 
	//  T->AlbumList is nullptr; if it is nullptr, make it point to a new AlbumList 
	//  with (yr, alb) at its head -- otherwise, add (yr, alb) to the end of the 
	//  existing AlbumList
	void add_album(std::string art, int yr, std::string alb);	

	// calls artists->print_inorder() if artists is not nullptr
	void print_artists();

	// searches artists for TreeNode *T with artist art; if found, prints the 
	//  contents of T->AlbumList
	void print_albums(std::string art);

	// return a vector with alphabetized artist names from the ArtistTree
	//  (used for printing within the graphics interface)
	std::vector<std::string> get_artist_strings();
};

#endif MUSICDATA_H