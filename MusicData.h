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
	MusicData(std::string);
	MusicData(ArtistTree*);
	void add_artist(std::string);
	void add_album(std::string, int, std::string);
	void print_artists();
};

#endif MUSICDATA_H