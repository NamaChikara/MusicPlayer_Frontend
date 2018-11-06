#include <iostream>
#include <string>
#include "ArtistTree.h"

int main()
{
	ArtistTree mytree;
	TreeNode* KM = new TreeNode("Kevin Morby");
	mytree.insert(new TreeNode("Chrome Sparks"));
	mytree.insert(new TreeNode("Kevin Morby"));
	mytree.insert(new TreeNode("Bob Moses"));
	mytree.insert(new TreeNode("Rufus Du Sol"));
	mytree.print_inorder();
	std::cin.get();
}