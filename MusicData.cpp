#include "MusicData.h"

MusicData::MusicData()
	: artists{ new ArtistTree } {};

MusicData::MusicData(std::string artist)
{
	if (artists)
	{
		add_artist(artist);
	}
	else
	{
		TreeNode *temp = new TreeNode(artist);
		artists = new ArtistTree(temp);
	}
}

MusicData::MusicData(ArtistTree* artistry)
	: artists{ artistry } {}

void MusicData::add_artist(std::string artist)
{
	if (artists)
	{
		artists->insert(artist);
	}
	else
	{
		MusicData(artist);
	}
}

TreeNode *MusicData::get_artist(std::string artist)
{
	if (artists)
	{
		TreeNode *temp = artists->find(artist);
		return temp;
	}
	else
	{
		return nullptr;
	}
}

void MusicData::add_album(std::string artist, int year, std::string album)
{
	TreeNode *temp = get_artist(artist);
	// check that the artist was found
	if (temp)
	{
		// if there is already a pointer to an album list, add to that list
		if (temp->album)
		{
			temp->album->add_end(year, album);
		}
		// otherwise, create a new list with (year, album) as the head
		else
		{
			temp->album = new AlbumList(year, album);
		}
	}
}

void MusicData::print_artists()
{
	artists->print_inorder();
}

void MusicData::print_albums(std::string artist)
{
	TreeNode* temp = get_artist(artist);
	if (temp)
	{
		if (temp->album)
		{
			std::cout << "Albums by " << artist << ":" << std::endl;
			temp->album->print();
		}
		else
		{
			std::cout << "Arist " << artist << " has no albums stored." << std::endl;
		}
	}
}

std::vector<std::string> MusicData::get_artist_strings()
{
	return artists->get_strings();
}

std::vector<std::string> MusicData::get_album_strings(std::string artist)
{
	std::vector<std::string> albums;
	TreeNode *temp = get_artist(artist);
	if (temp)
	{
		albums = temp->album->get_strings();
	}
	return albums;
}