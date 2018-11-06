#include <iostream>
#include <string>
#include "ArtistTree.h"
#include "AlbumList.h"

int main()
{
	std::cout << "Test default tree constructor." << std::endl;
	ArtistTree mytree;
	mytree.print_inorder();
	TreeNode* KM = new TreeNode("Kevin Morby");
	mytree.insert(new TreeNode("Chrome Sparks"));
	mytree.insert(new TreeNode("Kevin Morby"));
	mytree.insert(new TreeNode("Bob Moses"));
	mytree.insert(new TreeNode("Rufus Du Sol"));
	mytree.print_inorder();

	std::cout << std::endl;

	std::cout << "Test tree construction via TreeNode." << std::endl;
	TreeNode *CS = new TreeNode("What So Not");
	ArtistTree mytree1{ CS };
	mytree1.insert(new TreeNode("Baauer"));
	mytree1.print_inorder();

	std::cout << std::endl;

	std::cout << "Test tree construction via string and insert via string." << std::endl;
	ArtistTree mytree2{ "John Craigie" };
	mytree2.insert("The Shook Twins");
	mytree2.print_inorder();

	std::cout << std::endl;

	std::cout << "Test AlbumList with defualt constructor." << std::endl;
	AlbumList mylist;
	mylist.print();
	ListNode *CM = new ListNode(2017, "City Music");
	mylist.add_end(CM);
	mylist.add_end(new ListNode(2018, "Solace"));
	mylist.add_end(new ListNode(2018, "Room Inside the World"));
	mylist.print();

	std::cout << std::endl;


	std::cin.get();
}