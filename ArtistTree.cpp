#include "ArtistTree.h"

TreeNode::TreeNode(std::string name)
	: artist{ name } {};

ArtistTree::ArtistTree() {};

ArtistTree::ArtistTree(TreeNode* first)
	: root{ first } {};

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