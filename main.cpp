#include <iostream>
#include <string>
#include "ArtistTree.h"
#include "AlbumList.h"

int main()
{
	ArtistTree mytree;
	mytree.print_inorder();
	TreeNode* KM = new TreeNode("Kevin Morby");
	mytree.insert(new TreeNode("Chrome Sparks"));
	mytree.insert(new TreeNode("Kevin Morby"));
	mytree.insert(new TreeNode("Bob Moses"));
	mytree.insert(new TreeNode("Rufus Du Sol"));
	mytree.print_inorder();

	std::cout << std::endl;

	AlbumList mylist;
	mylist.print();
	ListNode *CM = new ListNode(2017, "City Music");
	mylist.add_end(CM);
	mylist.add_end(new ListNode(2018, "Solace"));
	mylist.add_end(new ListNode(2018, "Room Inside the World"));
	mylist.print();

	std::cin.get();
}