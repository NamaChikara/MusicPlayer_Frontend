#include "ArtistTree.h"

TreeNode::TreeNode(std::string name)
	: artist{ name } {};

ArtistTree::ArtistTree() {};

ArtistTree::ArtistTree(TreeNode* first)
	: root{ first } {};

ArtistTree::ArtistTree(std::string artist)
	: root{ new TreeNode(artist) } {}

void ArtistTree::insert(TreeNode* new_artist)
{
	TreeNode *temp = root;
	TreeNode *prev = nullptr;
	while (temp)
	{
		prev = temp;
		// do not allow for duplicate artists
		if (new_artist->artist == temp->artist)
		{
			return;
		}
		else if (new_artist->artist < temp->artist)
		{
			temp = temp->left;
		}
		else
		{
			temp = temp->right;
		}
	}
	new_artist->par = prev;
	if (!prev)
	{
		root = new_artist;
	}
	else if (new_artist->artist < prev->artist)
	{
		prev->left = new_artist;
	}
	else
	{
		prev->right = new_artist;
	}
}

void ArtistTree::insert(std::string artist)
{
	TreeNode *temp = new TreeNode(artist);
	insert(temp);
}

TreeNode* ArtistTree::find(std::string name)
{
	TreeNode* temp = root;
	while (temp)
	{
		if (temp->artist == name)
		{
			return temp;
		}
		else if (name < temp->artist)
		{
			temp = temp->left;
		}
		else
		{
			temp = temp->right;
		}
	}
	if (!temp)
	{
		std::cout << "Artist " << name << " not found." << std::endl;
	}
	return temp;	// temp is nullptr if no match found
}

void ArtistTree::print_inorder(TreeNode* start)
{
	if (start)
	{
		print_inorder(start->left);
		std::cout << start->artist << ", ";
		print_inorder(start->right);
	}
}

void ArtistTree::print_inorder()
{
	print_inorder(root);
}

void ArtistTree::strings_inorder(TreeNode* start)
{
	if (start)
	{
		strings_inorder(start->left);
		artists.push_back(start->artist);
		strings_inorder(start->right);
	}
}

void ArtistTree::strings_inorder()
{
	strings_inorder(root);
}

std::vector<std::string> ArtistTree::get_strings()
{
	artists.clear();
	strings_inorder(root);
	return artists;
}