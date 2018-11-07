#include "MusicData.h"

MusicData::MusicData() {};

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

void MusicData::add_album(std::string artist, int year, std::string album)
{

}

void MusicData::print_artists()
{
	artists->print_inorder();
}